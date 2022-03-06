#include <stdio.h>

int btoi(int bits[]);
void itob(int num, int result[32]);
void playground();
void printbits(int num);

unsigned getbits(unsigned x, int p, int n);
// exercises
unsigned setbits(unsigned x, int p, unsigned n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

// helpers
unsigned rightmost(unsigned x, int num);
unsigned maskofones(int n);

int main()
{
  playground();

}


/* 
 * Given Example
 * getbits: get n bits from position p
 * Returns right-adjusted nbit field of x that begins at position p.
 * We assume that bit position 0 is at right end.
 * For example getbits(x, 4, 3) returns bits in bit positions 4, 3, and 2 right adjusted.
 */
unsigned getbits(unsigned x, int p, int n)
{
    unsigned dropOffRight = x >> (p + 1 - n); 
    unsigned nRightOnes =  ~(~0 << n);
    // unsigned nRightOnes = (1 << n) - 1;
    // return nRightOnes; 
   return dropOffRight & ~(~0 << n);
}

/*
* Ex 2-6. Returns x with the n bits that begin at position p set to the
* rightmost n bits of y leaving the other bits unchanged.
 * We assume that bit position 0 is at right end.
* for-example setbits(110010b, 4, 2, 101b) = 101010b
*/
unsigned setbits(unsigned x, int p, unsigned n, unsigned y)
{    
    int lastBitCount = p - n + 1;
    unsigned replacementBits = rightmost(y, n);
    unsigned lastBitsOnX = rightmost(x, lastBitCount);
    unsigned droppedAllRightBitsFromP = x >> (p + 1);
    unsigned addedBitsFromY = (droppedAllRightBitsFromP << n) | replacementBits;
    unsigned addedLastBits = (addedBitsFromY << lastBitCount) | lastBitsOnX;
    return addedLastBits;
}

/**
 * @brief Ex 2-7. Produces x with the n bits that begin at position p inverted leaving the others unchanged.
 * For example invert(110010b (50), 4, 2) = 101010b (42)
 */
unsigned invert(unsigned x, int p, int n)
{
    unsigned leftbits = x >> (p + 1);
    unsigned toInvertBits = getbits(x, p, n);
    unsigned invertedBits = maskofones(n) ^ toInvertBits;
    unsigned rightbits = rightmost(x, p - n + 1);
    // compose result
    unsigned result = leftbits << n;
    result = result | invertedBits;
    result = result << (p - n + 1);
    result = result | rightbits;
    return result;
}

/*
* Produces the value of integer x rotated to the right by n bit positions 
* For example: rightrot(1010111b, 3) = 1111010b
*/
unsigned rightrot(unsigned x, int n)
{
    // We assume 32bit 
    int SIZE = 32;
    unsigned rightBitsToMoveToLeft = rightmost(x, n);
    unsigned leftmostBits = rightBitsToMoveToLeft << (SIZE - n);
    unsigned bitsToPlaceToTheRight = x >> n;
    unsigned result = leftmostBits | bitsToPlaceToTheRight;
    return result;
}
// -- Utilities --
/*
* Get bitset representing rightmost `num` bits in `x` 
* eg rightmost(6, 2) = 2
*/
unsigned rightmost(unsigned x, int num)
{
    unsigned mask = (1 << num) - 1;
    return x & mask;
}

/*
* Get a mask bitset made of `n` ones
*/
unsigned maskofones(int n)
{
    return (1 << n) - 1;
}


void playground()
{
    // -- setbits --
    // int x = 50; // 110010b
    // int y = 5; // 101b
    //  int x = 374; // 101110110b
    // int y = 3; // 11    . Result should be 101111110b (382d)
    // int result = setbits(x, 4, 2, y); // 101010b -> 42
    // printf("result setbits(%d, 4, 2, %d) = %d\n", x, y, result);
    // printbits(result);

    // -- invert -- 
    // int x = 50; // 110010b
    // int p = 4;
    // int n = 2;
    // int x = 3274; // 0b110011001010
    // int p = 6;
    // int n = 3;
    // int result = invert(x, p, n); // we expect 3258 (0b110010111010)
    // printf("invert(%d, %d, %d) = %d\n", x, p, n, result);
    // printbits(result);

    // -- right rotation --
    int x = 3251; // 0b110010110011
    int n = 5;
    int result = rightrot(x, n);  // we expect the bits: 10011000000000000000000001100101
    printf("rightrot(%d, %d) = %d\n", x, n, result);
    printbits(result);
}

/** Convert binary to decimal integer */
int btoi(int bits[32])
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
        startidx--;
    }
    return result;
}


// Get bit representation of a 32-bit integer
void itob(int num, int result[32])
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
    itob(num, bits);
    int i = 31;
    while(i >= 0)
    {
        printf("%d", bits[i]);
        i--;
    }
    printf("\n");
}