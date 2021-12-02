#include "implementation3.h"

/*
================================================================
                     - Implementation 3 -

Cette troisième implementation est la plus simple de toutes nos
implementations. C'est donc la plus lente. Elle stocke tout les
mots du dico dans une liste puis pour tester si un mot du livre
ext correct, on parcours toute la liste.

NOTE : NE PAS UTLISER AVEC DES ORDIS LENTS !

================================================================
*/

bool recherche_mot_dans_liste(liste l, char* mot){

  /*
  l pour liste
  pl pour pointeur_liste
  */

  int indice;
  liste* pl=&l;
  if(strcmp((*pl)->val,mot)==0){
    return true;
  }
  while(pl!=NULL){
    if(strcmp(mot,(*pl)->val)==0){
      return true;
    }
    *pl=(*pl)->next;
  }
  return false;
}

void insere_tete_liste(char* nouveau_mot, liste* pl) {
  liste l = malloc(sizeof(struct cellule)); /* allocation de la cellule */
  l->val = nouveau_mot;
  l->next = *pl;
  *pl=l;
}
