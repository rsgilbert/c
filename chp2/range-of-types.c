#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Char\n");
    printf("MIN: %d\n", CHAR_MIN); // -128
    printf("MAX: %d\n", CHAR_MAX); // 127
    printf("End Char\n\n");

    printf("int\n");
    printf("MIN: %d\n", INT_MIN); // -2bn
    printf("MAX: %d\n", INT_MAX); // 2bn
    printf("End int\n\n");

    printf("short\n");
    printf("MIN: %d\n", SHRT_MIN); // -32k
    printf("MAX: %d\n", SHRT_MAX); // 32k
    printf("End short\n\n");

    printf("long\n");
    printf("MIN: %ld\n", LONG_MIN); // -9 million million
    printf("MAX: %ld\n", LONG_MAX); // 9 million million
    printf("End long\n\n");

    printf("unsigned int\n");
    printf("MAX: %ld\n", UINT_MAX); // 4bn
    printf("End unsigned int\n\n");

    printf("float decimal places\n");
    printf("MIN: %d\n", FLT_MIN_10_EXP);  // -37
    printf("MAX: %d\n", FLT_MAX_10_EXP); // 38
    printf("End float decimal places\n");

    printf("double decimal places\n");
    printf("MIN: %d\n", DBL_MIN_10_EXP);  // -307
    printf("MAX: %d\n", DBL_MAX_10_EXP); // 308
    printf("End double decimal places\n\n");

    printf("positive float\n");
    printf("MAX: %f\n", FLT_MAX); // 3e39
    printf("End positive float\n\n");

    printf("positive double\n");
    printf("MAX: %f\n", DBL_MAX); // 1e309
    printf("End positive double\n\n");

    // printf("positive long double\n");
    // printf("MAX: %fd\n", LDBL_MIN); // 3e309
    // printf("MAX: %lf\n", LDBL_MAX); // 3e309
    // printf("End positive double\n\n");

}


