#include"hash.h"

int main(int argc, char* argv[])
{
    T_ht ht;
    init(ht);

    FILE* fd=fopen(argv[1], "r");
	char ligne[4096];

    int* cles = (int *) malloc(4000*sizeof(int));
    t_film* pfilm = NULL;

    while (fgets(ligne, sizeof(ligne), fd)!=NULL)
	{
		// creation d'un film à partir d'une ligne du fichier tsv et récupération d'un pointeur sur ce film.
		pfilm = creer_film(ligne);
		// insertion de l'adresse du film dans la structure
		if (pfilm!=NULL){
			insertion_feuille_mis(&t, pfilm);
			// récupération de la clé
			cles[i]=pfilm->num;
			// mise à jour de la prochaine case pouvant recevoir une clé
			i++;
		}
	}

    insertion(ht, 0, !pfilm);
}