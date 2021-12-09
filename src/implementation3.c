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
liste list_new(){
  liste p;
  p=calloc(1,sizeof(*p));
  return p;
}


void list_delete(liste l){
  liste p = l;
  while(p != NULL){
    l = p->suivante;
    free(p);
    p=l;
  }
}


void list_print(liste l){
  if(l!=NULL){
    printf("(");
    int i = 0;
    liste p;
    for(p=l;p!=NULL;p=p->suivante){
      printf(" %d", i);
      printf(" ");
      printf("%s", p->mot );
      i++;
    }
    printf(")");
    printf(",");
  }
}

bool recherche_mot_dans_liste(liste l, char* nouv_mot){

  liste p=l;
  while(p->suivante!=NULL){

    if (strcmp(nouv_mot, p->mot)==0) {
      return true;
    }
    p = p->suivante;
  }
  return false;
}

void insere_tete(char* nouv, liste* pl){
  liste p = malloc(sizeof(*p));
  if (*pl == NULL){
    strcpy(p->mot, nouv);
    *pl = p;
    return;
  }
  strcpy(p->mot, nouv);
  p->suivante = *pl ;
  *pl = p ;
}
