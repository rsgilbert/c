#include <stdio.h>
#define NKEYS 1000

struct key
{
    char *word;
    int count;
} keytab[] = {
    {"int", 0}, {"for", 0}, {"struct", 0}};

int
main()
{
    keytab[0].count = 3;
    keytab[1].count = 5;
    printf("for count %d\n", keytab[1].count);
    printf("key size %d, array size %d no of els %d\n", sizeof (struct key), sizeof keytab, sizeof(keytab)/sizeof(struct key));
}
