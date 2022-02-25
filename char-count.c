#include <stdio.h>

/* count characters in input, 1st version  */
/* Use Ctrl+D to stop (EOF) */

// int main()
// {
//     long nc;

//     nc = 0;
//     while(getchar() != EOF)
//         ++nc; 
//     printf("%ld\n", nc);
    
// }

// version 2
int main()
{
    double nc;

    int c;
    for(nc = 0; (c = getchar()) != EOF; ++nc)
        ;
        // printf("Char is %c\n", c) ;
    printf("Count is %.0f\n", nc);
    
}