#include "lecture.h"

int main(int argc, char **argv){
  char * dico;
  char* texte;
  assert(argc==3);
  dico = "FR.txt";
  texte = "a_la_recherche_du_temps_perdu.txt";
  arbreradix_t a = arbreradix_new();
  printf("%s %s\n",dico,texte);
  construct_dico_radix(dico,&a);
  verif_ortho_radix(a,texte);
  arbre_radix_delete(a);
  //free(dico);
  //free(texte);
  return EXIT_SUCCESS;
}
