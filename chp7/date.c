#include <stdio.h>

int main()
{
    int day, year;
    char monthname[20];
    float hrs;

    // scanf("%d %s %d %f", &day, monthname, &year, &hrs);
    // printf("Day is %d/%s/%d at %.1fhrs\n", day, monthname, year, hrs);

    int count;
    char title[20], name[20];
    count = sscanf("Mr. Tory Johnson", "%10s %s", title, name);
    printf("Title is %s and name is %s and count is %d\n", title, "ll", count);
}