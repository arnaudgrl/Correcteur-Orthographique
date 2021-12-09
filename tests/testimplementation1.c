#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "implementation1.h"
#include "lecture.h"
#include <assert.h>


int main(int argc, char **argv){
  char* texte;
  char* dico;
  texte = "a_la_recherche_du_temps_perdu.txt";
  dico = "FR.txt";
  //table_hachage a = hashtable_new(200,200);
  printf("%s\n",texte);
  //construct_dico_implementation1(dico,&a);
  //hashtable_print(&a);
  verif_ortho_hachage(dico,texte);
  //free_hashtable(&a);
  // printf("%d\n", hash("anticonstitutionnellement",a.capacite) );
  // printf("%d\n", hash("opina",a.capacite) );
  // printf("%d\n", est_present("anticonstitutionnellement",a));

  return EXIT_SUCCESS;

}
