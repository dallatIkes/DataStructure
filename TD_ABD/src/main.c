#include <stdlib.h>
#include "abd.h"

int main()
{
    T_Point a = {.x=4, .y=3};
    T_Point b = {.x=2, .y=4};
    T_Point c = {.x=5, .y=5};
    T_Point d = {.x=1, .y=2};
    T_Point e = {.x=3, .y=5};
    T_Point f = {.x=6, .y=6};
    T_Point g = {.x=1, .y=6};
    T_Point h = {.x=3, .y=1};
    T_Point i = {.x=1, .y=5};

    T_ABD t = malloc(sizeof(T_node));
    t=NULL;

    insertion(&t, a);
    insertion(&t, b);
    insertion(&t, c);
    insertion(&t, d);
    insertion(&t, e);
    insertion(&t, f);
    insertion(&t, g);
    insertion(&t, h);
    insertion(&t, i);

    print_abd(t);

    printf("\n\n");

    

    T_Rectangle rect = {.H=g, .B=a};
    int_rectangle(rect, t);
}