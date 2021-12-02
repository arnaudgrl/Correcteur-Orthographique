#include "arbreprefixe2.h"

noeud_t* creer_noeud(char* radix){
  noeud_t*p=calloc(1,sizeof(*p));
  p->compteurfils=0;
  p->radix=strdup(radix);
  if(p==NULL){
    printf("Erreur d'allocation");
  }
  return p;
}
void destruct_noeud(noeud_t* p){

}


int estprefixe(char* prefixe,char* mot){
  for(int i=0;prefixe[i]!='\0';i++){
    if(prefixe[i]!=mot[i]){
      return 0;
    }
  }
  return 1;
}


arbreprefixe_t2 creer_arbre();
int arbreprefixe_est_vide(arbreprefixe_t2 a);
void parcours_infixe(arbreprefixe_t2 a,int espace,int n);
void arbre_delete(arbreprefixe_t2 a);

int indice_caractere(char c);
void inserer_lettre(arbreprefixe_t2* a, char c);
void inserer_phrase(arbreprefixe_t2* a, char* mot);

int recherche_lettre(arbreprefixe_t2 a, char lettre);
int recherche_mot(arbreprefixe_t2 a, char* mot);
