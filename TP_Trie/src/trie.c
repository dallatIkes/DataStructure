#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

TTrie newTrie()
{
    return NULL;
}

void afficherTrie_(TTrie t)
{
    printf("<");
    if (t != NULL)
    {
        afficherTrie_(t->fi);
        if (t->m)
        {
            printf(", [%c], ", t->val);
        }
        else
        {

            printf(", %c, ", t->val);
        }
        afficherTrie_(t->fr);
    }
    printf(">");
}

void afficherTrie(TTrie t)
{
    afficherTrie_(t);
    printf("\n");
}

Tnode newNode(char lettre)
{
    Tnode new;
    new.val = lettre;
    new.fi = NULL;
    new.fr = NULL;
    return new;
}

void ajouterMot(TTrie *t, char *mot)
{
    int len = strlen(mot) - 1;
    if (len >= 0)
    {
        char *new_mot = malloc(len * sizeof(char));
        strncpy(new_mot, mot + 1, len);

        if (*t == NULL)
        {
            (*t) = malloc(sizeof(Tnode));
            (*t)->val = mot[0];
            ajouterMot(&((*t)->fi), new_mot);
        }
        else
        {
            if ((*t)->val == mot[0])
            {
                ajouterMot(&((*t)->fi), new_mot);
            }
            else
            {
                ajouterMot(&((*t)->fr), mot);
            }
        }

        if (len == 0 || (*t)->m)
        {
            (*t)->m = true;
        }
        else
        {
            (*t)->m = false;
        }
    }
}