#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

int main()
{
    char line[MAXLINE];
    FILE *fp;
    fp = stdin;
    char *line2;
    // line2 = fgets(line, MAXLINE, fp);
    // line2 = gets(line);
    // puts("Swaztenaegar");
    // fputs("Today is your day", stdout);
    // // line2 = getline
    // printf("line is #%s# D%dD and line2 is #%s# D%dD and \n", line, line, line2, line2);


    int sz = getline(line, MAXLINE);
    printf("size for line %s is %d\n", line, sz);
}


/* read a line from stdin and put into `line`, return length */
int getline(char *line, int max)
{
    if(fgets(line, max, stdin) == NULL)
        return 0;
    return strlen(line);
}