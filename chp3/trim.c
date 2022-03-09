#include <stdio.h>
#include <string.h>

void trim(char s[]);
void printNonNegatives(int ar[], int n);

int main()
{
    char s[] = "Josephine    f  \n  ";
    char s2[] = "     ";
    trim(s2);
    printf("%s#\n", s2);

    int ar[] = { 1, 2, -4, -100, 0, 21 };
    printNonNegatives(ar, 6);

}

void printNonNegatives(int ar[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(ar[i] < 0)
            continue;
        printf("%d ", ar[i]);
    }

}

/* remove trailing blanks, tabs, new lines */
void trim(char s[])
{
    int n;
    for(n = strlen(s) - 1; n >= 0; n--)
    {
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n+1] = 0;
}