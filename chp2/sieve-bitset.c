#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define MAXLINE 1000
#define A_1 1 // first number in GP 

// sieve of eratosthenes
// Using bit arithmetic
uint64_t  btoi(char s[]);
void itob(uint64_t  n, char s[]);
uint64_t  runningPrimes(uint64_t  max);
void printBits(uint64_t  num);
uint64_t  gpSum(uint64_t  a_1, uint64_t  r, uint64_t  n);
uint64_t  numElementsInGP(uint64_t  a_1, uint64_t  a_n, uint64_t  r);
uint64_t  lastElementInBitset(uint64_t  width);
uint64_t  width(uint64_t  factor, uint64_t  n);
uint64_t  paddedSum(uint64_t  sum, uint64_t  n, uint64_t  i);
uint64_t  commonRatio(uint64_t  i);
uint64_t  flip(uint64_t  bitset);
void sieve(uint64_t  n, uint64_t  primes[]);
uint64_t  dropRightBits(uint64_t  bitset, uint64_t  noToDrop);
void primeBitsetToArray(uint64_t  bitset, uint64_t  primes[]);
void printPrimes(uint64_t  primes[], size_t size);
uint64_t  greaterFirstBit(uint64_t  bitset);

uint64_t  main()
{
    uint64_t  n = 53; // 32 is not supported (??) I dont know why
    uint64_t  runner = runningPrimes(n);
    uint64_t  primes[n];
    sieve(n, primes);
    printPrimes(primes, n);
}


/**
 * sieve of eratosthenes
 * Algorithm for finding all prime numbers upto a given limit.
 * We go through natural numbers starting with 2 removing out multiples of each.
 */
void sieve(uint64_t  n, uint64_t  primes[])
{
    // 1. fill in numbers
    uint64_t  runner = runningPrimes(n);
    uint64_t  start_no = 2;
    uint64_t  i = start_no;
    while(i <= n)
    {
        // printf("%d\n", i);
        uint64_t  w = width(i, n);
        uint64_t  lastEl = lastElementInBitset(w);
        uint64_t  r = commonRatio(i);
        uint64_t  numEls = numElementsInGP(A_1, lastEl, r);
        uint64_t  sum = gpSum(A_1, r, numEls);
        //  printf("non padded sum: w %d , r %d , numEls %d ", w, r, numEls);
        // printBits(sum);
        sum = paddedSum(sum, n, i);  
        // We need to flip `sum` bits because currently 1s in sum represent multiples
        // If we flip 1010 it becomes 101. But notice we also want to remove 1000. 
        // If we dont handle this, 4 will show up in the primes
        // So we first get a copy of first bit 
        uint64_t  grtrBitset = greaterFirstBit(sum);
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
        uint64_t  bitsOnRightToDrop = n - (2 * i) + 1;
        uint64_t  notToChangeBits = dropRightBits(runner, bitsOnRightToDrop);
        uint64_t  withoutSum = runner & sum;
        // printf("Runner: ");
        runner = notToChangeBits | withoutSum;
        // printBits(runner);
        i++;
    }
    primeBitsetToArray(runner, primes);
}

uint64_t  runningPrimes(uint64_t  max)
{
    return pow(2, max) - 1;
}

uint64_t  paddedSum(uint64_t  sum, uint64_t  n, uint64_t  i) {
    return sum * pow(2, (n % i));
}

/** Find sum of a geometric progression 
 * a_1: first element in GP
 * r: common ratio
 * n: number of elements in GP
*/
uint64_t  gpSum(uint64_t  a_1, uint64_t  r, uint64_t  n)
{
    return a_1 * (pow(r, n) - 1) / (r - 1);
}

/* Compute common ratio to be used for a given number */
uint64_t  commonRatio(uint64_t  i)
{
    return pow(2, i);
}

/** Find number of elements in a GP
 * a_1: first element in GP
 * a_n: last element in GP
 * r : common ratio
 */
uint64_t  numElementsInGP(uint64_t  a_1, uint64_t  a_n, uint64_t  r)
{
    return log2(a_n / a_1) / log2(r) + 1;
}

/* Find last element in bitset as decimal integer
* For example if bitset is 10010 , last element is 10000 = 16
* width: Number of characters in bitset.
*/
uint64_t  lastElementInBitset(uint64_t  width)
{
    return pow(2, (width - 1));
}

/* Produces the number of bits from first multiple greater than factor to last multiple less than n. */
uint64_t  width(uint64_t  factor, uint64_t  n)
{
    uint64_t  firstMultGR = 2 * factor;
    uint64_t  lastMultLess = n - (n % factor);
    return lastMultLess - firstMultGR + 1;
}



// -- Bit functions --

/** Convert binary to decimal integer */
uint64_t  btoi(char s[])
{
    uint64_t  result = 0;
    uint64_t  i = 0;
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
void itob(uint64_t  n, char s[])
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
    uint64_t  pos = log2(n);
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
void printBits(uint64_t  num)
{
    char result[MAXLINE];
    itob(num, result);
    printf("%s\n", result);
}

// Flip bits. For example 10110 becomes 1001
uint64_t  flip(uint64_t  bitset)
{
    uint64_t  mask = pow(2, (long) log2(bitset) + 1) - 1;
    return bitset ^ mask;
}

// Drop some bits from the right side of a bitset. For example dropRighBits(btoi("1001100110"), 6) produces 1001000000
uint64_t  dropRightBits(uint64_t  bitset, uint64_t  noToDrop) {
    uint64_t  mask = pow(2, noToDrop) - 1; 
    uint64_t  rightFlippedBitset = bitset ^ mask;
    return bitset & rightFlippedBitset;
}


/* Copy bitset representing prime positions into an array of prime numbers */
void primeBitsetToArray(uint64_t  bitset, uint64_t  primes[])
{
    char temp[MAXLINE];
    itob(bitset, temp);
    // printf("bitset %s\n", temp);
    // in the bitset, the first position represents number 1 then 2 ... etc So our primes will start at index 1 
    uint64_t  i = 1;
    uint64_t  j = 0;
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
uint64_t  bitsetForFirstBit(uint64_t  bitset) {
    return pow(2, log2(bitset));
}

/* Return bitset that is greater than given bitset but also a multiple of 2.
* For example bitsetForFirstBit(10) = 16
*/
uint64_t  greaterFirstBit(uint64_t  bitset) {
    return pow(2, (long) log2(bitset) + 1);
}


void printPrimes(uint64_t  primes[], size_t size)
{
    uint64_t  i = 0;
    while(i < size && primes[i] != -1)
    {
        printf("%d, ", primes[i]);
        i++;
    }
    printf("\n");
}