#include <stdio.h>

int main()
{
    long count;
    int c;
    while( (c = getchar()) != EOF)
    {
        if(c == ' ' )
            ++count;
        if(c == '\n')
            ++count;
        if(c == '\t')
            ++count;
    }
    printf("Count of blanks, newlines and tabs is %ld", count);
}