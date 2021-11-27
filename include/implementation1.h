#ifndef IMPLEMENTATION1_H
#define IMPLEMENTATION1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// typedef struct coordonnee {
//   char mot;
// } T;


typedef struct _cellule {
  char* mot;
  struct _cellule* next;
} cellule;
typedef cellule* liste;


typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;



//Fonctions

unsigned int hash1(char* mot);

bool identiques(char* mot1, char* mot2);

bool est_present_1(char* mot, table_hachage* ht);

void inserer(char* mot, liste* pl);

void list_print(liste l);

table_hachage hashtable_new(int taille);

table_hachage redimensionner(table_hachage ht);

void inserer_sans_redimensionner(char* mot, table_hachage* ht);

void hashtable_print(table_hachage ht);

#endif //IMPLEMENTATION1_H
