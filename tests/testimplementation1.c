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
  dico = "FR.txt";
  texte = "a_la_recherche_du_temps_perdu.txt";
  table_hachage a = hashtable_new(10,10);
  table_hachage* b = &a;
  printf("%s %s\n",dico,texte);


  construct_dico_implementation1(dico,&a);
  //hashtable_print(&a);
  //printf("%d\n", hash("anticonstitutionnellement",655359));
  verif_ortho_hachage(a,texte);
  return EXIT_SUCCESS;
}
