/***
 * compilation :
 *		gcc -O3 -Wall -Wextra -Wconversion -ansi -Wpedantic -std=c11  *.c -o TestABR
 *
 * extraction des donnees : for l in 10 1000 2000 4000 10000 20000 40000 100000 200000 400000 1000000; do echo $l; head -n $l ~/tmp/title.basics.tsv | sort -R > title_$l.tsv; done
 *
 * generation des résutats :
 *		for l in 10 1000 2000 4000 10000 20000 40000 100000 200000 400000 1000000; do echo $l; ./TestABR title_$l.tsv | tee -a resultat_abr_$l.txt; done
 *
 */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "liste_chainee.h"
#include "complexite.h"
#include "arbre.h"






int main(int argc, char *argv[])
// argc est le nombre d'argument et vaut au moins 1
// le premier argument étant le chemin vers le nom de l'exécutable
// argv[] est le tableau des arguments
{
	if (argc-1 != 1)
	{
		fprintf(stderr, "Usage %s <fichier.tsv>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* fd=fopen(argv[1], "r");
	char ligne[4096];

	// Déclaration des structures

	T_Tree t;
	// cles = tableau des numéros des films
	// sauvegarde des clés dans ce tableau pour faire un tirage aléatoire d'une 50 aines de clés
	// puis effectuer une moyenne d'une nombre d'opérations fondamentales pour la recherche de ces 50 clés
	int * cles;



	//initialisation d'un pointeur sur un film
	t_film* pfilm = NULL;
	// i prochaine case libre du tableau
	int i= 0;

	init_Tree(&t);

	cles = (int *) malloc(100000*sizeof(int)); // à modifier en fonction de la taille de la donnée


	/*********************************************************************/
  /************************* Phase d'insertion *************************/
	/*********************************************************************/
	demarrer_chrono();


	// la partie suivante lit chaque ligne du fichier tsv pour extraire les informations utiles
	// à la création de films
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
	arreter_chrono();

	long int temps_cumul = temps_chrono();

	long int usec = temps_cumul %1000;
	long int msec = (temps_cumul/1000)%1000;
	long int sec = temps_cumul/1000000;

	printf("Temps de chargement de %d elements dans Tree : (s:ms:us) %ld:%ld:%ld\n", i, sec, msec, usec);


  /*********************************************************************/
	/*********************** Test de recherche **************************/
	/*********************************************************************/
	//89119
	initialiser_comp_op_elementaire();
	demarrer_chrono();
  bool trouve = recherche(t, 89119);
	arreter_chrono();
	temps_cumul = temps_chrono();

	usec = temps_cumul %1000;
	msec = (temps_cumul/1000)%1000;
	sec = temps_cumul/1000000;
	printf("Temps de recherche de 89119, trouve ? %d: (s:ms:us) %ld:%ld:%ld\n", trouve,sec, msec, usec);
	printf("Nb opérations élémentaires : %lu\n", compteur_op_elementaire);


	return EXIT_SUCCESS;
}
