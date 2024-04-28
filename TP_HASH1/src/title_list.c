#include<stdlib.h>
#include"title_list.h" 

T_liste creer_liste()
{
    return NULL;
}

T_liste ajouter_enqueue_fonc(T_liste list, t_film film)
{
    node* new = malloc(sizeof(node));
    new->val = film;
    new->next = NULL;
    if(list==NULL)
    {
        return new;
    }
    else
    {
        node* current = list;
        while (current->next!=NULL)
        {
            current = current->next;
        }
        current->next = new;
        return list;
    }
}

void afficher_liste(T_liste list)
{
    node* current = list;
    while(current!=NULL)
    {
        afficher_film(&current->val);
        current = current->next;
    }
    printf("NULL \n");
}

bool recherche_list(T_liste list, t_film film)
{
    node* current = list;
    while(current!=NULL&&equals(current->val, film))
    {
        current = current->next;
    }
    if(current==NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
} 
