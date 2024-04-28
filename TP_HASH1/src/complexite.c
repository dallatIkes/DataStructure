#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "complexite.h"

size_t compteur_memoire;
size_t compteur_op_elementaire;
struct timeval compteur_start, compteur_stop;

void *allouer(size_t taille)
{
	compteur_memoire += taille;
	return malloc(taille);
}

void initialiser_comp_op_elementaire(){
	compteur_op_elementaire = 0;
}
void operation_elementaire()
{
	compteur_op_elementaire++;
}

void demarrer_chrono()
{
	gettimeofday(&compteur_start, NULL);
}

void arreter_chrono()
{
	gettimeofday(&compteur_stop, NULL);
}

long int temps_chrono()
{
	return (compteur_stop.tv_sec - compteur_start.tv_sec)*1000000 + compteur_stop.tv_usec - compteur_start.tv_usec;
}

void afficher_resultat_complexite()
{

	long int delta = temps_chrono();
	long int usec = delta %1000;
	long int msec = (delta/1000)%1000;
	long int sec = delta/1000000;

	printf("Temps écoulé : (s:ms:us) %ld:%ld:%ld\n", sec, msec, usec);
	printf("Nb opérations élémentaires : %lu\n", compteur_op_elementaire);

	size_t o = compteur_memoire%1024;
	size_t ko = (compteur_memoire/1024)%1024;
	size_t Mo = compteur_memoire/(1024*1024);
	printf("Memoire occupée : %lu Mio + %lu kio + %lu o\n", Mo, ko, o);
}
