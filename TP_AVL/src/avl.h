/* En-tete de arbre
   ----------------
   objectif : définir le TAA arbre
*/

#ifndef AVL_H
#define AVL_H
#define max 20

#include <stdbool.h>

/* type noeud incomplet */
typedef struct s_node T_node;

/* type pointeur sur noeud */
typedef T_node *T_Tree;

/* type noeud complet */
struct s_node
{
    int val;
    T_Tree g, d;
    int eq; // dans -1 0 1
};

/* Prototypes */
T_Tree arbre_vide();
void insertion_feuille(T_Tree *T, int i);
bool AVL_recherche(T_Tree T, int i);
void lecture_arbre(T_Tree T);
void rotation_g(T_Tree *T);
void rotation_d(T_Tree *T);
#endif