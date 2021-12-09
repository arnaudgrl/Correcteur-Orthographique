#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arbreprefixe.h"
#include "lecture.h"
#include <assert.h>


int main(int argc, char **argv){
  char * dico;
  char* texte;
  assert(argc==3);
  dico = strdup(argv[1]);
  texte = strdup(argv[2]);
  arbreprefixe_t a = creer_arbre_prefixe();
  printf("%s %s\n",dico,texte);
  construct_dico_prefixe(dico,&a);
  verif_ortho_prefixe(dico,texte);
  arbre_prefixe_delete(a);
  free(dico);
  free(texte);
  return EXIT_SUCCESS;
}
