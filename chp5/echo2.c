#include <stdio.h>

// echo v2
// Relies on the fact that argv is a pointer to an array of pointers
int main(int argc, char *argv[])
{
    // skip argv[0]
    argv++;
    while(*argv)
    {
        printf("%s,", *argv);
        argv++;
    }
}