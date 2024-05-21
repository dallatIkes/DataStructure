#include "avl.h"
#include <stdio.h>

int main()
{
    T_Tree t = arbre_vide();
    lecture_arbre(t);
    insertion_feuille(&t, 4);
    lecture_arbre(t);
    insertion_feuille(&t, 3);
    lecture_arbre(t);
    insertion_feuille(&t, 9);
    lecture_arbre(t);
    insertion_feuille(&t, 0);
    lecture_arbre(t);
    insertion_feuille(&t, 7);
    lecture_arbre(t);
    insertion_feuille(&t, 1);
    lecture_arbre(t);
    printf("Mem 1 ? : %d \n", AVL_recherche(t, 1));
    insertion_feuille(&t, 2);
    lecture_arbre(t);
    printf("Mem 2 ? : %d \n", AVL_recherche(t, 2));
    insertion_feuille(&t, 5);
    lecture_arbre(t);
    insertion_feuille(&t, 8);
    lecture_arbre(t);
    insertion_feuille(&t, 6);
    printf("%d %d %d\n", t->val, t->g->val, t->d->val);
    lecture_arbre(t);
    // insertion_feuille(&t, 3);
    // lecture_arbre(t);
    // insertion_feuille(&t, 16);
    // lecture_arbre(t);

    /*printf("\n\nRotation à droite de l'arbre : \n");
    rotation_d(&t);

    lecture_arbre(t);*/

    printf("Mem 0 ? : %d \n", AVL_recherche(t, 0));
}