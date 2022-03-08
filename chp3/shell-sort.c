#include <stdio.h>

void shellsort(int v[], int n);
void printarr(int arr[], int n);

int main()
{
    int n = 5;
    int v[] = { 10, -12, 5, 30, 3 };
    shellsort(v, n);
    printarr(v, n);

}

/* Sorting algorithm invented in 1959 by D. L. Shell. 
* Far-apart elements are compared, rather than adjacent ones so as
* to eliminate large amounts of disorder quickly so later stages have less work to do.
*/
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2)
    {
        // perform sort on pairs of items `gap` positions apart.
        for(i = gap; i < n; i++)
        {
            // we loop through the elements, if we find a pair that 
            // can be swapped, it means we've brought a smaller value to 
            // a lower point in the array so we have to try the sort again 
            // with another element at the next lower point.
            for(j=i-gap; (j>=0 && v[j] > v[j+gap]); j-=gap)
            {
                // at this point far away items are not sorted, so we swap them
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                printarr(v, n);
            }
        }
    }
}

void printarr(int arr[], int n)
{
    int i = 0;
    while(i < n)
        printf("%d, ", arr[i++]);
    printf("\n");
}


