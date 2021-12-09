#ifndef IMPLEMENTATION3_H
#define IMPLEMENTATION3_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
Type de structure de mots chainés pour pouvoir ajouter des noeuds a chaque ajout de mot du dictionnaire
*/
struct cellule {
    char mot[30];
    struct cellule* suivante;
};
typedef struct cellule* liste;
/*
Cette fonction permet de creer une nouvelle liste avec allocation d'un noeud
*/
liste list_new();
/*
Fonction de deletion d'une liste
*/
void list_delete(liste l);
/*
Fonction d'affichage d'une liste avec indice de l'element dans la liste
*/
void list_print(liste l);
/*
Fonction d'insertion en tete dans la liste
*/
void insere_tete(char* nouveau_mot, liste* pl);
/*
Fonction de recherche de mot dans une liste
*/
bool recherche_mot_dans_liste( liste l, char* nouv_mot);

#endif
