#include <stdio.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);
void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "c-m5-8";
    char s2[MAXLINE];
    expand(s1, s2);
    printf("%s\n", s2);
    char s1_2[] = "-a-b-z0-8";
    expand(s1_2, s2);
    printf("%s\n", s2);
}

/* expands shorthand notation like a-z into equivalent
 * complete string like abcdef...xyz
 */
void expand(char s1[], char s2[])
{
    int i;
    int s2idx = 0;
    for (i = 0; s1[i] != 0; i++)
    {
        if (s1[i] == '-')
        {
            if (i == 0)
            {
                s2[s2idx] = '-';
                s2idx++;
            }
            else
            {
                int first = s1[i - 1];
                int last = s1[i + 1];
                int c;
                for (c = first; c <= last; c++)
                {
                    s2[s2idx] = c;
                    s2idx++;
                }
            }

            s2[s2idx] = 0;
        }
    }
}
