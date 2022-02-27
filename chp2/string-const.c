#include <stdio.h>
#include <string.h>

int main()
{
    // return length of character string 
    char s1[] = "This is my daily bread";
    char s2[] = "Taken from me";
    char s3[] = "Hozanna" "Hallelujah";

    
    printf("%d %d %d\n", strlen(s1), strnlen(s2, 4), strnlen(s3, 50));
    printf("%d\n", s3[17]);
}