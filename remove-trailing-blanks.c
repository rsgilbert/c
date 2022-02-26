#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
void removeTrailingBlanksAndHandleBlankLine();


int main() {
    int len;  // current line length
    int max; // maximum length seen so far 
    char line[MAXLINE]; // current input line 

    while( (len = getline2(line, MAXLINE)) > 0) {
        removeTrailingBlanksAndHandleBlankLine(line);
        printf("%s", line);
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

/**
 * trim line
 */
void removeTrailingBlanksAndHandleBlankLine(char line[]) {
    int i = 0;
    // Find position of null character
    while(line[i] != '\0') {
        i++;
    }
    line[i] = 0;
    i--;

    // Go backwards removing blanks
    while(i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' )) {
        line[i] = 0;
        i--;
    }

    // no new line for blank lines
    if(i >= 0) {
        i++;
        line[i] = '\n';
    }
    i++;
    line[i] = '\0';
}