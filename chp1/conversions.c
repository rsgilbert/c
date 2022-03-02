#include <stdio.h>

int atoi(char s[]);
char lower(char c);

int main()
{
    int a = 3.5555;
    // printf("%d %d\n", a, -242.421);
    char num_str[] = "256";
    printf("%d\n", atoi(num_str) * 2);

    printf("lower  C=%c x=%c 8=%c Y=%c\n", lower('C'), lower('x'), lower('8'), lower('Y'));
}


// atoi. Converts a string to integer
int atoi(char s[])
{
    int i, n;
    n = 0;
    for(i =0; s[i] >= '0' && s[i] <= '9'; i++) 
    {
        n = 10 * n + s[i] - '0';
    }
    return n;
}

// lower. Convert from uppercase to lowercase. ASCII only
char lower(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        c = (c - 'A') + 'a';
    }
    return c;
}