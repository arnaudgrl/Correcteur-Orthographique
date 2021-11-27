#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "implementation1.h"
#include "lecture.h"
#include <assert.h>


int main(int argc, char **argv){
  char * dico;
  char* texte;
  assert(argc==3);
  dico = strdup(argv[1]);
  texte = strdup(argv[2]);
  table_hachage a = hashtable_new();
  printf("%s %s\n",dico,texte);
  construct_dico_implementation1(dico,&a);
  //verif_ortho(a,texte);
  //arbre_delete(a);
  free(dico);
  free(texte);
  return EXIT_SUCCESS;
}
