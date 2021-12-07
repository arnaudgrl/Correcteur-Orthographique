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
  liste l = malloc(sizeof(struct cellule));
  printf("%s %s\n",dico,texte);


  construct_dico_implementation3(dico,&l);
  //list_print(l);


  verif_ortho_liste(l,texte);
  list_delete(l);

  return EXIT_SUCCESS;
}
//
// int main(int argc, char **argv){
//   char * dico;
//   char* texte;
//   dico = "FR.txt";
//   texte = "a_la_recherche_du_temps_perdu.txt";
//   liste l = malloc(sizeof(struct cellule));
//   construct_dico_implementation3(dico,&l);
//   if(recherche_mot_dans_liste(l,"arbre")){
//     printf("le mot est présent dans la liste\n");
//   }
//   //affiche(l);
//   //list_delete(l);
//   return 0;
//}
