#ifndef IMPLEMENTATION2
#define IMPLEMENTATION2

#include <stdio.h>
#include <stdlib.h>
#define ALPHABET 26


typedef struct noeud{
  char c;
  struct noeud* alp[ALPHABET];//Chaque lettre possède 26 fils(1 fils par lettre possible)
}node_t,*arbresuffixe;



#endif
