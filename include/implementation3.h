#ifndef IMPLEMENTATION3_H
#define IMPLEMENTATION3_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct _cellule {
  char* mot;
  struct _cellule* suivante;
} cellule;
typedef cellule* liste;


void insere_tete_liste(char* nouveau_mot, liste* pl);
bool recherche_mot_dans_liste( liste l, char* mot);
void list_delete(liste l);
void insere_tete(char* mot, liste* pl);

#endif
