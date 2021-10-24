#ifndef IMPLEMENTATION2
#define IMPLEMENTATION2

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
arbreprefixe_t creer_arbre();
void destruct_noeud(noeud_t* p);
int arbre_est_vide(arbreprefixe_t a);
arbreprefixe_t creer_arbre();
void parcours_infixe(arbreprefixe_t a,int espace,int n);
int indice_caractere(char c);
void inserer_lettre(arbreprefixe_t* a, char c);
void inserer_phrase(arbreprefixe_t* a, char* mot);
#endif
