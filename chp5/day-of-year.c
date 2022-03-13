#include <stdio.h>

// we can use char to store small non-character integers
static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int isleap(int year)
{
    return !(year % 4) && (year % 100) || !(year % 400);
}

/* day of year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = isleap(year);
    for(i = 1; i < month; i++)
    { 
        day += daytab[leap][i];
    }
    return day;
}

// set month and day from day-of-year
void month_day(int year, int day_of_year, int *month, int *day)
{
    int leap = isleap(year);
    for(*month = 1; day_of_year > daytab[leap][*month]; (*month)++)
    {
        day_of_year -= daytab[leap][*month];
    }
    *day = day_of_year;
}
int main()
{
    int d = day_of_year(2022, 3, 1); // 60
    printf("day of year %d\n", d);
    int month, day, year = 2022;
    month_day(year, 65, &month, &day);
    printf("month is %d and day is %d\n", month, day);
}