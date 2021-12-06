#ifndef ARBREPREFIXE2
#define ARBREPREFIXE2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#define ALPHABET 26



typedef struct noeud_radix_t{
  char* radix;
  int estunmot;
  int compteurfils;
  struct noeud_radix_t** alp;//On crée une structure dynamique de fils pour optimiser la mémoire
}noeud_radix_t,*arbreradix_t;


noeud_radix_t* creer_noeud_radix(char* c);
void destruct_noeud_radix(noeud_radix_t* p);


arbreradix_t arbreradix_new();
int arbreradix_est_vide(arbreradix_t a);
void parcours_infixe_radix(arbreradix_t a,int espace,int n);
void arbre_radix_delete(arbreradix_t a);

int indice_caractere_radix(char c);
void inserer_lettre_radix(arbreradix_t* a, char* c);
void inserer_mot_radix(arbreradix_t* a, char* mot);

void compresser(arbreradix_t* arbre);
void fusion_noeud(arbreradix_t* pere, arbreradix_t* fils);
void concatener_radix(char* pere,char* fils);
void compresser_arbre(arbreradix_t* arbre);

int estprefixe(char* prefixe,char* mot);
int trouve_prefixe(arbreradix_t arbre, char* mot);
char* suffixe(char* mot, int size);
int recherche_mot_radix(arbreradix_t a, char* mot);

#endif
