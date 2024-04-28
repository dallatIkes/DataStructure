#include<stdbool.h>
#include"film.h"

// type T_liste
struct node_s {t_film val; struct node_s* next;};
typedef struct node_s node;
typedef node* T_liste;

// creation liste vide
T_liste creer_liste();
// ajout en queue de liste de element
T_liste ajouter_enqueue_fonc(T_liste list, t_film film);
// affichage itératif
void afficher_liste(T_liste list);
// recherche de elem dans list
bool recherche_list(T_liste list, t_film film);