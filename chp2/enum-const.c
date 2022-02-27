#include <stdio.h>

// Enumeration constant
// A list of constant integer values.

int main()
{
    enum booln { NO, YES };

    int b = NO;
    int b2 = YES;

    printf("%d\n", NO);
    printf("%d\n", b2);

    enum months { JUL = 1, AUG='a', OCT=10, NOV, DEC=-11, JAN };
    int m1 = JUL;
    printf("%d %d %d %d %d %d\n", m1, AUG, OCT, NOV, DEC, JAN, AUG, OCT);
}