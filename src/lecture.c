#include "lecture.h"
#include "arbreprefixe.h"


void lecture_ligne(char* src,char* lec){
  FILE * texte;
  texte=fopen(src,"r");
  if(texte==NULL){
    perror("Error opening file\n");
  }
  else{
    if(fgets(lec,30,texte)==NULL){
      printf("Erreur de lecture\n");
    }
  }
}

void decoupe_mot(char * lec){
  char* mot;
  mot=strtok(lec," : ,.");
  while(mot!=NULL){
    printf("%s\n",mot);
    mot=strtok(NULL, ": ,.");
  }
}
void lecture_fichier(char* src, char * lec){
  FILE * texte;
  texte=fopen(src,"r");
  if(texte==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(lec,1000,texte)!=NULL){
        printf("%s\n",lec);
      }
    }
  }

void construct_dico(char * dico,arbreprefixe_t* a){
  char * mot;
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL){
      inserer_phrase(a,mot);
    }
  }
}
