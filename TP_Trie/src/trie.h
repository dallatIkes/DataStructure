#include <stdbool.h>

/* Définition du type Trie */

typedef struct snode
{
    char val;
    bool m;
    struct snode *fi;
    struct snode *fr;
} Tnode;

typedef Tnode *TTrie;

/* Prototypes */

TTrie newTrie();
void afficherTrie(TTrie);
void ajouterMot(TTrie *, char *);