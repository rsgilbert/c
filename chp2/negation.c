#include <stdio.h>

int main() 
{
    // ! is the unary negation operator 
    // It converts a non-zero operand into 0 and 
    // a zero operand into 1 
    int a = !89;
    char name[] = "Simon";
    int b = !name;
    int c = !0;
    printf("%d %d %d %d", a, b, c, !c);
}