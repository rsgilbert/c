#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
void reverse(char line[]);
void copy(char to[], char from[]);

int main() {
    int len;  // current line length
    int max; // maximum length seen so far 
    char line[MAXLINE]; // current input line 

    while( (len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
        // handle newline character that has been pushed to start
        if(line[0] == '\n') {
            line[0] = '\b';
        }
        printf("%s\n", line);
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

/* reverse: Reverses character string */
void reverse(char line[]) {
    int i, length;
    char templine[MAXLINE];
    copy(templine, line);
    // Find position of null character
    length = 0;
    while(line[length] != '\0') {
        length++;
    }

    i = 0;
    while(line[i] != '\0') {
        line[i] = templine[length - i - 1];
        i++;
    }
}

/* copy: copy `from` into `to`; assume `to` is big enough */
void copy(char to[], char from[]) {
    int i = 0; 
    while( (to[i] = from[i]) != '\0') {
        i++;
    }
}
