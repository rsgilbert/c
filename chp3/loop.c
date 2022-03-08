#include <stdio.h>

int main()
{
    // for(;;)
    // {
    //     printf("loop");
    // }

    int c;
    for(c = getchar(); c != '\n'; c = getchar())
    {
        putchar(c);
    }
}