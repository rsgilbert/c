#include <stdio.h>


int main()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(i * j > 30)
            {
                goto greaterthan30;
            }
        }
    }

    printf("outside for\n");
    greaterthan30: 
        printf("We reached, i is %d, j %d\n", i, j);
        printf("Bye bye\n");

    printf("without goto\n");

    int found = 0;
    for(i = 0; i < 10 && !found; i++)
    {
        for(j = 0; j < 5 && !found; j++)
        {
            if(i * j > 30)
            {
                found = 1;
                i--;
                j--;
            }
        }
    }

    printf("We reached, i is %d, j %d\n", i, j);
    printf("Bye bye\n");
}