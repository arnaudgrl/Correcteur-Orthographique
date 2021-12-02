#ifndef IMPLEMENTATION3_H
#define IMPLEMENTATION3_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


struct cellule {
    char* val;
    struct cellule* next;
};
typedef struct cellule* liste;

void insere_tete_liste(char* nouveau_mot, liste* pl);
bool recherche_liste(int valeur, liste l);

#endif
