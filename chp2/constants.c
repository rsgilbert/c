#include <stdio.h>

#define MAXLINE 100
// constant expression MAXLINE+2 maybe evaluated at compile time
char line[MAXLINE + 2];

int main() 
{
    int i = 1234;
    long l = 55555L;
    unsigned u = -18u;
    u = u - 20;
    float f = 2.5f;
    

    printf("%d %d %d %f\n", i, l, u, f);

    // octal 
    int o = 0110; // 72 base 10
    printf("%d\n", o);

    // hexadecimal
    int h = 0X3F; // 3*16^1 + 15*16^0 = 63
    printf("0X3F is %d\n", h);

    unsigned long fifteen = 0XFUL; 
    printf("fifteen is %ld\n", fifteen);

    // character sets
    printf("zero %d\n", '0');
    int vertical_tab = '\013'; // ASCII vertical tab
    printf("vertical tab %d %c\n", vertical_tab, vertical_tab);
    printf("? qn %c %c\n", '\?', '?');
    printf("hexa %c\n", '\x7');
    // null character
    printf("ZERO: %c %d , actual: %c %d", '\0', '\0', 0, 0);
}