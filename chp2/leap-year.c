#include <stdio.h>

int is_leapyear(int year);

// arithmetic operators associate left to right

int main()
{
    int isleap = is_leapyear(100);
    printf("100 is leap is %d\n", isleap);
    int a = 13 % 2;
    printf("a %d\n", a);
}

int is_leapyear(int year)
{
    // logical operators like && or || have lower precedence
    // than relational and equality operators.
    if (
        (year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0))
    {
        return 1;
    }
    return 0;
}