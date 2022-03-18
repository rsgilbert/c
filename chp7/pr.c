
#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

 // Make ap point to 1st unnamed arg
    va_start(ap, fmt);
    // each va_arg call returns one argument and steps ap to the next
    ival = va_arg(ap, int);
    printf("first ival is %d\n", ival);
    dval = va_arg(ap, double);
    printf("second  is double %f\n", dval);
    sval = va_arg(ap, char *);
    printf("Third is character array %s\n", sval);
    // clean up when done
    va_end(ap);

}

// print
int main()
{
    minprintf("Museum", 40, 22.52, "Kristofer", 12);

    // printf("Yes %d swaz, %.*s, MOon %s", 100, 5, "Greater gatsby", "landing\n");

    // char stmt[1000];
    // sprintf(stmt, "This is a great %10.2s, right\n", "evening");
    // printf("Statement is %s", stmt);
    // sprintf(stmt, "This is a great %-10.2s, right\n", "evening");
    // printf("Statement is %s", stmt);
}