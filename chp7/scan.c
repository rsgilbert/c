#include <stdio.h>

int main()
{
    double sum, v;
    char person[100];
    sum = 0;
    int s;
    while((s = scanf("%lf", &v)) == 1) // lf for double
    {
        printf("Input is %d, v is %lf, Sum is %.2lf\n", s, v,  sum += v);
    }
    printf("Final sum at %d is %f\n", s, sum);

}