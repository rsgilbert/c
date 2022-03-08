#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);

int main()
{
    char s[] = "magnitude";
    reverse(s);
    printf("%s\n", s);
}

/* reverse string s in-place */
void reverse(char s[])
{
    int i, j;
    char temp;
    int a = (i = 3, j = 5, i = j + 2);
    printf("a is %d\n", a);
    for (i = 0, j = strnlen(s, MAXLINE) - 1; i < j; i++, j--)
    {
        // perform exchange
        temp = s[i], s[i] = s[j], s[j] = temp;
    }
}