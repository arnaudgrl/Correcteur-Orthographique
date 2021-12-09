#ifndef ARBREPREFIXE
#define ARBREPREFIXE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define ALPHABET 26//On definit le nombre de fils de chaque noeud de l'arbre prefixe



typedef struct noeud{
  char lettre;//Chaque noeud contient une lettre, on pourrait se passer de cette option et seulement voir si il y a un pointeur NULL sur alp[i]
  int estunmot;//Estunmot permet de savoir si au moment où l'on s'arrête on a un mot ou non
  struct noeud* alp[ALPHABET];//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreprefixe_t;



/*
Cette fonction cree un noeud d'un arbre prefixe avec un caractere et initalise estunmot a  et tout ses fils(26) a NULL
*/
noeud_t* creer_noeud(char c);
/*
Cette fonction detruit seulement un noeud d'un arbre prefixe
*/
void destruct_noeud(noeud_t* p);




/*
Cette fonction cree un arbre a partir de creer_noeud()
*/
arbreprefixe_t creer_arbre_prefixe();
/*
Cette fonction teste si un arbre prefixe est vide ou non
*/
int arbreprefixe_est_vide(arbreprefixe_t a);
/*
Fonction pour afficher l arbre prefixe(peu efficace)
*/
void parcours_infixe(arbreprefixe_t a,int espace,int n);
/*
Cette fonction detruit un arbreprefixe de manière recursive a l'aide de destruct_noeud()
*/
void arbre_prefixe_delete(arbreprefixe_t a);




/*
Renvoie l'indice d'un caractere en le passant en minuscule puis en verifiant si son indice est compris entre 'a' et 'z'
*/
int indice_caractere(char c);
/*
Insere une lettre c dans un arbreprefixe a l'aide de creer_noeud et indice caractere
*/
void inserer_lettre(arbreprefixe_t* a, char c);
/*
Insere un mot de manière recursive a l'aide de la fonction inserer_lettre()
*/
void inserer_mot(arbreprefixe_t* a, char* mot);




/*
Fonction permettant la recherche dans les fils(seulement) d'un arbre prefixe a si la lettre a est presente ou non
*/
int recherche_lettre(arbreprefixe_t a, char lettre);
/*
Fonction utilisant recherche_lettre() pour recherche dans un arbre prefixe si toutes les lettres sont presentes en s'assurant qu'il s'agit d'un mot
*/
int recherche_mot(arbreprefixe_t a, char* mot);

#endif
