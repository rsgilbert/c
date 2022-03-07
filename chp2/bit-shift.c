#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

int btoi(char s[]);
int btoi2(int bits[]);
void itob(int n, char s[]);
void itob2(int num, int result[32]);
void playground();
unsigned getbits(unsigned x, int p, int n);
void printbits(int num);
int bitcount(unsigned num);
int bitcount2(int num);
int main()
{
    int n = 56;
    printbits(n);
    printf("%d\n", n);
    printf("%d, using bitcount2 %d \n", bitcount(n), bitcount2(n));

}
/** Count the number of 1 bits in num. num can not be negative
 * because right shifting a negative number still leaves a one at the left end.
 */
int bitcount(unsigned num)
{
    int count = 0;
    for(; num != 0; num = num >> 1)
    {
        if(num & 1)
        {
            count++;
        }
    }
    return count;
}

/* Use the fact that x & (x-1) produces a value that is x without the rightmost 1-bit.
* This program is more efficient than the earlier bitcount(int num) because it skips zero bits so less iteration occurs.
*/
int bitcount2(int num)
{
    int count = 0;
    for(; num != 0; num = num & (num - 1))
    {
        count++;
    }
    return count;
}

/* getbits: get n bits from position p
 * Returns right-adjusted nbit field of x that begins at position p.
 * We assume that bit position 0 is at right end.
 * For example getbits(x, 4, 3) returns bits in bit positions 4, 3, and 2 right adjusted.
 */
unsigned getbits(unsigned x, int p, int n)
{
    unsigned dropOffRight = x >> (p + 1 - n); 
    unsigned nRightOnes = ~1;// ~(~0 << n);
    // unsigned nRightOnes = (1 << n) - 1;
    return nRightOnes; 
   // return dropOffRight & ~(~0 << n);
}



void playground()
{
    char s[MAXLINE] = "111";
    // int num = 
    char result[MAXLINE];
    int a = btoi(s);
    // like muliplying: b = a * 2^3 (or x)
    int b = a << 2;
    itob(b, result);
    printf("left shift\n");
    printf("%d to %d: %s\n", btoi(s), b, result);

    printf("right shift\n");
    char s2[] = "101";
    int a2 = btoi(s2);
    int b2 = a2 >> 1;
    char result2[MAXLINE];
    itob(b2, result2);
    printf("%d to %d : %s \n", btoi(s2), b2, result2);

    printf("complement\n");
    char s3[] = "100";
    unsigned int a3 = btoi(s3);
    unsigned int b3 = ~a3; // ~x == -x - 1
    char result3[MAXLINE];
    itob(b3, result3);
    printf("%d to %d : %s \n", btoi(s3), b3, result3);
}

/** Convert binary to decimal integer */
int btoi(char s[])
{
    int result = 0;
    int i = 0;
    while(s[i] != 0)
    {
        if(s[i] != '0' && s[i] != '1')
            return -1;
        result *= 2;
        result += s[i] - '0';
        i++;
    }
    return result;
}

/** Convert binary to decimal integer */
int btoi2(int bits[32])
{ 
    int result = 0;
    int startidx = 31;
    while(startidx >= 0 && bits[startidx] == 0)
    {
        startidx--;
    }
    while(startidx >= 0)
    {
        result += (1 << startidx) * bits[startidx];
        // printf("result %u", result);
        startidx--;
    }
    printf("final result %u\n", result);
    return result;
}


/** convert decimal integer to binary */
void itob(int n, char s[])
{
    if(n == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return;
    };
    if(n < 0) 
    {
        s[0] = '-';
        s[1] = '1';
        s[2] = 0;
        return;
    }
    int pos = log2(n);
    s[pos + 1] = 0;
    while(pos != 0)
    {
        s[pos] = '0' + n % 2;
        n = n / 2;
        pos--;
    }
    // pos will be 0
    s[pos] = '1';
}

// Get bit representation of a 32-bit integer
void itob2(int num, int result[32])
{
    int i = 0;
    while(i < 32)
    {
        unsigned test_pos = 1 << i; // 2 ^ i
        result[i] = (num & test_pos) > 0;
        i++;
    }
}


void printbits(int num)
{
    int bits[32];
    itob2(num, bits);
    int i = 31;
    while(i >= 0)
    {
        printf("%d", bits[i]);
        i--;
    }
    printf("\n");
}