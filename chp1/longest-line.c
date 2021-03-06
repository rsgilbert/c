#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;  // current line length
    int max; // maximum length seen so far 
    char line[MAXLINE]; // current input line 
    char longest[MAXLINE]; // longest line saved here 
    // printf("%c %c %c %c", -1, 0, 1, 47);

    max = 0;
    while( (len = getline2(line, MAXLINE)) > 0) {
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) {
        // there was a line. We print it
        printf("Longest has length %d, chars %s\n", max, longest);
    }
}

// /**
//  * getline2: read a line into s, return length 
//  */
// int getline2(char s[], int limit) {
//     int c, i;
//     for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
//         s[i] = c;
//     }
//     if(c == '\n') {
//         s[i] = c;
//         i++;
//     }
//     s[i] = '\0';
//     return i;
// }



/**
 * Exercie 2.2
 * // Loop equivalent that doesnt use &&
 * getline2: read a line into s, return length 
 */
int getline2(char s[], int limit) {
    int c, i;
    // for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    //     s[i] = c;
    // }
    for(i = 0; i < limit - 1; i++) {
        if((c = getchar()) != EOF) {
            if(c != '\n') {
                s[i] = c;
            }
            else {
                limit = 0;
                i--;
            }
        }
        else {
            limit = 0;
            i--;
        }
       
    }
    if(c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy `from` into `to`; assume `to` is big enough */
void copy(char to[], char from[]) {
    int i = 0; 
    while( (to[i] = from[i]) != '\0') {
        i++;
    }
}
