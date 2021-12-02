#ifndef IMPLEMENTATION1_H
#define IMPLEMENTATION1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct element {
  char* mot;
} T;

typedef struct _cellule {
  T element;
  struct _cellule* suivante;
} cellule;
typedef cellule* liste;

typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;




//Fonctions

void element_print(T element);

void insere_tete(T element, liste* pl);

void list_print(liste l);

int identiques(T element_1,T element_2);

int hash(T element, int taille);

int est_present(T element, table_hachage* ht);

table_hachage hashtable_new(int taille);

void inserer_sans_redimensionner(T element, table_hachage* ht);

void redimensionner(T element, table_hachage* ht);

void hashtable_print(table_hachage* ht);

void free_hashtable(table_hachage* ht);

#endif //IMPLEMENTATION1_H
