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
  liste *pl = malloc(sizeof(*pl));
  pl=&l;
  if((*pl)->element.mot==mot){
    return true;
  }
  while(pl!=NULL){
    if(mot==(*pl)->element.mot){
      free(pl);
      return true;
    }
    *pl=(*pl)->suivante;
  }
  free(pl);
  return false;
}

void insere_tete_liste(char* nouveau_mot, liste* pl) {
  liste l = malloc(sizeof(*l)); /* allocation de la cellule */
  T element;
  element.mot = nouveau_mot;
  l->element = element;
  l->suivante = *pl;
  *pl=l;
}

void list_delete(liste l){
  liste p = l;
  while(p != NULL){
    l = p->suivante;
    free(p);
    p=l;
  }
}

void insere_tete(T element, liste* pl){
  //printf("%s\n",element.mot );
  liste p=calloc(1,sizeof(*p));
  if(NULL==p){
    fprintf(stderr,"Fatal : Unable to allocate new list link.\n");
  }
  p->element=element;
  p->suivante = *pl;
  *pl=p;
}
