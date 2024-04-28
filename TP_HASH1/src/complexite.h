#ifndef COMPLEXITE_H
#define COMPLEXITE_H


extern size_t compteur_memoire;
extern size_t compteur_op_elementaire;

void initialiser_comp_op_elementaire();
void *allouer(size_t taille);
void operation_elementaire();
void demarrer_chrono();
void arreter_chrono();
long int temps_chrono();

void afficher_resultat_complexite();
#endif
