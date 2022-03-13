#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a = 100;
    int b = 400;
    swap(&a, &b);
    printf("a %d, b %d\n", a, b);
}

/* interchange *px and *py */
void swap(int *px, int *py) 
{
    int temp = *px;
    *px = *py;
    *py = temp;
}