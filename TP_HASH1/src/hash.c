#include"hash.h"

void init(T_ht ht)
{
    for(int i=0; i<N; i++)
    {
        ht[i] = creer_liste();
    }
}

void afficher_ht(T_ht ht)
{
    for(int i=0; i<N; i++)
    {
        afficher_liste(ht[i]);
    }
}

void insertion(T_ht ht, int k, t_film cle)
{
    ht[k] = ajouter_enqueue_fonc(ht[k], cle);
}

bool recherche(T_ht ht, int k, t_film cle)
{
    return recherche_list(ht[k], cle);
}

/*int main()
{
    T_ht ht;
    init(ht);
    insertion(ht, 0, 12);
    insertion(ht, 3, 4);
    insertion(ht, 3, 6);
    printf("\n");
    afficher_ht(ht);
    printf("\n");
    if(recherche(ht, 1, 12))
    {
        printf("12 en 1\n");
    }
    else
    {
        printf("12 pas en 1\n");
    }
    if(recherche(ht, 3, 4))
    {
        printf("4 en 3\n");
    }
    else
    {
        printf("4 pas en 3\n");
    }
}*/