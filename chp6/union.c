#include <stdio.h>

union performance {
    char *sperf;
    double percperf;
    int iperf;
};

void printperformance(union performance p, char * type) 
{
    if(type == "INT") 
    {
        printf("%d/10\n", p.iperf);
    }
    else if(type == "PERC")
    {
        printf("%.1f%%\n", p.percperf);
    }
    else 
    {
        printf("%s\n", p.sperf);
    }

}
int main()
{
    union u_tag
    {
        int ival;
        float fval;
        char *sval;
    } U;
    u.ival = 4;
    printf("i val is %d\n", u.ival);

    u.fval = 20.52;
    printf("again i val is %d\n", u.ival); // undefined
    printf("f val is %f\n", u.fval);

    union performance myperf;
    myperf.percperf = 25;
    printperformance(myperf, "PERC");
    myperf.iperf = 8;
    printperformance(myperf, "INT");
    myperf.sperf = "EXCELENT";    
    printperformance(myperf, "WHO KNOWS");
    
}
