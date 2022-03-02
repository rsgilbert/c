#include <stdio.h>

int htoi(char s[]);

int main()
{
    char s[] = "0x59F";
    char t[] = "0X1a9";
    char u[] = "b5";
    char v[] = "0";
    printf("HEXADECIMAL TO -> INTEGER\n");
    printf("%s -> %d\n", s, htoi(s));
    printf("%s -> %d\n", t, htoi(t));
    printf("%s -> %d\n", u, htoi(u));
    printf("%s -> %d\n", v, htoi(v));
    
}

/* 
 * A function that converts hexadecimal digits into equivalent integer values.
 * If a character is reached that is not a hexadecimal digit, the function returns -1.
 */
int htoi(char s[]) 
{
    int i, c, result;
    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }
    result = 0;
    while((c = s[i]) != '\0')
    {
        result *= 16;
        if(c >= '0' && c <= '9')
        {
            result += (c - '0');
        }
        else if(c >= 'A' && c <= 'F')
        {
            result += c - 'A' + 10; 
        }
        else if(c >= 'a' && c <= 'f')
        {
            result += c - 'a' + 10; 
        }
        else
        {
            return -1;
        }
        i++;
    }
    return result;
}
