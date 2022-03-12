#include <stdio.h>

extern int sp;

void swim() 
{
    extern char nm[];
    printf("now Sp is %d and nm is %s\n", sp, nm);
}



