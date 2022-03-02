#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s[], int c);
void strcat2(char s[], char t[]);

// exercise 2-4
void squeeze2(char s1[], char s2[]);
// exercise 2-5
int any(char s1[], char s2[]);

int main()
{
    int a = 10;
    int b = a++;
    a = 10;
    int c = ++a;
    printf("b %d , c %d\n", b, c);
    char s[] = "Memories of Midnight";
    printf("Squeeze %s on char %c into: ", s, 'i');
    squeeze(s, 'i');
    printf("%s\n", s);
    printf("*** strcat ***\n");
    char phrase0[1000] = "K & R";
    char phrase1[] = "Types, Operators and Expression";
    strcat2(phrase0, phrase1);
    printf("%s\n", phrase0);

    printf("\n*** squeeze2 ***\n");
    char x[MAXLINE] = "Technology";
    char removeThese[MAXLINE] = "yno";
    squeeze2(x, removeThese);
    printf("%s\n", x);

    printf("\n*** any ***\n");
    char meta[MAXLINE] = "Metamorphosis";
    char checkThese[MAXLINE] = "zygote";
    int pos = any(meta, checkThese);
    int shouldNotBeFound = any(meta, "zzqq");
    printf("Position using any is %d\n", pos);
    printf("should not be found position using any is %d\n", shouldNotBeFound);
}

void squeeze(char s[], int c)
{
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)
    {
        if(s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* strcat2: concatenate t to end of s. Assumes s is big enough to hold result */
void strcat2(char s[], char t[])
{
    int i = -1;
    while(s[++i] != '\0')
        ;
    int j = 0;
    while(t[j] != '\0')
        s[i++] = t[j++];
}

/* squeeze2: function that deletes each character in s1
    that matches any character in the string s2
    */
void squeeze2(char s1[], char s2[])
{
    char result[MAXLINE];
    int k = 0, i = 0;
    // squeeze s1 into result
    while(s1[i] != 0)
    {
        int j = 0;
        while(s2[j] != 0 && s2[j] != s1[i])
        {
            j++;
        }
        if(s2[j] == 0) 
        {
            // no match
            result[k] = s1[i];
            k++;
        }
        i++;
    }
    // copy result to s1
    i = 0;
    while(result[i] != 0)
    {
        s1[i] = result[i];
        i++;
    }
    // mark end
    s1[i] = 0;
}

/**
 * Function that returns the first location in the 
 * string s1 where any character from the string s2 occurs, or 
 * -1 if s1 contains no character from s2.
 * Similar to standard library function strpbrk */
int any(char s1[], char s2[])
{
    int i = 0;
    while(s1[i] != 0)
    {
        int j = 0;
        while(s2[j] != 0)
        {
            if(s1[i] == s2[j])
            {
                return i;
            }
            j++;
        }
        i++;
    }
    return -1;
}


