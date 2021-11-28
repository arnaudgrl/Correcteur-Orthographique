#ifndef ARBRERADIX_H
#define ARBRERADIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define ALPHABET 26

typedef struct noeud{
  char data;
  struct noeud* alp[ALPHABET];//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreradix_t;

#endif
