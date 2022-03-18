#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compare(FILE *f1, FILE *f2);
#define MAXLINE 1000

// A program to compare two files. Printing the first line where they differ
int main(int argc, char **argv)
{
    if(argc != 3)
    { 
        fprintf(stderr, "%s: Expected two arguments, got %d\n", *argv, argc - 1);
        exit(1);
    }
    char *filename1 = *(argv + 1);
    char *filename2 = *(argv + 2);
    FILE *f1 = fopen(filename1, "r");
    FILE *f2 = fopen(filename2, "r");
    compare(f1, f2);
}

void compare(FILE *f1, FILE *f2)
{
    // must be character arrays, not just pointers
    char f1line[MAXLINE], f2line[MAXLINE];
    do
    {
        if(feof(f1) && feof(f2))
        {
            return;
        }
        // make lines initially blank so they dont start off with undefined characters
        f1line[0] = 0;
        f2line[0] = 0;
        fgets(f1line, MAXLINE, f1);
        fgets(f2line, MAXLINE, f2);
    }
    while(strcmp(f1line, f2line) == 0);
    printf("File 1: %s\n", f1line);
    printf("File 2: %s\n", f2line);
}