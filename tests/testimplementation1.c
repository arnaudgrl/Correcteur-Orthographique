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


  construct_dico_implementation1(dico,b);
  //printf("%d\n", hash(element, a.capacite) );
  //element.mot = "abaissa";
  //printf("%d\n", hash(element, a.capacite) );
  // if(est_present(element,&a) == 1){
  //   printf("Le mot %s est présent\n", element.mot);
  // }
  //hashtable_print(b);
  T element2;
  element2.mot = "des";
  printf("%d\n", hash(element2, a.capacite) );
  //list_print(a.table[4]);
  if(est_present(element2,&a) == 1){
     printf("Le mot %s est présent\n", element2.mot);
  }
  // printf("%d\n", a.capacite );
  // printf("%d\n", a.capacite_initiale);
  // printf("%d\n", identiques(element,element2) );
  //list_print(a.table[7]);
  verif_ortho_hachage(a,texte);
  free_hashtable(a);
  //free(dico);
  //free(texte);
  return EXIT_SUCCESS;
}
