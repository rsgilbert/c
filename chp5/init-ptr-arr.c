#include <stdio.h>

char *month_name(int n)
{
    // Array of character pointers
    // Each pointer points to a character array of varying size
    static char *name[] = {
        "Illegal month", 
        "Jan", "Feb", "Mar",
        "Apr", "May", "Jun", "Jul",
        "Aug", "Sep", "Oct",
        "Nov", "Dec"   
    };
    printf("%c\n", *(name[4] + 1));
    return (n > 0 && n <= 12) ? name[n] : name[0];
}

int main()
{
    char * fourthmonth = month_name(4);
    printf("Fourth month is %s\n", fourthmonth);
}