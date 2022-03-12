#include <stdio.h>
// macro subsitution 
// Replace name with replacement text
#define f for
#define forever for(;;)

// Macro with arguments
#define mx(A, b) A > b ? A : b
#define square(x) (x) * (x)

#define age 30
#undef age
#define age 11


// #undef square
#define dprint(expr) printf("here" #expr " = %d\n", expr)

#define conc(a, b) a ## b

int main()
{
    printf("pasted token value is : %d\n", conc(a, ge)); // age
   
    // printf("%c\n", 'dq');
    dprint(3 + age);
    printf("age %d\n", age);
    int a1 = 30;
    int b1 = 50;
    // printf("max %d\n", mx(12, b1++));
    // printf("b is %d\n", b1);


    int p = 10;
    printf("sq %d\n", square(p + 1));

    // printf("max %f\n", mx(2.20, 20.4));
    // int i;
    // f(i = 0; i < 5; i++)
    // {
    //     printf("i is %d\n",  i);
    // }
    // forever
    // {
    //     printf("i %d\n", i);
    //     if(i++ > 10) break;
    // }
}
