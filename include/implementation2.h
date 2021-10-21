#ifndef IMPLEMENTATION2
#define IMPLEMENTATION2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET 26


typedef struct noeud{
  char lettre;
  struct noeud* alp[ALPHABET];//Chaque lettre possède 26 fils(1 fils par lettre possible)
}noeud_t,*arbreprefixe_t;



#endif
