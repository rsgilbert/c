#include <stdio.h>
#include <math.h>

#define MAXLINE 1000
#define A_1 1 // first number in GP 

// sieve of eratosthenes
// Using bit arithmetic
int btoi(char s[]);
void itob(int n, char s[]);
int runningPrimes(int max);
void printBits(int num);
int gpSum(int a_1, int r, int n);
int numElementsInGP(int a_1, int a_n, int r);
int lastElementInBitset(int width);
int width(int factor, int n);
int paddedSum(int sum, int n, int i);
int commonRatio(int i);
int flip(int bitset);
void sieve(int n, int primes[]);
int dropRightBits(int bitset, int noToDrop);
void primeBitsetToArray(int bitset, int primes[]);
void printPrimes(int primes[], size_t size);

int main()
{
    int n = 7;
    int runner = runningPrimes(n);
    int primes[n];
    sieve(n, primes);
    printPrimes(primes, n);
}


/**
 * sieve of eratosthenes
 * Algorithm for finding all prime numbers upto a given limit.
 * We go through natural numbers starting with 2 removing out multiples of each.
 */
void sieve(int n, int primes[])
{
    // 1. fill in numbers
    int runner = runningPrimes(n);
    int start_no = 2;
    int i = start_no;
    while(i <= n)
    {
        if(i > 5) break;
        printf("%d\n", i);
        int w = width(i, n);
        int lastEl = lastElementInBitset(w);
        int r = commonRatio(i);
        int numEls = numElementsInGP(A_1, lastEl, r);
        int sum = gpSum(A_1, r, numEls);
         printf("non padded sum: ");
        printBits(sum);
        sum = paddedSum(sum, n, i);  
        // We first flip `sum` bits because currently 1s in sum represent multiples
        sum = flip(sum);
        printf("sum: ");
        printBits(sum);
        // Cancel out bits that represent multiples of i
        // We are going to drop some bits. The ones that are multiples of i
        // We first store some values
        int bitsOnRightToDrop = n - (2 * i) ;
        int notToChangeBits = dropRightBits(runner, bitsOnRightToDrop);
        int withoutSum = runner & sum;
        // printf("Runner: ");
        runner = notToChangeBits | withoutSum;
        // printBits(runner);
        i++;
    }
    primeBitsetToArray(runner, primes);
}

int runningPrimes(int max)
{
    return pow(2, max) - 1;
}

int paddedSum(int sum, int n, int i) {
    return sum * pow(2, (n % i));
}

/** Find sum of a geometric progression 
 * a_1: first element in GP
 * r: common ratio
 * n: number of elements in GP
*/
int gpSum(int a_1, int r, int n)
{
    return a_1 * (pow(r, n) - 1) / (r - 1);
}

/* Compute common ratio to be used for a given number */
int commonRatio(int i)
{
    return pow(2, i);
}

/** Find number of elements in a GP
 * a_1: first element in GP
 * a_n: last element in GP
 * r : common ratio
 */
int numElementsInGP(int a_1, int a_n, int r)
{
    return log2(a_n / a_1) / log2(r) + 1;
}

/* Find last element in bitset as decimal integer
* For example if bitset is 10010 , last element is 10000 = 16
* width: Number of characters in bitset.
*/
int lastElementInBitset(int width)
{
    return pow(2, (width - 1));
}

/* Produces the number of bits from first multiple greater than factor to last multiple less than n. */
int width(int factor, int n)
{
    int firstMultGR = 2 * factor;
    int lastMultLess = n - (n % factor);
    return lastMultLess - firstMultGR + 1;
}



// -- Bit functions --

/** Convert binary to decimal integer */
int btoi(char s[])
{
    int result = 0;
    int i = 0;
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
void itob(int n, char s[])
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
    int pos = log2(n);
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
void printBits(int num)
{
    char result[MAXLINE];
    itob(num, result);
    printf("%s\n", result);
}

// Flip bits. For example 10110 becomes 1001
int flip(int bitset)
{
    int mask = pow(2, (int) log2(bitset) + 1) - 1;
    return bitset ^ mask;
}

// Drop some bits from the right side of a bitset. For example dropRighBits(btoi("1001100110"), 6) produces 1001000000
int dropRightBits(int bitset, int noToDrop) {
    int mask = pow(2, noToDrop) - 1; 
    int rightFlippedBitset = bitset ^ mask;
    return bitset & rightFlippedBitset;
}


/* Copy bitset representing prime positions into an array of prime numbers */
void primeBitsetToArray(int bitset, int primes[])
{
    char temp[MAXLINE];
    itob(bitset, temp);
    // printf("bitset %s\n", temp);
    // in the bitset, the first position represents number 1 then 2 ... etc So our primes will start at index 1 
    int i = 1;
    int j = 0;
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

void printPrimes(int primes[], size_t size)
{
    int i = 0;
    while(i < size && primes[i] != -1)
    {
        printf("%d, ", primes[i]);
        i++;
    }
    printf("\n");
}