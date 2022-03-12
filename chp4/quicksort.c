#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
int reverse_recur(char s[], int pos);
void swap_char(char v[], int i, int j);

int main()
{
    // int arr[] = { 1, 5, -2, 30, 4 };
    // qsort(arr, 0, sizeof(arr));
    // int i = 0;
    // for(i = 0; i < sizeof(arr); i++)
    // {
    //     printf("%d,", arr[i]);
    // }

    // reverse 
    char s1[] = "German boaTs";
    int result = reverse_recur(s1, 0);
    printf("s1 %s\n", s1);
    printf("result %d\n", result);
}
// Reverses a string in place.
int reverse_recur(char s[], int pos)
{
    if(s[pos] == 0)
    {
        return -1;
    }
    int other_pos = 1 + reverse_recur(s, pos + 1);
    if(pos > other_pos)
    {
        swap_char(s, pos, other_pos);
    }
    return other_pos;
}
/* Quick sort. sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    
    if(left >= right)
    {
        // do nothing if array contains < 2 elements
        return;
    }

    // move partition element to v[0]
    swap(v, left, (left + right) / 2);
    last = left;
    // partition
    for(i = left + 1; i <= right; i++)
    {
        if(v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }
    // restore partition element
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* swap: interchange v[i] and v[j] */
void swap_char(char v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}