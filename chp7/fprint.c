#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] = "testfile.txt";
    fp = fopen(filename, "r");

    char disease[100];
    int infected;
    fscanf(fp, "%s %d", disease, &infected);
    printf("file had disease: %s , infected: %d\n", disease, infected);

    FILE *fpwrite = fopen("output.txt", "w");
    int c = fprintf(fpwrite, "PRINTED: %d sick of %s\n", infected, disease);
    printf("Wrote %d\n", c);
}