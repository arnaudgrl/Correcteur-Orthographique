#ifndef IMPLEMENTATION1_H
#define IMPLEMENTATION1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "implementation3.h"


typedef struct {
  liste* table;
  unsigned int capacite; /* capacité de la table */
  unsigned int nb_elements; /* nombres d'éléments dans la table */
  unsigned int capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;





//Fonctions

void insere_tete(char* mot, liste* pl);

void list_print(liste l);

int identiques(char* mot1, char* mot2);

int hash(char* mot, int taille);

int est_present(char* mot, table_hachage* ht);

table_hachage hashtable_new(unsigned int taille, unsigned int taille_initiale);

void inserer_sans_redimensionner(char* mot, table_hachage* ht);

void redimensionner(char* mot, table_hachage* ht);

void hashtable_print(table_hachage* ht);

void free_hashtable(table_hachage ht);

#endif //IMPLEMENTATION1_H
