#include <stdio.h>


void swap(char v[], int i, int j);
int reverse_recur(char s[], int pos);

int main()
{
    // reverse 
    char s1[] = "German boaTs";
    printf("original s1 %s\n", s1);
    int result = reverse_recur(s1, 0);
    printf("reversed s1 %s\n", s1);
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
        swap(s, pos, other_pos);
    }
    return other_pos;
}

/* swap: interchange v[i] and v[j] */
void swap(char v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
