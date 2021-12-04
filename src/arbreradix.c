#include "arbreradix.h"

int estprefixe(char* prefixe,char* mot){
  for(int i=0;prefixe[i]!='\0';i++){
    if(prefixe[i]!=mot[i]){
      return 0;
    }
  }
  return 1;
}

noeud_radix_t* creer_noeud_radix(char* radix){
  noeud_radix_t*p=calloc(1,sizeof(*p));
  p->compteurfils=0;
  p->radix=strdup(radix);
  if(p==NULL){
    printf("Erreur d'allocation");
  }
  return p;
}
