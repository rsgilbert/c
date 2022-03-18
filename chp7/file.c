#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        printf("Expected a file name in args");
        return 1;
    }
    char * filename;
    filename = argv[1];
    FILE *fp;
    fp = fopen(filename, "w");
    char c1, c2, c3;
    c1 = getc(fp);
    c2 = getc(fp);
    c3 = getc(fp);
    printf("Chars read are %c %c %c\n", c1, c2, c3);
    // writes
    char d1, d2, d3;
    d1 = putc('A', fp);
    d2 = putc(' ', fp);
    d3 = putc('5', fp);
    printf("Chars written are %c, %c, %c\n", d1, d2, d3);

    // change mode 
    fclose(fp);
    fp = fopen(filename, "r");
    c1 = getc(fp);
    c2 = getc(fp);
    c3 = getc(fp);
    printf("Chars read are %c %c %c\n", c1, c2, c3);
}
