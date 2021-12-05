#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "implementation1.h"
#include "lecture.h"
#include <assert.h>


int main(int argc, char **argv){
  /*char * dico;
  char* texte;
  dico = "FR.txt";
  texte = "a_la_recherche_du_temps_perdu.txt";
  table_hachage a = hashtable_new(10);
  table_hachage* b = &a;
  printf("%s %s\n",dico,texte);
  //construct_dico_implementation1(dico,&a);

  T element;
  element.mot = "a";
  inserer_sans_redimensionner(element.mot,&a);
  element.mot = "abaissas";
  inserer_sans_redimensionner(element.mot,&a);
  element.mot = "abaissable";
  inserer_sans_redimensionner(element.mot,&a);
  element.mot = "abaissables";
  inserer_sans_redimensionner(element.mot,&a);
  element.mot = "abaissai";
  inserer_sans_redimensionner(element.mot,&a);
  element.mot = "abaissaient";
  inserer_sans_redimensionner(element.mot,&a);

  construct_dico_implementation1(dico,&a);

  if(est_present(element,b) == 1){
    printf("Le mot %s est présent\n", element.mot);
  }
  hashtable_print(b);
  //arbre_delete(a);
  //free(dico);
  //free(texte);*/
  return EXIT_SUCCESS;
}
