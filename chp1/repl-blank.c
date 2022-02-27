#include <stdio.h>
#define BLANK ' '

int main() {
    int lastchar, c; 
    while( (c = getchar()) != EOF) {
        if(c == BLANK) {
            if(lastchar != BLANK)
                putchar(c);
        }
        else 
            putchar(c);
        lastchar = c;
    }
}


