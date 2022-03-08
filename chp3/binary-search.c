#include <stdio.h>

/** Binary search. Find x in v[0] <= v[1] .. <= v[n-1] */
int binarysearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (high >= low)
    {
        mid = (low + high) / 2;
        // printf("%d %d %d \n", low, mid, high);
        if (v[mid] == x)
        {
            return mid;
        }
        if (v[mid] > x)
        {
            // Search lower half
            high = mid - 1;
        }
        else
        {
            // Search upper half
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int x = 62;
    int data[] = { -25, 1, 4, 13, 20, 62 };
    int n = 6;
    int pos = binarysearch(x, data, n);
    printf("Pos %d\n", pos);
}
