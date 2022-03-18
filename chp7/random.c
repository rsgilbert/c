#include <stdio.h>
#include <stdlib.h>

int main()
{
    // produce random numbers
    srand(11);
    printf("%d\n", rand());
    printf("%d\n", RAND_MAX);
    double db = (double) rand() / RAND_MAX;
    printf("%lf\n", db);
}