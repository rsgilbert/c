#include <stdio.h>
#include <ctype.h>
#include <string.h>

void low()
{
    int c;
    while((c = getchar()) != '\n')
    {
        putchar(tolower(c));
    }
}

void high()
{
    int c;
    while((c = getchar()) != '\n')
    {
        putchar(toupper(c));
    }
}
int main(int argc, char *argv[])
{
    // printf("arg %s", argv[1]);
    char * actionarg = argv[1];
    if(!strcmp(actionarg, "LOW"))
    {
        low();
    }
    else if(!strcmp(actionarg, "UPPER"))
    {
        high();
    }
    else printf("INVALID argument %s", actionarg);

}