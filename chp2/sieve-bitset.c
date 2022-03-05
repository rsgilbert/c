#include <stdio.h>
#include <math.h>

#define MAXLINE 1000
#define A_1 1 // first number in GP 

// sieve of eratosthenes
// Using bit arithmetic
long btoi(char s[]);
void itob(long n, char s[]);
long runningPrimes(long max);
void printBits(long num);
long gpSum(long a_1, long r, long n);
long numElementsInGP(long a_1, long a_n, long r);
long lastElementInBitset(long width);
long width(long factor, long n);
long paddedSum(long sum, long n, long i);
long commonRatio(long i);
long flip(long bitset);
void sieve(long n, long primes[]);
long dropRightBits(long bitset, long noToDrop);
void primeBitsetToArray(long bitset, long primes[]);
void printPrimes(long primes[], size_t size);
long greaterFirstBit(long bitset);

long main()
{
    long n = 31; // 32 is not supported (??) I dont know why
    long runner = runningPrimes(n);
    long primes[n];
    sieve(n, primes);
    printPrimes(primes, n);
}


/**
 * sieve of eratosthenes
 * Algorithm for finding all prime numbers upto a given limit.
 * We go through natural numbers starting with 2 removing out multiples of each.
 */
void sieve(long n, long primes[])
{
    // 1. fill in numbers
    long runner = runningPrimes(n);
    long start_no = 2;
    long i = start_no;
    while(i <= n)
    {
        // printf("%d\n", i);
        long w = width(i, n);
        long lastEl = lastElementInBitset(w);
        long r = commonRatio(i);
        long numEls = numElementsInGP(A_1, lastEl, r);
        long sum = gpSum(A_1, r, numEls);
        //  printf("non padded sum: w %d , r %d , numEls %d ", w, r, numEls);
        // printBits(sum);
        sum = paddedSum(sum, n, i);  
        // We need to flip `sum` bits because currently 1s in sum represent multiples
        // If we flip 1010 it becomes 101. But notice we also want to remove 1000. 
        // If we dont handle this, 4 will show up in the primes
        // So we first get a copy of first bit 
        long grtrBitset = greaterFirstBit(sum);
        sum = flip(sum);
        sum = grtrBitset | sum;

        // 
        // printf("sum: gr %d ", grtrBitset);
        // printBits(grtrBitset);
        // printf("sum ");
        // printBits(sum);
        // Cancel out bits that represent multiples of i
        // We are going to drop some bits. The ones that are multiples of i
        // We first store some values
        long bitsOnRightToDrop = n - (2 * i) + 1;
        long notToChangeBits = dropRightBits(runner, bitsOnRightToDrop);
        long withoutSum = runner & sum;
        // printf("Runner: ");
        runner = notToChangeBits | withoutSum;
        // printBits(runner);
        i++;
    }
    primeBitsetToArray(runner, primes);
}

long runningPrimes(long max)
{
    return pow(2, max) - 1;
}

long paddedSum(long sum, long n, long i) {
    return sum * pow(2, (n % i));
}

/** Find sum of a geometric progression 
 * a_1: first element in GP
 * r: common ratio
 * n: number of elements in GP
*/
long gpSum(long a_1, long r, long n)
{
    return a_1 * (pow(r, n) - 1) / (r - 1);
}

/* Compute common ratio to be used for a given number */
long commonRatio(long i)
{
    return pow(2, i);
}

/** Find number of elements in a GP
 * a_1: first element in GP
 * a_n: last element in GP
 * r : common ratio
 */
long numElementsInGP(long a_1, long a_n, long r)
{
    return log2(a_n / a_1) / log2(r) + 1;
}

/* Find last element in bitset as decimal integer
* For example if bitset is 10010 , last element is 10000 = 16
* width: Number of characters in bitset.
*/
long lastElementInBitset(long width)
{
    return pow(2, (width - 1));
}

/* Produces the number of bits from first multiple greater than factor to last multiple less than n. */
long width(long factor, long n)
{
    long firstMultGR = 2 * factor;
    long lastMultLess = n - (n % factor);
    return lastMultLess - firstMultGR + 1;
}



// -- Bit functions --

/** Convert binary to decimal integer */
long btoi(char s[])
{
    long result = 0;
    long i = 0;
    while (s[i] != 0)
    {
        if (s[i] != '0' && s[i] != '1')
            return -1;
        result *= 2;
        result += s[i] - '0';
        i++;
    }
    return result;
}

/** convert decimal integer to binary */
void itob(long n, char s[])
{
    if (n == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return;
    };
    if (n < 0)
    {
        s[0] = '-';
        s[1] = '1';
        s[2] = 0;
        return;
    }
    long pos = log2(n);
    s[pos + 1] = 0;
    while (pos != 0)
    {
        s[pos] = '0' + n % 2;
        n = n / 2;
        pos--;
    }
    // pos will be 0
    s[pos] = '1';
}

/**
 * Prints binary representation of set
 */
void printBits(long num)
{
    char result[MAXLINE];
    itob(num, result);
    printf("%s\n", result);
}

// Flip bits. For example 10110 becomes 1001
long flip(long bitset)
{
    long mask = pow(2, (long) log2(bitset) + 1) - 1;
    return bitset ^ mask;
}

// Drop some bits from the right side of a bitset. For example dropRighBits(btoi("1001100110"), 6) produces 1001000000
long dropRightBits(long bitset, long noToDrop) {
    long mask = pow(2, noToDrop) - 1; 
    long rightFlippedBitset = bitset ^ mask;
    return bitset & rightFlippedBitset;
}


/* Copy bitset representing prime positions into an array of prime numbers */
void primeBitsetToArray(long bitset, long primes[])
{
    char temp[MAXLINE];
    itob(bitset, temp);
    // printf("bitset %s\n", temp);
    // in the bitset, the first position represents number 1 then 2 ... etc So our primes will start at index 1 
    long i = 1;
    long j = 0;
    while(temp[i] != 0)
    {   
        if(temp[i] == '1')
        {            
            // in the bitset, the first position is 1 then 2 ... etc
            primes[j] = i + 1;
            // printf("%d\n", i + 1);
            j++;
        }
        i++;
    }
    primes[j] = -1;
}

/* Return bitset for the first bit in a given bitset.
* For example bitsetForFirstBit(10) = 8
*/
long bitsetForFirstBit(long bitset) {
    return pow(2, log2(bitset));
}

/* Return bitset that is greater than given bitset but also a multiple of 2.
* For example bitsetForFirstBit(10) = 16
*/
long greaterFirstBit(long bitset) {
    return pow(2, (long) log2(bitset) + 1);
}


void printPrimes(long primes[], size_t size)
{
    long i = 0;
    while(i < size && primes[i] != -1)
    {
        printf("%d, ", primes[i]);
        i++;
    }
    printf("\n");
}