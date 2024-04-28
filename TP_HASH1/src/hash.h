#define N 10

#include<stdio.h>
#include"title_list.h"

// Type T_ht
typedef T_liste T_ht[N];

//Initialisation de la table de hachage  
void init(T_ht ht);
// Insertion d'une clé  
void insertion(T_ht ht, int k, t_film cle);
// Recherche d'une clé 
bool recherche(T_ht ht, int k, t_film cle);
