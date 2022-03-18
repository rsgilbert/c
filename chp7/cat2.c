#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
void filecopy2(FILE *, FILE *);

// concatenate files. version 2
int main(int argc, char **argv)
{
    FILE *fp;
    char *programname = *argv; // for errors
    if (argc == 1)
    { // no args. copy stdin
        filecopy2(stdin, stdout);
    }
    else
    {
        char *filename;
        argc--;
        argv++;
        while (argc-- > 0)
        {
            filename = *argv;
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                fprintf(stderr, "%s: cannot open %s\n", programname, *argv);
                exit(1);
            }
            else
            {
                filecopy2(fp, stdout);
                fclose(fp);                
            }
            argv++;
        }
        if(ferror(stdout))
        {
            fprintf(stderr, "%s: error writing to stdout\n", programname);
            exit(2);
        }
        exit(0);
    }
}

// filecopy v2: copy file ifp to file ofp
void filecopy2(FILE *inf, FILE *outf)
{
    int c, d; 
    while(c = getc(inf))
    {
        if(feof(inf))
        {
            break;
        }
        putc(c, outf);
    }
}