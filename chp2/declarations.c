#include <stdio.h>

int length_for(const char s[]);
int main()
{
    int lower, upper, step;
    char c, line[1000];
    float eps = 1.0e-5;
    printf("%10f\n", eps);

    // const. Value will not be changed
    const int size = 3;
    printf("Size %d\n", size);

    const char name[] = "Timothy";
    printf("Name is %s\n", name);

    char nm2[] = "Mark";
    int l = length_for(nm2);
    printf("Name %s has length %d\n", nm2, l);

}

int length_for(const char s[]) 
{
    // s[0] = 'J';
    return 3;
}

