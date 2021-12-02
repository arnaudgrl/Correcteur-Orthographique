#ifndef ARBREPREFIXE2
#define ARBREPREFIXE2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "element.h"
#define ALPHABET 26



typedef struct noeud{
  char* radix;
  int compteurfils;
  struct noeud** alp;//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreprefixe_t2;


noeud_t* creer_noeud(char* c);
void destruct_noeud(noeud_t* p);


arbreprefixe_t2 creer_arbre();
int arbreprefixe_est_vide(arbreprefixe_t2 a);
void parcours_infixe(arbreprefixe_t2 a,int espace,int n);
void arbre_delete(arbreprefixe_t2 a);

int indice_caractere(char c);
void inserer_lettre(arbreprefixe_t2* a, char c);
void inserer_phrase(arbreprefixe_t2* a, char* mot);
void compresser(arbreprefixe_t2);

int estprefixe(char* prefixe,char* mot);
int recherche_lettre(arbreprefixe_t2 a, char lettre);
int recherche_mot(arbreprefixe_t2 a, char* mot);

#endif
