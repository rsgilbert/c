#include <stdio.h>

// echo v1
// argv[0] is the path to the executable.
int main(int argc, char *argv[])
{
    int  i;
    printf("arg count %d, argv[0] %s\n", argc, argv[0]);
    for(i = 1; i < argc; i++)
    {
        printf("%s,", argv[i]);
    }
    printf("\n");
}