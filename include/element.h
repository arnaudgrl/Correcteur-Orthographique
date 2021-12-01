#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct radix {
  char* rad;//Contient la chaine de caractere a comparer
  int estunmot;//Permet de savoir si l'on a un mot ou pas
} element;


void element_print(element x);
