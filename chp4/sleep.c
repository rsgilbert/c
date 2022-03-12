#include "sleep.h"

extern char day[];

static char time[] = "evening";

void sleep()
{
    static int count = 1;
    printf("I slept %d times on %s %s, count is %d\n", sleepcount, day, time, count++);
}