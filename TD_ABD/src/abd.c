#include <stdio.h>
#include <stdlib.h>
#include "abd.h"

void insertion_x(T_ABD* T, T_Point p)
{
    if((*T)==NULL)
    {
        T_ABD new = malloc(sizeof(T_node));
        new->p = p;
        new->g = NULL;
        new->d = NULL;
        (*T) = new;
    }
    else
    {
        if(p.x < (*T)->p.x)
        {
            insertion_y(&((*T)->g), p);
        }
        else
        {
            insertion_y(&((*T)->d), p);
        }
    }
}

void insertion_y(T_ABD* T, T_Point p)
{
    if((*T)==NULL)
    {
        T_ABD new = malloc(sizeof(T_node));
        new->p = p;
        new->g = NULL;
        new->d = NULL;
        (*T) = new;
    }
    else
    {
        if(p.y < (*T)->p.y)
        {
            insertion_x(&((*T)->g), p);
        }
        else
        {
            insertion_x(&((*T)->d), p);
        }
    }
}

void insertion(T_ABD* T, T_Point p)
{
    insertion_x(T, p);
}

void print_node(T_node n)
{
    printf("(%d, %d) \n", n.p.x, n.p.y);
}

void print_abd(T_ABD T)
{
    if(T!=NULL)
    {
        print_node(*T);
        printf("gauche\n");
        print_abd(T->g);
        printf("droite\n");
        print_abd(T->d);
    }
    else
    {
        printf("Vide\n");
    }
}