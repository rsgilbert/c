#include <stdio.h>

#define SPACES_PER_TAB 4 

// Exercise 1-20
// A program that replaces tabs in the input
// with the proper number of blanks to space to the
// next tab stop.

int main()
{
    int c;
    while((c = getchar()) != EOF) 
    {
        if(c == '\t') 
        {
            int i;
            for(i = 0; i < SPACES_PER_TAB; i++) 
            {
                // using # instead of ' ' for test purposes
                putchar('#');
            }
        }
        else
        {
            putchar(c);
        }
    }
}
