#ifndef ARBREPREFIXE
#define ARBREPREFIXE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET 26


typedef struct noeud{
  char lettre;
  struct noeud* alp[ALPHABET];//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreprefixe_t;


noeud_t* creer_noeud(char c);
void destruct_noeud(noeud_t* p);


arbreprefixe_t creer_arbre();
int arbre_est_vide(arbreprefixe_t a);
void parcours_infixe(arbreprefixe_t a,int espace,int n);
void arbre_delete(arbreprefixe_t a);

int indice_caractere(char c);
void inserer_lettre(arbreprefixe_t* a, char c);
void inserer_phrase(arbreprefixe_t* a, char* mot);

int recherche_lettre(arbreprefixe_t a, char lettre);
int recherche_mot(arbreprefixe_t a, char* mot);

#endif
