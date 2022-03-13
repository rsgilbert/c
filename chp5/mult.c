#include <stdio.h>

/* use a pointer to a multidimensional array as argument */
void printmult(int (*mult)[5], int sz)
{
    int i, j;
    for(i = 0; i < sz; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d,", (*(mult+i))[j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{   
    int m[3][5] = {
        {2, 4, 0, 77},
        {3, 5, 2},
        {5 ,11, -34 }
    };
    printmult(m, 3);

}