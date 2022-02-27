#include <stdio.h>

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300 */

void main() 
{
    int fahr;
    float celsius;
    int lower, upper, step;

    lower = 0; /* lower limit */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
    printf("FAHRENHEIT TO CELSIUS CONVERSION\n");
    while(fahr <= upper)
    {
        // integer division truncates
        celsius = (fahr - 32) * (5.0 / 9);
        printf("%3d%8.1f %c\n", fahr, celsius, 'C');
        fahr = fahr + step;
    }
}