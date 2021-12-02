#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  char* rad;//Contient la chaine de caractere a comparer
  int estunmot;//Permet de savoir si l'on a un mot ou pas
} element;

typedef struct _cellule {
  elmeent radix;
  struct _cellule* suivante;//Designe la lettre suivante
  struct _cellule* dessous;//Pointe sur la lettre suivante d'un mot
} cellule;
typedef cellule* list;