#include <stdio.h>

/* print n in decimal */
void printdec(int n)
{
    if(n < 0)
    { 
        putchar('-');
        n = -n;
    }
    if(n / 10) 
    {
        printdec(n / 10);
    }
    putchar((n % 10) + '0');
}

int main()
{
    printdec(-9037);
}