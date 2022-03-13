#include <stdio.h>
#include <stddef.h>

/* uses the fact that an array name parameter is a pointer
to compute the length of a character array */
int strlen2(char *s)
{
    int n;
    for (n = 0; *s != 0; n++, s++)
    {
    }
    return n;
}

/* use pointer subtraction to calculate size of character array */
ptrdiff_t strlen3(char *s)
{
    char *p = s;
    while(*p != 0)
    {
        p++;
    }
    ptrdiff_t diff = p - s;
    return diff; 
}


void sz(char s[])
{
    printf("size of %s is %d, prev el is #%c#, idx #%d#\n", s, strlen2(s), s[-1], s[-1]);
}


int main()
{
    char m[] = "Mango";
    printf("size %d\n", strlen3(m));
    // char s1[] = "Pytho of montdkfn";
    // printf("length of s1 %d\n", strlen2(s1 + 4));
    // printf("length of s1 %d\n", strlen2(&s1[2] + 1));
    // printf("length of peterson %d\n", strlen2("peterson"));
    // printf("arr size is %d\n", sizeof(s1));

    // char s2[] = "Groom";
    // sz(s2);
    
    // char * s2ptr = s2;
    // s2ptr++;
    // sz(++s2ptr);
    // sz(++s2ptr);

    double ar[] = { 2.3, 5.1, 8.7 };
    printf("ar %u %u\n", &ar[0], &ar[1]); 
}