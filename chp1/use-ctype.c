#include <stdio.h>
#include <ctype.h>

int main() 
{
    printf("isdigit: 'a'=%d , '8'=%d , 2=%d , '0'=%d '3'=%d\n", isdigit('a'), isdigit('8'), isdigit(2), isdigit('0'), isdigit('3'));

    printf("to lower A=%c, X=%c 4=%c m=%c R=%c\n\n", tolower('A'), tolower('X'), tolower('4'), tolower('m'), tolower('R'));

    int a = 4242;
    char c = a;
    printf("%d\n", c);
}
