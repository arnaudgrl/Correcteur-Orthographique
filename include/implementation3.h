#ifndef IMPLEMENTATION3_H
#define IMPLEMENTATION3_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct cellule {
    char* mot;
    struct cellule* suivante;
};
typedef struct cellule* liste;


void list_delete(liste l);
void insere_tete_liste(char* nouveau_mot, liste* pl);
bool recherche_mot_dans_liste( liste l, char* nouv_mot);
void list_delete(liste l);
void affiche(liste l);

#endif
