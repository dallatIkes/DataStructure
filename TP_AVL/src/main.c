#include "avl.h"
#include <stdio.h>

int main()
{
    T_Tree t = arbre_vide();
    lecture_arbre(t);
    insertion_feuille(&t, 5);
    lecture_arbre(t);
    insertion_feuille(&t, 4);
    lecture_arbre(t);
    insertion_feuille(&t, 7);
    lecture_arbre(t);
    insertion_feuille(&t, 2);
    lecture_arbre(t);
    insertion_feuille(&t, 12);
    lecture_arbre(t);
    insertion_feuille(&t, 6);
    lecture_arbre(t);
    insertion_feuille(&t, 13);
    lecture_arbre(t);
    insertion_feuille(&t, 1);
    lecture_arbre(t);
    insertion_feuille(&t, 0);
    lecture_arbre(t);
    insertion_feuille(&t, 69);
    lecture_arbre(t);
    insertion_feuille(&t, 3);
    lecture_arbre(t);
    insertion_feuille(&t, 16);
    lecture_arbre(t);

    /*printf("\n\nRotation à droite de l'arbre : \n");
    rotation_d(&t);

    lecture_arbre(t);*/
}