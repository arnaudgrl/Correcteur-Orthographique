#ifndef ARBRERADIX_H
#define ARBRERADIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define ALPHABET 26

typedef struct noeud{
  char* data;
  int estunmot;
  int compteurfils;
  struct noeud** prefixe;//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreradix_t;


int estprefixe(char* prefixe,char* mot);
void inserer_motradix(arbreradix_t* radix,char* mot);
void inserer_radix(arbreradix_t* radix,char* mot);

#endif
