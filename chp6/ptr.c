#include <stdio.h>

// a structure is a list of declarations
// enclosed in brackets.
struct point
{
    int x;
    int y;
};

int main()
{
    struct point origin, *pp;
    origin.x = 0;
    origin.y = 0;
    pp = &origin;
    printf("pp is (%d,%d)\n", (*pp).x, (*pp).y);
    origin.y = 5;
     printf("pp is also (%d,%d)\n", pp->x, pp->y);
}