#include <stdio.h>

/* function prototype */
int power(int m, int n);
int power2(int m, int n);


int kk();

/* test power function */

int main() {
    int i;
    for(i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power2(2, i), power(-3, i));
    }
    printf("%d", kk(8, 6));
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int i, p;
    p = 1;
    for(i = 1; i <= n; i++) {
        p = p * base;
    }
    return p;
}


/* power fn version that makes use of call by value feature in C: raise base to n-th power; n >= 0 */
int power2(int base, int n) {
    int p;
    for(p = 1; n > 0; n--) {
        p = p * base;
    }
    return p;
}
/* old style */
int kk(base, n) 
int base, n;
{
    return base * n;
}