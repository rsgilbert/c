#include <stdio.h>
#include <math.h>
#define MAXLINE  1000


int btoi(char s[]);
void itob(int n, char s[]);
int createSet();
void printSet(int set);
int addMember(char mem, int set);
int setUnion(int set1, int set2);
int setIntersection(int set1, int set2);
int universalSet();
int setComplement(int set);

int main()
{
    int set = createSet("AG"); 
    printSet(set); // 1000001
    set = addMember('D', set);
    printSet(set); // 1001001
    set = addMember('F', set);
    printSet(set); // 1101001
    int setU = setUnion(createSet("ABC"), createSet("BCDE")); 
    printSet(setU); // 11111
    int setInter = setIntersection(createSet("DAB"), createSet("BDGRE"));
    printSet(setInter); // 1010
    printSet(universalSet());
    int setCompl = setComplement(createSet("ABCEGHI"));
    printSet(setCompl);

}

/**
 * Creates a set
 */
int createSet(char s[])
{
    int i = 0;
    int set = 0;
    while(s[i] != 0)
    {
        set = addMember(s[i], set);
        i++;
    }
    return set;
}

/** 
 * Prints binary representation of set 
 */
void printSet(int set)
{
    char result[MAXLINE];
    itob(set, result);
    printf("%s\n", result);
}

/*
* Add a member to a set. 
* Returns a new set containing the elements in `set` as well as the given member.
*/
int addMember(char mem, int set)
{
    if(mem < 'A' || mem > 'Z')
    {
        return set;
    }
    int pos = mem - 'A';
    int toUse = pow(2, pos);
    set = set | toUse;
    return set;
}

/**
 * Returns a set that is a union of two sets 
 */
int setUnion(int set1, int set2)
{
    return set1 | set2;
}

/* Returns a set that is the intersection of two sets  */
int setIntersection(int set1, int set2)
{
    return set1 & set2;
}

/* Returns a set that has those members that not in `set`. */
int setComplement(int set)
{
    return universalSet() ^ set;
}

int universalSet()
{
    return pow(2, 26) - 1;
}

/** Convert binary to decimal integer */
int btoi(char s[])
{
    int result = 0;
    int i = 0;
    while(s[i] != 0)
    {
        if(s[i] != '0' && s[i] != '1')
            return -1;
        result *= 2;
        result += s[i] - '0';
        i++;
    }
    return result;
}

/** convert decimal integer to binary */
void itob(int n, char s[])
{
    if(n == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return;
    };
    if(n < 0) 
    {
        s[0] = '-';
        s[1] = '1';
        s[2] = 0;
        return;
    }
    int pos = log2(n);
    s[pos + 1] = 0;
    while(pos != 0)
    {
        s[pos] = '0' + n % 2;
        n = n / 2;
        pos--;
    }
    // pos will be 0
    s[pos] = '1';
}