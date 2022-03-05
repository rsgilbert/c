#include <stdio.h>
#include <math.h>
#define MAXLINE  1000


int btoi(char s[]);
void itob(int n, char s[]);

int main()
{
    printf("btoi\n");
    char s1[] = "1011001";
    int num1 = btoi(s1);
    char s2[] = "1001011";
    int num2 = btoi(s2);

    // and 
    int andResult = num1 & num2;
    char result[MAXLINE];
    itob(andResult, result);

    // or 
    int orResult = num1 | num2; // 1011011
    char result2[MAXLINE];
    itob(orResult, result2);

    printf("%d & %d = %d , %s\n", num1, num2, andResult, result); 
    printf("%d | %d = %d , %s\n", num1, num2, orResult, result2); 
}

/** Convert binary to decimal integer */
int btoi(char s[])
{
    int result = 0;
    int i = 0;
    while(s[i] != 0)
    {
        if(s[i] != '0' && s[i] != '1')
            return -1;
        result *= 2;
        result += s[i] - '0';
        i++;
    }
    return result;
}

/** convert decimal integer to binary */
void itob(int n, char s[])
{
    if(n == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return;
    };
    if(n < 0) 
    {
        s[0] = '-';
        s[1] = '1';
        s[2] = 0;
        return;
    }
    int pos = log2(n);
    s[pos + 1] = 0;
    while(pos != 0)
    {
        s[pos] = '0' + n % 2;
        n = n / 2;
        pos--;
    }
    // pos will be 0
    s[pos] = '1';
}