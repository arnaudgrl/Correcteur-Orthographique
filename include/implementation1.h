#ifndef IMPLEMENTATION1_H
#define IMPLEMENTATION1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "implementation3.h"

typedef char* T;

typedef struct {
  liste* table;
  unsigned int capacite; /* capacité de la table */
  unsigned int nb_elements; /* nombres d'éléments dans la table */
  unsigned int capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;





//Fonctions


/*
Cette fonction renvoie 1 si deux string sont identiques, 0 sinon
*/
bool identiques(char* mot1, char* mot2);

/*
Renvoie le hashcode d'une chaine de caractere mot avec pour borne taille
*/
int hash(char* mot, int taille);

/*
Renvoie une table de hachage de taille initiale capacite initiale et de taille taille qui peut etre change plus tard avec redimensionner()
*/
table_hachage hashtable_new(unsigned int capacite,int capacite_initiale);
/*
Libere une table de hachage
*/
void free_hashtable(table_hachage ht);

/*
Affiche une table de hachage
*/
void hashtable_print(table_hachage ht);




/*
Renvoie 1 si un mot est present dans une table de hachage,0 sinon
*/
int est_present(char* mot, table_hachage* ht);

/*
Insere un mot dans une table de hachage en la redimensionnant si necessaire
*/
void inserer_sans_redimensionner(char* mot, table_hachage* ht);
/*
Redimensionne une table de hachage puis insere le mot mot
*/
void redimensionner(char* mot, table_hachage* ht);
/*
Insere un mot dans une table de hachage en la redimensionnant si necessaire et en verifiant si le mot est present dans la table ou non
*/
void inserer_sans_redimensionner_conflits(char* mot, table_hachage* ht);
/*
Redimensionne une table de hachage puis insere le mot mot en gerant les conflits
*/
void redimensionner_conflits(char* mot, table_hachage* ht);




#endif //IMPLEMENTATION1_H
