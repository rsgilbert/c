#include <stdio.h>

// extract magic numbers
#define LOWER 0 /* lower limit */
#define UPPER 150 /* upper limit */
#define STEP 20 /* step size */

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

void main()
{
    int fahr;
    float celsius;

    printf("FAHRENHEIT TO CELSIUS CONVERSION\n");

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    {
        celsius = (fahr - 32) * (5.0 / 9);
        printf("%3d%8.1f %c\n", fahr, celsius, 'C');
    }
}