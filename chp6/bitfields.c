#include <stdio.h>

int main()
{
    struct person_status {
        unsigned int is_healthy: 1;
        unsigned int is_awake: 1;
        unsigned int is_married: 1;
    };

    struct person_status mshai_flags;

    mshai_flags.is_healthy = 1;
    mshai_flags.is_awake = 0;
    mshai_flags.is_married = 0;

    printf("Msai is dateable: %d\n", mshai_flags.is_healthy && !mshai_flags.is_married);

}