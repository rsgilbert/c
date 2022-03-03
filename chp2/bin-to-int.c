#include <stdio.h>
#include <math.h>


int btoi(char s[]);
void itob(int n, char s[]);

int main()
{
    printf("btoi\n");
    char s[100] = "101001";
    printf("%s -> %d\n", s, btoi(s)); 
    printf("\nitob\n");
    char result[100];
    int num = 41;
    itob(num, result);
    printf("%d -> %s\n", num, result); 
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