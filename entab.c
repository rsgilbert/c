#include <stdio.h>

// Exercise 1-21
// A program that replaces strings of blanks
// by the minimum number of tabs and blanks to achieve the same spacing

#define BLANK ' '
#define TAB 'T'

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);
void entab(char line[], char entabbed_line[]);
int get_length(char line[]);

int main()
{
    int len;            // current line length
    int max;            // maximum length seen so far
    char line[MAXLINE]; // current input line

    while ((len = getline2(line, MAXLINE)) > 0)
    {
        char entabbed_line[MAXLINE];
        entab(line, entabbed_line);
        printf("Output: %s", entabbed_line);
    }
}

void entab(char line[], char outline[])
{
    int i = 0;
    int j = 0;
    while (line[i] != '\0')
    {
        if ((line[i + 0] == BLANK) &&
            (line[i + 1] == BLANK) &&
            (line[i + 2] == BLANK) &&
            (line[i + 3] == BLANK))
        {
            outline[j] = TAB;
            i = i + 4;
            j++;
        }
        else
        {
            outline[j] = line[i];
            i++;
            j++;
        }
    }
}

int get_length(char line[])
{
    int result = 0;
    while (line[result] != '\0')
    {
        result++;
    }
    return result;
}

/**
 * getline2: read a line into s, return length
 */
int getline2(char s[], int limit)
{
    int c, i;
    for (i = 0; i < limit - 1 &&  (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`; assume `to` is big enough */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
