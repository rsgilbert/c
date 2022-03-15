#include <stdio.h>


int run(char * person)
{
    printf("%s, run", person);
    return 3;
}


int main()
{
    typedef int Length;

    Length x = 5;
    printf("length x is %d\n", x);

    typedef char * String;

    String myname = "Joan";
    printf("my name is %s\n", myname);


    struct tnode {
        char *word;
        int count;
    };

    typedef struct tnode Treenode;
    typedef struct tnode * Treeptr;

    Treenode a;
    a.count = 3;
    a.word = "Solemn";

    Treeptr pa = &a;

    printf("def is %s with count %d\n", pa->word, a.count);


    // creates type PFI for pointer to function
    typedef int (*PFI) (char *);
    // PFI p = printf;
    // p("Yello\n");

    PFI r = run;
    r(pa->word);

    int (*rn2) (char *);
    rn2 = run;
    rn2("Jackie");
}