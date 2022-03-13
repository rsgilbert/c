#include <stdio.h>

/* return <0 if s <t, 0 if s == t, >0 if s>t */
int strcmp2(char *s, char *t) 
{
    int i;
    for(i = 0; s[i] && s[i] == t[i]; i++)
    {}
    return s[i] - t[i];
}

/* pointer version */
int strcmp3(char *s, char *t)
{
    int i;
    while(*s++ == *t++)
    {}
    return *--s - *--t;
}

int main()
{
    char a[] = "Moste";
    char b[] = "Moses";
    printf("strcmp2 %d\n", strcmp2(a, b));
    printf("strcmp3 %d\n", strcmp3(a, b));
}
