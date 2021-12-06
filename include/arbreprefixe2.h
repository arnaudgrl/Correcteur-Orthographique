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
}noeud_radix_t,*arbreprefixe_t2;


noeud_radix_t* creer_noeud_radix(char* c);
void destruct_noeud_radix(noeud_radix_t* p);


arbreradix_t creer_arbre_radix();
int arbreradix_est_vide(arbreradix_t a);
void parcours_infixe_radix(arbreradix_t a,int espace,int n);
void arbre_radix_delete(arbreradix_t a);

int indice_caractere_radix(char c);
void inserer_lettre_radix(arbreradix_t* a, char c);
void inserer_phrase_radix(arbreradix_t* a, char* mot);
void compresser(arbreradix_t);

int estprefixe(char* prefixe,char* mot);
int recherche_lettre_radix(arbreradix_t a, char lettre);
int recherche_mot_radix(arbreradix_t a, char* mot);

#endif
