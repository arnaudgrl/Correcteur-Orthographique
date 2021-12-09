#include "arbreradix.h"

/*
===========================================================================================================================
                     - Implementation 4 -

Cette quatrieme implementation est un arbre radix construit a partir d'un arbre prefixe optimise en memoire puis compresse

===========================================================================================================================
*/
noeud_radix_t* creer_noeud_radix(char* chaine){
  noeud_radix_t*p=calloc(1,sizeof(*p));
  if(p==NULL){
    printf("Erreur d'allocation");
  }
  int taille=strlen(chaine);
  p->radix = calloc(taille,sizeof(char*));
  for(int i=0;chaine[i]!='\0';i++){
    p->radix[i]=tolower(chaine[i]);
  }
  p->compteurfils=0;
  return p;
}

void destruct_noeud_radix(noeud_radix_t* noeud){
  free(noeud->radix);
  free(noeud);
}



arbreradix_t creer_arbre_radix(){
  arbreradix_t res = creer_noeud_radix("root");
  return res;
}

void arbre_radix_delete(arbreradix_t a){
  if(a!=NULL){
    for(int i=0;i<a->compteurfils;i++){
      arbre_radix_delete(a->alp[i]);
    }
    free(a->alp);
    destruct_noeud_radix(a);
  }
  if(a==NULL){
    return ;
  }
}


void inserer_lettre_radix(arbreradix_t* a, char* c){
  assert(a!=NULL);
  arbreradix_t p =*a;
  if(p->compteurfils==0){
    p->alp=calloc(1,sizeof(*p->alp));
    p->alp[0]=creer_noeud_radix(c);
    p->compteurfils++;
  }
  else{
    p->alp=realloc(p->alp,(p->compteurfils+1)*sizeof(*p->alp));
    p->alp[p->compteurfils]=creer_noeud_radix(c);
    p->compteurfils++;
  }
}

void inserer_mot_radix(arbreradix_t* a, char* mot){
  arbreradix_t p=*a;
  int indice;
  int j=0;
  char* lettrestring=malloc(2*sizeof(char));
  lettrestring[1]='\0';
  for(int i=0;mot[i]!='\0';i++){
    lettrestring[0]=mot[i];
    if(p->compteurfils==0){
      inserer_lettre_radix(&p,lettrestring);
      p=p->alp[0];
    }
    else{
      j=0;
      while(j<p->compteurfils && strcmp(p->alp[j]->radix,lettrestring)!=0){
        j++;
      }
      if(j>=p->compteurfils){
        inserer_lettre_radix(&p,lettrestring);
        p=p->alp[j];
      }
      else if(strcmp(p->alp[j]->radix,lettrestring)==0){
        p=p->alp[j];
      }
    }
  }
  p->estunmot=1;
  free(lettrestring);
}


char* concatene(char* pere, char* fils){
  int sizepere=strlen(pere);
  int sizefils=strlen(fils);
  char* interm=strdup(pere);
  free(pere);
  pere=calloc(sizepere+sizefils+1,sizeof(char*));
  pere=strcpy(pere,interm);
  pere=strcpy(pere+sizepere,fils);
  pere=pere-sizepere;
  free(interm);
  return pere;
}

void fusion_noeud(arbreradix_t* pere, arbreradix_t* fils){
  arbreradix_t son = *fils;
  arbreradix_t father = *pere;
  father->radix=concatene(father->radix,son->radix);
  father->alp=realloc(father->alp,son->compteurfils*sizeof(*(father->alp)));
  father->compteurfils=son->compteurfils;
  father->estunmot=son->estunmot;
  for(int i=0;i<son->compteurfils;i++){
    father->alp[i]=son->alp[i];
  }
  free(son->alp);
  destruct_noeud_radix(son);
}

void compresser(arbreradix_t* arbre){
  arbreradix_t p =*arbre;
  if(p->compteurfils==1 && p->estunmot==0){
    fusion_noeud(&p,&(p->alp[0]));
  }
}

void compresser_arbre(arbreradix_t* arbre){
  arbreradix_t p= *arbre;
  if(p!=NULL){
    for(int i=0;i<p->compteurfils;i++){
      compresser_arbre(&(p->alp[i]));
    }
    if(strcmp(p->radix,"root")!=0){
      compresser(&p);
    }
  }
}


int estprefixe(char* prefixe,char* mot){
  for(int i=0;prefixe[i]!='\0';i++){
    if(prefixe[i]!=mot[i]){
      return 0;
    }
  }
  return 1;
}

char* suffixe(char* mot, int size){
  return mot+size;
}

int trouve_prefixe(arbreradix_t arbre, char* mot){
  for(int i=0;i<arbre->compteurfils;i++){
    if(estprefixe(arbre->alp[i]->radix,mot)){
      return i;
    }
  }
  return -1;
}

int recherche_mot_radix(arbreradix_t arbre, char* mot){
  int prefixe;
  if(arbre->estunmot==1 && strlen(mot)==0){
    return 1;
  }
  else if(arbre->alp==NULL || strlen(mot)==0){
    return 0;
  }
  else{
    prefixe=trouve_prefixe(arbre,mot);
    if(prefixe==-1){
      return 0;
    }
    else{
      return recherche_mot_radix(arbre->alp[prefixe],suffixe(mot,(int)strlen(arbre->alp[prefixe]->radix)));
    }
  }
}
