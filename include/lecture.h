#ifndef LECTURE
#define LECTURE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbreprefixe.h"
#include "arbreradix.h"
#include "implementation1.h"
#include "implementation3.h"

//Fonctions de tests de lecture sur un fichier
void decoupe_mot(char * lec);
void lecture_ligne(char* src,char* lec);

//Fonctions sur les chaines de caracteres
/*
Renvoie le mot en minuscule
*/
char* motlower(char* mot);

//Fonctions de construction d'un dictionnaire en fonction de la structure voulue


/*
Construction d'un dictionnaire a partir d'une table de hachage
*/
void construct_dico_implementation3(char * dico, liste* l);
/*
Construction d'un dictionnaire a partir d'une table de hachage
*/
void construct_dico_implementation1(char * dico, table_hachage* a);
/*
Construction d'un dictionnaire a partir d'un arbre prefixe
*/
void construct_dico_prefixe(char * dico,arbreprefixe_t* a);
/*
Construction d'un dictionnaire a partir d'un arbre radix
*/
void construct_dico_radix(char * dico, arbreradix_t* a);





//Fonctions de verification d'un texte a partir d'un dictionnaire en fonction de la structure voulue


/*
Fonction de verification d'orthographe sur une liste
*/
void verif_ortho_liste(char* dico,char * texte);
/*
Fonction de verification d'orthographe sur une table de hachage
*/
void verif_ortho_hachage(char* dico,char * texte);
/*
Fonction de verification d'orthographe sur un arbre prefixe
*/
void verif_ortho_prefixe(char* dico,char * texte);
/*
Fonction de verification d'orthographe sur un arbre radix
*/
void verif_ortho_radix(char* dico,char * texte);


#endif
