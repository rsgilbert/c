#include <stdio.h>

#define MAXLINE 1000

// sieve of eratosthenes

void sieve(int n, int primes[]);
void printPrimes(int primes[], size_t size);
void compact(int s1[], size_t size1, int s2[], size_t size2);

int main()
{
    int primes[MAXLINE];
    int n = 30;
    sieve(n, primes);
    printPrimes(primes, n);

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
/**
 * sieve of eratosthenes
 * Algorithm for finding all prime numbers upto a given limit.
 * We go through natural numbers starting with 2 removing out multiples of each.
 */
void sieve(int n, int primes[])
{
    // 1. fill in numbers
    int start_no = 2;
    int i = 0;
    size_t size = n - start_no + 1;
    int temp[size];
    while(i < size)
    {
        temp[i] = i + start_no;
        i++;
    }

    // zero out multiples
    i = 0;
    while(i < size)
    {   
        int temp_idx = i + 1;
        while(temp_idx < size)
        {
            if(temp[temp_idx] % (i + start_no) == 0)
            {
                temp[temp_idx] = 0;
            }
            temp_idx++;
        }
        i++;
    }
    printPrimes(temp, size);
    compact(temp, size, primes, size);
}

// remove cells that have zeros
void compact(int s1[], size_t size1, int s2[], size_t size2)
{
    int i = 0;
    int j = 0;
    while(i < size1)
    {
        if(s1[i] != 0)
        {
            if(j < size2)
            {
                s2[j] = s1[i];
                j++;
            }
        }
        i++;
    }
    s2[j] = -1;
}