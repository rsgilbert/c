#include <stdio.h>
#define MAXLINE 1000
void filecopy(FILE *, FILE *);

// concatenate files. version 1
int main(int argc, char **argv)
{
    FILE *fp;
    if (argc == 1)
    { // no args. copy stdin
        filecopy(stdin, stdout);
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
                printf("cat: cannot open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);                
            }
            argv++;
        }
    }
}

// copy file ifp to file ofp
void filecopy(FILE *inf, FILE *outf)
{
    int c; 
    while((c = getc(inf)) != EOF)
    {
        putc(c, outf);
    }
}