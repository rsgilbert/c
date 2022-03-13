#include <stdio.h>
#include <string.h>

void sortlist(char *list[])
{
    char *ptr0, *ptr1;
    ptr0 = list[0];
    ptr1 = list[1];
    if(strcmp(ptr0, ptr1) > 0)
    {
        list[0] = ptr1;
        list[1] = ptr0;
    }
}

int main()
{
    char *ptrs[2];
    char name0[] = "Zane";
    char *name1 = "Simon";

    ptrs[0] = name0;
    ptrs[1] = name1;

    sortlist(ptrs);

    printf("name 0 %s\n", ptrs[0]);
    printf("name 1 %s\n", ptrs[1]);

}