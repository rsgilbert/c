#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXOP 100  // max size of operand or operator
#define NUMBER '#' // signal that a number has been found
#define MAXVAL 100 // maximum depth of val stack 


int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

// external variables
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

/* reverse polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(-pop() + pop());
            break;
        case '/':
            push((1 / pop()) * pop());
            break;
        case '\n':
            printf("result: \t%3.2g\n", pop());
            break;
        default:
            //printf("Error: unknown command %s, type is %d \n", s, type);
            break;
        }
    }
}

void push(double f)
{
    if(sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: stack full, cant push %g\n", f);
    }
}

/* pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
    {
        return val[sp--];
    }
    else
    {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

/* get next operator or numeric operand */
int getop(char s[])
{
    // printf("getting \n\n");
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
    {}
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
    {
     //   printf("not digit _%c_, s %s\n", c, s);
        return c; /* not a number */
    }
    i = 0;
    // printf("is digit _%c_, s %s\n", c, s);
    if(isdigit(c))
    {
        // collect integer part. If c = `.` dot will also be included before breaking
        while(isdigit(s[++i] = c = getch()))
        {}
    }
    if(c == '.')
    {   
        // collect fraction part
        while(isdigit(s[++i] = c = getch()))
        {}
    }
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    printf("end c is _%c_, num is _%c_", c, NUMBER);
    return NUMBER;
}

#define BUFSIZE 100 
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf 

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    {
        printf("Error: Reached maximum buffer size %d\n", BUFSIZE);
        return;
    }
    buf[bufp++] = c;
}







