#include "abr.h"

T_ABR init_ABR(t_film elt)
{
    T_ABR new = malloc(sizeof(node));
    new->val = elt;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void add_leaf(T_ABR *t, t_film elt)
{
    if (*t == NULL)
    {
        *t = init_ABR(elt);
    }
    else
    {
        if (elt.num < (*t)->val.num)
        {
            add_leaf(&((*t)->left), elt);
        }
        else
        {
            add_leaf(&((*t)->right), elt);
        }
    }
}

void print_ABR_(T_ABR t)
{
    if (t != NULL)
    {
        printf("<%d, ", t->val);
        print_ABR_(t->left);
        printf(", ");
        print_ABR_(t->right);
        printf(">");
    }
    else
    {
        printf("V");
    }
}

void print_ABR(T_ABR t)
{
    print_ABR_(t);
    printf("\n");
}

bool mem(T_ABR t, t_film elt)
{
    if (t == NULL)
    {
        return false;
    }
    else if (equals(t->val, elt))
    {
        return true;
    }
    else
    {
        if (elt.num < t->val.num)
        {
            return mem(t->left, elt);
        }
        else
        {
            return mem(t->right, elt);
        }
    }
}

void printBool(bool p)
{
    if (p)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

void left_rot(T_ABR *t)
{
    if ((*t) != NULL && (*t)->right != NULL)
    {
        T_ABR temp = (*t)->right;
        (*t)->right = temp->left;
        temp->left = (*t);
        (*t) = temp;
    }
    else
    {
        printf("Erreur : Préconditions non vérifiées! \n");
    }
}

void right_rot(T_ABR *t)
{
    if ((*t) != NULL && (*t)->left != NULL)
    {
        T_ABR temp = (*t)->left;
        (*t)->left = temp->right;
        temp->right = (*t);
        (*t) = temp;
    }
    else
    {
        printf("Erreur : Préconditions non vérifiées! \n");
    }
}

void add_root(T_ABR *t, t_film elt)
{
    if (*t == NULL)
    {
        *t = init_ABR(elt);
    }
    else
    {
        if (elt.num < (*t)->val.num)
        {
            add_root(&((*t)->left), elt);
            right_rot(t);
        }
        else
        {
            add_root(&((*t)->right), elt);
            left_rot(t);
        }
    }
}