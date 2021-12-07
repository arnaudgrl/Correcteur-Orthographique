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

bool recherche_mot_dans_liste(liste l, char* nouv_mot){

  liste p=l;
  while(p->suivante!=NULL){
    //printf("%s comparé à %s\n", nouv_mot, p->mot );

    if (strcmp(nouv_mot, p->mot)==0) {

      return true;
    }
    p = p->suivante;
  }
  return false;
}

void insere_tete_liste(char* nouveau_mot, liste* pl) {
  liste l = malloc(sizeof(*l)); /* allocation de la cellule */
  l->mot = nouveau_mot;
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


void affiche(liste l){
  liste p;
  for ( p=l; !(p==NULL); p = p->suivante) {
    printf("%s\n",p->mot);
  }
}
