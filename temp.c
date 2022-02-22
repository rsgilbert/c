#include <stdio.h>

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300 */

void main() 
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
    while(fahr <= upper)
    {
        // integer division truncates
        celsius =  ( 5 * (fahr - 32) ) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}