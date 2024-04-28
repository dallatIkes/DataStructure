#include"liste.h"
#include<stdio.h>

int main()
{
    T_liste l = creer_liste();
    afficher_liste(l);
    ajout_entete_liste(&l, 2);
    ajout_entete_liste(&l, 6);
    ajout_entete_liste(&l, 7);
    l = ajouter_enqueue_fonc(l, 12);
    afficher_liste(l);

    afficher_liste(inversion_rec_term(l, NULL));
    afficher_liste(inversion_rec_env(l));

    printf("\n\n12?:%d\n16?:%d \n", (int)recherche_list(l, 12), (int)recherche_list(l, 16));

    /*afficher_inv_liste(l);
    afficher_dir_liste(ajouter_entete_fonc(l, 5));
    //inv_mis_liste(&l);
    afficher_liste(l);
    printf("taille de la liste : %d \n", long_env(l));
    printf("taille de la liste : %d \n", long_ter(l, 0));*/
}