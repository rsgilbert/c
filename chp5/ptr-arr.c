#include <stdio.h>


// Get bit representation of a 32-bit integer
void itob(unsigned int num, int result[32])
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

// An array-and-index expression is equivalent to one written
// as a pointer and offset.
int main()
{
    unsigned int num1 = 1103100720, num2 = 1103100724, num3 = 1103100728;
    // printbits(num1);
    // printbits(num2);
    // printbits(num3);

    int a[] = { 5, 2, 10, 7, -52 };
    int *pa = &a[0];

    printf("a[0] is %d, a[0] addr is %d a is %d\n", *pa, pa, a);

    // int *p2 = a;
    int *p2;
    p2 = a;
    // int b[] = a;
    printf("idx 3 is > %d\n", *(p2 + 3));
    int *id4 = a + 4;
    printf("at idx 4 is %d\n", *id4);
    printf("p2 idx 2 is %d\n", p2[2]);

    // int x = *pa;
    // printf("x is %d\n", x);

    // int * el2 = pa + 1;
    // printf("el2 is %d\n", *el2);

    // int *el4 = el2 + 1;
    // printf("pa %u el2 %u el4 %u\n", pa, el2, el4);
    // printf("el4 is %d\n", *el4);
}

