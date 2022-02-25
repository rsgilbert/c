#include <stdio.h>

int main()
{
    int lower, higher, step;
    lower = 0, higher = 100, step = 20;

    float celsius = lower, fahr;
    
    printf("CELSIUS TO FAHRENHEIT TABLE\n");
    while(celsius <= higher)
    {
        fahr = (celsius * 9.0 / 5.0 ) + 32;
        printf("%3.f%6.1f %c\n", celsius, fahr, 'F');
        celsius += step;
    }
}