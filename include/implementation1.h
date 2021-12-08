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

void list_delete(liste l);

void insere_tete(char* mot, liste* pl);

void list_print(liste l);

bool identiques(T mot1, T mot2);

void insere_tete(T nouv, liste* pl);

int hash(char* mot, int taille);

int est_present(T mot, table_hachage* ht);

table_hachage hashtable_new(unsigned int capacite,int capacite_initiale);

void inserer_sans_redimensionner(T mot, table_hachage* ht);

void redimensionner(T mot, table_hachage* ht);

void hashtable_print(table_hachage* ht);

void free_hashtable(table_hachage ht);

#endif //IMPLEMENTATION1_H
