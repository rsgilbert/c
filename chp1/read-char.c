#include <stdio.h>

/** copy input to output, first version */
int main() 
{
    int c;
    printf("End: %d , %c", EOF, EOF);
    c = getchar();
    printf("Got char%cacter %c\n", 10, c);
    putchar(c);
    printf("Finished putting  first character %c\n", c); 
    c = getchar();
    printf("Got character again %c\n", c);
    putchar(c);
    printf("Finished putting character again %c\n", c);


      c = getchar();
    printf("Got character third again %c\n", c);
    putchar(c);
    printf("Finished putting character third again %c\n", c);
    while(c != EOF)
    {
        // printf("%d is:", c);
        putchar(c);
        // putchar('\n');
        c = getchar();
        printf("Was paused");
    }

}