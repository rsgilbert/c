#include <stdio.h>

int main()
{
    int c; 
    int count = 0;
    // printf("b is %d", c = getchar() != EOF);
    // printf("eof is %d , :%c:zn\n", EOF, EOF);
    while( (c = getchar()) != EOF)
    {
        putchar(c);
        printf("\n c is %d\n", c);
        c = getchar();
        // count++;
        // printf("Count is %d\n", count);
    }
}