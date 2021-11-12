#include "arbreprefixe.h"





noeud_t* creer_noeud(char c){
  noeud_t*p=calloc(1,sizeof(*p));
  char s = tolower(c);
  p->lettre=s;
  return p;
}


void destruct_noeud(noeud_t* p){
  free(p);
}



arbreprefixe_t creer_arbre(){
  arbreprefixe_t p=creer_noeud(' ');
  return p;
}

int arbre_est_vide(arbreprefixe_t a){
  return a==NULL;
}

void arbre_delete(arbreprefixe_t a){
  if(a!=NULL){
    for(int i=0;i<26;i++){
      arbre_delete(a->alp[i]);
    }
  destruct_noeud(a);
  }
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
  assert(a!=NULL);
  int indice =indice_caractere(c);
  if((*a)->alp[indice]==NULL){
  (*a)->alp[indice]=creer_noeud(c);
  }
}


void inserer_phrase(arbreprefixe_t* a, char* mot){
  arbreprefixe_t p=*a;
  int indice;
  //printf("%s\n",mot);
  for(int i=0;mot[i]!='\0';i++){
    indice=indice_caractere(mot[i]);
    inserer_lettre(&p,mot[i]);
    p=p->alp[indice];
  }
}


int recherche_lettre(arbreprefixe_t a, char lettre){
  int i=indice_caractere(lettre);
  if(a==NULL){
    return 0;
  }
  if(a->alp[i]==NULL){
    return 0;
  }
  else{
    return 1;
  }
}


int recherche_mot(arbreprefixe_t a, char* mot){
  int i=0;
  int indice;
  arbreprefixe_t p=a;
  while(mot[i]!='\0'){
    if(recherche_lettre(p,mot[i])==0){
      return 0;
    }
    indice=indice_caractere(mot[i]);
    p=p->alp[indice];
    i++;
  }
  return 1;
}




//Construire une table de hachage qui contient les suffixes déja obtenus(penser au free qui decremente juste le dernier un compteur)
