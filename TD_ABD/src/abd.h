#include <stdio.h>

typedef struct s_Point{
    int x;
    int y;
} T_Point;

typedef struct s_node T_node;

struct s_node{
    T_Point p;
    T_node* g;
    T_node* d;
};

typedef T_node* T_ABD;

/*

Représentation du rectangle

    H(x_h, y_h)
     +--------------+
     |              |
     |              |
     +--------------+
                     B(x_b, y_b)

*/

typedef struct s_Rectangle{
    T_Point H;
    T_Point B;
} T_Rectangle;

void insertion_x(T_ABD* T, T_Point p);
void insertion_y(T_ABD* T, T_Point p);
void insertion(T_ABD* T, T_Point p);

void print_node(T_node n);
void print_abd(T_ABD T);

void int_rectangle(T_Rectangle r, T_ABD T);