#include <stdio.h>
#include "./syscalls.h"



int main() 
{ // copy input to output
    char buff[BUFFSIZE];
    int n;

    while((n = read(FD_STDIN, buff, BUFFSIZE)) > 0)
    {
        write(FD_STDOUT, buff, n);
    }
}