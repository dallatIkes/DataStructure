#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "film.h"

// Type ABR

struct node_s
{
    t_film val;
    struct node_s *left;
    struct node_s *right;
};

typedef struct node_s node;

typedef node *T_ABR;

// Prototypes

T_ABR init_ABR(t_film);
void add_leaf(T_ABR *, t_film);
bool mem(T_ABR, t_film);
void add_root(T_ABR *, t_film);
void print_ABR(T_ABR);
void printBool(bool);
void left_rot(T_ABR *);
void right_rot(T_ABR *);