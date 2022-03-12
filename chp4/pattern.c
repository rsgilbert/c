#include <stdio.h>
#define MAXLINE 1000

/* getline2 is defined in other.c */
int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];

    while(getline2(line, MAXLINE) > 0)
    {
        if(strindex(line, pattern) >= 0)
        {
            printf("%s", line);
        }
    }

}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for(i = 0; s[i] != 0; i++)
    {
        for(j = i, k = 0; t[k] != 0 && s[j] == t[k]; j++, k++)
        {
        }
        // check that all letters in t have been covered
        if(k > 0 && t[k] == 0)
        {
            return i;
        }
    }
    return -1;
}