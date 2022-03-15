#include <stdio.h>

// a structure is a list of declarations
// enclosed in brackets.
struct point
{
    int x;
    int y;
} x, y, z;

/* make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoints(struct point p1, struct point p2)
{
    p1.x = 10000;
    struct point result = {
        p1.x + p2.x,
        p1.y + p2.y
    };
    return result;
}

int main()
{

    struct point p1 = makepoint(40, 5);
    struct point p2 = makepoint(1, 10);

    struct point sum = addpoints(p1, p2);
    
    printf("point(%d,%d)\n", p1.x, p1.y);

printf("sum of points: point(%d,%d)\n", sum.x, sum.y);
    // struct point pt;
    // struct point maxpt = {30, 50};
    // printf("max point is (%d,%d)\n", maxpt.x, maxpt.y);

    // // nested structures
    // struct rect
    // {
    //     struct point pt1;
    //     struct point pt2;
    // };
    // struct rect r1 = {{3, 6}, {30, 51}};
    // printf("width is %d\n", r1.pt1.x - r1.pt2.x);
}