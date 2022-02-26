#include <stdio.h>

/* count digits, white space, others */

int main()
{
    int c, i, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;

    for(i = 0; i < 10; i++) {
        ndigits[i] = 0;
    }
    while( (c = getchar()) != EOF) {
        if(c >= '0' && c <= '9') {
            ++ndigits[c - '0'];
        }
        else if(c == ' ' || c == '\t') {
            ++nwhite;
        }
        else ++nother;
    }
    printf("Digits/n");
    for(i = 0; i < 10; i++) {
        printf("%d: %d\n", i, ndigits[i]);
    }

    printf("whitespace: %d\nOther %d\n", nwhite, nother);
}