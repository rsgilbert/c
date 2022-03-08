#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000

void reverse(char s[]);
char basechar(int decimal);

/** convert integer to string */
void itoa(int n, char s[])
{
    int i = 0;
    // We use `unsigned` rather than `int` to handle INT_MIN
    unsigned abs_n = n;
    if(n < 0)
        abs_n = -n; // make n positive
    do 
    {
        // generate digits in reverse order
        s[i++] = (abs_n % 10) + '0';
    }
    while((abs_n /= 10) > 0);
    if(n < 0)
        s[i++] = '-';
    s[i] = 0;
    reverse(s);
}

/** convert integer to a base-`b` representation in string `s` */
void itob(int n, char s[], int b)
{
    int i = 0;
    // We use `unsigned` rather than `int` to handle INT_MIN
    unsigned abs_n = n;
    if(n < 0)
        abs_n = -n; // make n positive
    do 
    {
        // generate digits in reverse order
        int remainder = abs_n % b;
        s[i++] = basechar(remainder);
    }
    while((abs_n /= b) > 0);
    if(n < 0)
        s[i++] = '-';
    s[i] = 0;
    reverse(s);
}

char basechar(int decimal)
{
    if(decimal >= 10) 
        return 'A' + (decimal - 10);
    return '0' + decimal;
}


int main()
{
    int n = -122;
    char s[1000];
    // itoa(n, s);
    // printf("%s\n", s);
    // handle largest negative number
    // printf("smallest %d\n", INT_MIN);
    // n = INT_MIN;
    // itoa(n, s);
    // printf("%d -> %s\n", n, s);

    // printf("largest %d\n", INT_MAX);
    // n = INT_MAX;
    // itoa(n, s);
    // printf("%d -> %s\n", n, s);

    int b = 16;
    n = 255; // 0xff
    itob(n, s, b);
    printf("%d -> %s\n", n, s);
}

/* reverse string s in-place */
void reverse(char s[])
{
    int i, j;
    char temp;
    for (i = 0, j = strnlen(s, MAXLINE) - 1; i < j; i++, j--)
    {
        // perform exchange
        temp = s[i], s[i] = s[j], s[j] = temp;
    }
}