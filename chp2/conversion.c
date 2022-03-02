#include <stdio.h>
#include <math.h>


int main()
{
    int a = 445;
    float f = 51.23;

    int f_as_int = f;
    printf("%d\n", f_as_int);

    float a_as_float = a;
    printf("%f\n", a_as_float);

    // coercion -> explicit type conversion.
    // sqrt expects double
    int num  = 1050;
    double s = sqrt((int) num);
    printf("sqrt of %d is %f\n", num, s);
}