#include <stdio.h>

int main()
{
    int days[12] = { 21, 10, 100 };
    int i = 0;
    for(i = 0; i < 12; i++)
    {
       // printf("i %d -> day %d\n", i, days[i]);
    }
    char p1[] = { 'a', 'n', 'g', 'e', 'l', 0 };
    printf("p1 %s %d %d\n", p1, sizeof(p1), sizeof("fkd"));
}

