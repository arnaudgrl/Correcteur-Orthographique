#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "implementation3.h"
#include "implementation1.h"
#include "lecture.h"
#include <assert.h>


int main(int argc, char **argv){
  char * dico;
  char* texte;
  dico = "FR.txt";
  texte = "a_la_recherche_du_temps_perdu.txt";
  liste l = calloc(1,sizeof(struct cellule));
  printf("%s %s\n",dico,texte);


  construct_dico_implementation3(dico,&l);
  //list_print(l);


  verif_ortho_liste(dico,texte);
  list_delete(l);

  return EXIT_SUCCESS;
}
