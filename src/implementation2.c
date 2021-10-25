#include "implementation2.h"

#include <string.h>


noeud_t* creer_noeud(char c){
  noeud_t*p=calloc(1,sizeof(*p));
  char s = tolower(c);
  p->lettre=s;
  return p;
}


void destruct_noeud(noeud_t* p){
  free(p);
}

int arbre_est_vide(arbreprefixe_t a){
  return a==NULL;
}
arbreprefixe_t creer_arbre(){
  arbreprefixe_t p=creer_noeud(' ');
  return p;
}
void parcours_infixe(arbreprefixe_t a,int espace,int n){
  if(!arbre_est_vide(a)){
    for(int i=0;i<13;i++){
      espace+=n;
      parcours_infixe(a->alp[i],espace,n);
      printf("\n");
    }
    for(int i=n;i<espace;i++){
      printf(" ");
    }
    printf("%c\n", a->lettre);
    for(int i=13;i<26;i++){
    parcours_infixe(a->alp[i],espace,n);
    }
  }
}
int indice_caractere(char c){
  char s =tolower(c);
  return (int)(s-'a');
}
void inserer_lettre(arbreprefixe_t* a, char c){
  int indice =indice_caractere(c);
  if((*a)->alp[indice]==NULL){
  (*a)->alp[indice]=creer_noeud(c);
  }
}
void inserer_phrase(arbreprefixe_t* a, char* mot){
  arbreprefixe_t p=*a;
  int indice;
  for(int i=0;mot[i]!='\0';i++){
    indice=indice_caractere(mot[i]);
    inserer_lettre(&p,mot[i]);
    p=p->alp[indice];
  }
}
void arbre_delete(arbreprefixe_t a){
  if(a!=NULL){
    for(int i=0;i<26;i++){
      arbre_delete(a->alp[i]);
    }
  destruct_noeud(a);
  }
}
int recherche(arbreprefixe_t* a, char* mot){

}
int main(){
  arbreprefixe_t a=creer_arbre();
  //a->alp[1]=creer_noeud('b');
  inserer_lettre(&a,'a');
  inserer_lettre(&a,'b');
  inserer_lettre(&a,'d');
  inserer_lettre(&a,'c');
  inserer_phrase(&a,"bonjour");
//  parcours_infixe(a,0,1);
  printf("%d\n",'b'-'a');
  printf("%c %c %c %c %c \n",a->alp[1]->lettre,a->alp[1]->alp[14]->lettre,a->alp[1]->alp[14]->alp[13]->lettre,a->alp[1]->alp[14]->alp[13]->alp[9]->lettre,a->alp[1]->alp[14]->alp[13]->alp[9]->alp[14]->lettre);
  arbre_delete(a);
  return EXIT_SUCCESS;
}
//Construire une table de hachage qui contient les suffixes déja obtenus(penser au free qui decremente juste le dernier un compteur)
