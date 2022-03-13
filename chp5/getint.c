#include <stdio.h>

int getint(int *);

int main()
{
    int sum = 0;
    int i, result, arr[5];
    for(i = 0; i < 5; i++)
    {
        int signal = getint(&arr[i]);
        if(signal == -1)
        {
            break;
        }
        sum += arr[i];
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\nSum %d\n", sum);
}

/* Gets an integer and places it in presult. 
* if end of input is reached, it returns -1
* Input can be like: 85231
*/
int getint(int *presult)
{
    char c = getchar();
    if(c == '\n' || c == EOF)
    { 
        return -1;
    }
    *presult = c - '0';
    return c;
}





