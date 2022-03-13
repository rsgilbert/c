#include <stdio.h>

#define ALLOCSIZE 100 // size of available space

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf;  // next free position

// Return pointer to n characters
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE >= allocp + n)
    { // it fits
        allocp += n;
        return allocp - n;
    } 
    // not enough room
    return NULL;
}

// free storage pointed to by p
void afree(char *p)
{
    if(p >= allocbuf && p < allocp)
    {
        allocp = p;
    }
}

int main()
{
    char * cp = alloc(3);
    printf("%c\n", *cp);
    afree(cp+1);

    cp = cp + 2;
    // cp = (char *) 0;
    // cp = NULL;
    printf("%c\n", *cp);
}