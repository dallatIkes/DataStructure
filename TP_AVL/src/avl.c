#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

T_Tree arbre_vide()
{
    return NULL;
}

T_Tree creer_noeud(int i)
{
    T_Tree t = (T_node *)malloc(sizeof(T_node));
    if (t != NULL)
    {
        t->val = i;
        t->g = NULL;
        t->d = NULL;
    }
    else
    {
        printf("pbm allocation memoire!\n");
    }
    return t;
}

void rec_lecture_arbre(T_Tree T)
{
    if (T != NULL)
    {
        printf("< ");
        rec_lecture_arbre(T->g);
        printf(" , %d(%d), ", T->val, T->eq);
        rec_lecture_arbre(T->d);
        printf(">");
    }
    else
    {
        printf("<>");
    }
}

void lecture_arbre(T_Tree T)
{
    rec_lecture_arbre(T);
    printf("\n");
}

void rotation_g(T_Tree *T)
{
    // precondition : arbre de hauteur 1 avec son sous-arbre droit non vide
    T_Tree dtmp;

    // init
    dtmp = (*T)->d;

    // operation de rotation : completer
    (*T)->d = dtmp->g;
    dtmp->g = *T;

    // mise a jour des degres

    dtmp->eq++;
    (*T)->eq++;

    (*T) = dtmp;
}

void rotation_d(T_Tree *T)
{
    // precondition : arbre de hauteur 1 avec son sous-arbre gauche non vide
    T_Tree gtmp;

    // init
    gtmp = (*T)->g;

    // operation de rotation : completer
    (*T)->g = gtmp->d;
    gtmp->d = *T;

    // mise a jour des degres

    gtmp->eq--;
    (*T)->eq--;

    (*T) = gtmp;
}

void rotation_g_d(T_Tree *T)
{
    // precondition : arbre de hauteur 2 avec son sous-arbre droit puis gauche non vide
    T_Tree gtmp;
    T_Tree dtmp;

    // init
    gtmp = (*T)->g;
    dtmp = gtmp->d;

    // operation de rotation : completer
    rotation_g(&gtmp);
    rotation_d(T);

    // mise a jour des degres
    /*switch (dtmp->eq)
    {
    case -1:
        gtmp->eq = 1;
        (*T)->eq = 0;
        break;
    case 1:
        gtmp->eq = 0;
        (*T)->eq = -1;
        break;
    case 0:
        gtmp->eq = 0;
        (*T)->eq = 0;
        break;
    }
    // mise a jour du degre de la future racine
    dtmp->eq = 0;
    // mise a jour de l'arbre *T
    (*T) = dtmp;*/
}

void rotation_d_g(T_Tree *T)
{
    // precondition : arbre de hauteur 2 avec son sous-arbre gauche puis sous sous-droit non vide
    T_Tree dtmp;
    T_Tree gtmp;

    // init
    dtmp = (*T)->d;
    gtmp = dtmp->g;

    // operation de rotation : completer
    rotation_d(&dtmp);
    rotation_g(T);

    // mise a jour des degres
    /*switch (gtmp->eq)
    {
    case 1:
        dtmp->eq = -1;
        (*T)->eq = 0;
        break;
    case -1:
        dtmp->eq = 0;
        (*T)->eq = 1;
        break;
    case 0:
        dtmp->eq = 0;
        (*T)->eq = 0;
        break;
    }
    // mise a jour du degre de la future racine
    gtmp->eq = 0;
    // mise a jour de l'arbre *T
    (*T) = gtmp;*/
}

void insertion(T_Tree *T, int i, int *h)
{
    if (*T == NULL)
    { // cas de base
        (*T) = creer_noeud(i);
        if (*T == NULL)
        {
            printf("Allocation memoire impossible\n");
            (*h) = 0;
        }
        else
        {
            (*h) = 1;
        }
    }
    else
    { // HR : on sait inserer un element dans un arbre de hauteur plus petite
        if (i < ((*T)->val))
        {
            insertion(&((*T)->g), i, h);
            if (*h == 1)
            {
                switch (((*T)->eq))
                {
                case -1:
                    ((*T)->eq)++;
                    *h = 0;
                    break;
                case 0:
                    ((*T)->eq)++;
                    *h = 1;
                    break;
                case 1:
                    if ((((*T)->g)->eq) == 1)
                    {
                        // rotation simple vers la droite
                        rotation_d(T);
                    }
                    else
                    {
                        // rotation double
                        rotation_g_d(T);
                    }
                    *h = 0;
                    break;
                }
            }
        }
        else
        {
            // completer le cas d'insertion dans le sous-arbre droit
            insertion(&((*T)->d), i, h);
            if (*h == 1)
            {
                switch (((*T)->eq))
                {
                case 1:
                    ((*T)->eq)--;
                    *h = 0;
                    break;
                case 0:
                    ((*T)->eq)--;
                    *h = 1;
                    break;
                case -1:
                    if ((((*T)->d)->eq) == -1)
                    {
                        // rotation simple vers la gauche
                        rotation_g(T);
                    }
                    else
                    {
                        // rotation double
                        rotation_d_g(T);
                    }
                    *h = 0;
                    break;
                }
            }
        }
    }
}

void insertion_feuille(T_Tree *T, int i)
{
    int h = 0;
    insertion(T, i, &h);
}

bool AVL_recherche(T_Tree T, int i)
{
    if (T == NULL)
    {
        return false;
    }
    else
    {
        if (T->val == i)
        {
            return true;
        }
        else
        {
            if (i < T->val)
            {
                return AVL_recherche(T->g, i);
            }
            else
            {
                return AVL_recherche(T->d, i);
            }
        }
    }
}