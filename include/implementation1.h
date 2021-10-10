#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordonnee {
  char mot;
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

flaot hash1(T element);

bool identiques(T element_1, T element_2);

bool est_present_1(T element, table_hachage* ht);

void inserer(T element , table_hachage* ht);
