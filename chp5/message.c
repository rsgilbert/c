#include <stdio.h>

void change(char s[])
{
    s[1] = 'R';
}

int main()
{
    char amess[] = "TOday is the day\n";
    char *pmess = amess;//"Today is greater pointer\n";

    printf(amess);
    printf(pmess);

    // *(pmess + 2) = '#';
    // *(pmess)
    change(pmess);
    printf("letter is %c\n", *(pmess + 1));
    printf(pmess);
    printf(amess);
    // char s[] = "Moses";
    // printf("first %c\n", *s);
    // printf("hello world\n");

    // char *pm;
    // pm = "Jaguar\n";
    // printf(pm);
    // char w[] = "Mongo\n";
    // printf(w);
    // pm = w;
    // printf(pm,"now", pm);
}

