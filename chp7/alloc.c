#include <stdio.h>
#include <stdlib.h>

// storage allocation

int main()
{
    char * arr =  calloc(5, sizeof(char));
    printf("%s #%d# %s #%d#  %s #%d#\n", arr[0], arr[1], arr[2]);
}