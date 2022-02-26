#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define MINIMUMLENGTH 5 /* minimum length for which to print */

int getline2(char line[], int maxline);


int main() {
    int len;  // current line length
    int max; // maximum length seen so far 
    char line[MAXLINE]; // current input line 

    while( (len = getline2(line, MAXLINE)) > 0) {
        if(len >= MINIMUMLENGTH) {
            printf("%s", line);
        }
    }
}


/**
 * getline2: read a line into s, return length 
 */
int getline2(char s[], int limit) {
    int c, i;
    for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if(c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
