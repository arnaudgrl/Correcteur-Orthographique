#include "implementation2.h"



int main(int argc, char **argv){
  char * dico;
  char* texte;
  assert(argc==3);
  dico = strdup(argv[1]);
  texte = strdup(argv[2]);
  arbreprefixe_t a = creer_arbre();
  construct_dico(dico,&a);

  return EXIT_SUCCESS;
}
