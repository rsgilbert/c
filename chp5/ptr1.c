#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1, y = 2, z[5];

    int *int_p;

    int_p = &x;
    y = *int_p;
    // printf("int_p %d addr_x %d deref %d, y %d\n", int_p, &x, *int_p, y);

    // *int_p = 20;
    // printf("x %d deref %d, y %d\n", x, *int_p, y);

    // x = 30;
    // printf("x %d deref %d, y %d\n", x, *int_p, y);

    // int_p = &z[1];
    // z[1] = 7;
    // printf("x %d deref %d, z %d", x, *int_p, z[1]);

    int *ip;
    int m = 500;
    ip = &m;
    // unary operators like *, ++ associate right to left
    (*ip)++;
    ++ *ip;
    printf("ip %d\n", *ip);

    int d = 2021;
    int *iq = &d;
    printf("ip %d, iq %d\n", ip, iq);
    // ip = iq;
    *ip = 15;
    ip += 1;
    printf("d %d and ip %d\n", d, *ip);

}