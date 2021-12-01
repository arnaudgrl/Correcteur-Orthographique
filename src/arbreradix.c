#include "arbreradix.h"




int feuille_unique(arbreradix_t a){
  int compteur=0;
  for(int i=0,arbreradix_t p=a->alp[i];i<ALPHABET;i++){
    if(p!=NULL){
      compteur ++;
    }
  }
  return compteur;
}
noeud_t* creer_noeud(char c){
  noeud_t*p=calloc(1,sizeof(*p));
  if(p==NULL){
    printf("%c\n",c);
    printf("Erreur d'allocation");
  }
  char s = tolower(c);
  p->lettre=s;
  return p;
}


void destruct_noeud(noeud_t* p){
  free(p);
}



arbreradix_t creer_arbre(){
  arbreradix_t p=creer_noeud(' ');
  return p;
}

int arbreradix_est_vide(arbreradix_t a){
  return a==NULL;
}

void arbre_delete(arbreradix_t a){
  if(a!=NULL){
    for(int i=0;i<26;i++){
      arbre_delete(a->alp[i]);
    }
  destruct_noeud(a);
  }
}
