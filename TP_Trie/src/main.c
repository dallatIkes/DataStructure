#include "trie.h"

int main()
{
    TTrie t = newTrie();
    ajouterMot(&t, "bonjour");
    afficherTrie(t);
    ajouterMot(&t, "bon");
    afficherTrie(t);
    ajouterMot(&t, "salut");
    afficherTrie(t);
    ajouterMot(&t, "salutations");
    afficherTrie(t);
}