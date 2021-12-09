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

/*
Cette fonction renvoie un arbreradix initialise avec un noeud "root"
*/
arbreradix_t creer_arbre_radix();
/*
Test si un arbreradix_t est vide
*/
int arbreradix_est_vide(arbreradix_t a);
/*
Supprime de manière recursive un arbreradix_t
*/
void arbre_radix_delete(arbreradix_t a);


/*
Insère une lettre c dans un arbreradix
*/
void inserer_lettre_radix(arbreradix_t* a, char* c);
/*
Insère un mot mot dans un arbre radix a l'aide de la fonction inserer_lettre_radix
*/
void inserer_mot_radix(arbreradix_t* a, char* mot);

/*
Concatene deux chaines de caractère en s'assurant d'avoir la taille restante pour le caractère '\0'
*/
char* concatene(char* pere, char* fils);
/*
Fusionne deux noeuds d'un arbreradix_t
*/
void fusion_noeud(arbreradix_t* pere, arbreradix_t* fils);
/*
Compresse un arbreradix si celui-ci n'a qu'un fils a l'aide de fusion_noeud()
*/
void compresser(arbreradix_t* arbre);
/*
Compresse un arbre de maniere recursive a l'aide de compresser()
*/
void compresser_arbre(arbreradix_t* arbre);

/*
Renvoie 1 si prefixe est un prefixe de mot et 0 sinon
*/
int estprefixe(char* prefixe,char* mot);
/*
Renvoie l'indice dans le tableau arbre->alp si il existe un prefixe de mot dans arbre->alp,sinon -1
*/
int trouve_prefixe(arbreradix_t arbre, char* mot);
/*
renvoie mot+size,un suffixe de mot libéré du prefixe trouvé dans trouve_prefixe
*/
char* suffixe(char* mot, int size);
/*
Recherche mot dans un arbreradix_t a partir de suffixe() et de trouve_prefixe de maniere recursive
*/
int recherche_mot_radix(arbreradix_t a, char* mot);

#endif
