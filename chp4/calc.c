#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

/* getline2 is defined in other.c */
// int getline2(char line[], int max);

void playground(void);
int atoi(char s[]);

/* rudimentary calculator */
int main()
{
//    playground();
printf("sta");
    char s[] = "23.92";
    int i = atoi(s);
    printf(" res %d\n", i);
}

void playground()
{
    double sum, atof(char s[]);
    char line[MAXLINE];
    int getline2(char line[], int max);

    sum = 0;
    while(getline2(line, MAXLINE) > 0)
    {
        printf("\t%g\n", sum += atof(line));
    }

}

int atoi(char s[])
{
    double atof(char s[]);
    double atofresult = atof(s);
    printf("atofre %f\n", atofresult);
    return (int) atofresult;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    // skip whitespace
    for(i = 0; isspace(s[i]); i++)
    {}

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for(val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.')
    {
        i++;
    }
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}