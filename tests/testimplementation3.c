#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "implementation3.h"
#include "implementation1.h"
#include "lecture.h"
#include <assert.h>

//
// int main(int argc, char **argv){
//   char * dico;
//   char* texte;
//   dico = "FR.txt";
//   texte = "a_la_recherche_du_temps_perdu.txt";
//   liste_t l = malloc(sizeof(liste_t));
//   printf("%s %s\n",dico,texte);
//
//
//   construct_dico_implementation3(dico,l);
//
//
//   verif_ortho_liste(l,texte);
//
//   return EXIT_SUCCESS;
// }

int main(){
  liste l = malloc(sizeof(*l));
  T element;
  element.mot = "arbre";
  insere_tete(element, &l);
  if(recherche_mot_dans_liste(l,"abre")){
    printf("le mot est présent dans la liste\n");
  }
  list_delete(l);
  return 0;

}
