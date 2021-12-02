#include "lecture.h"
#include "arbreprefixe.h"
#include "implementation1.h"


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

void construct_dico(char * dico, arbreprefixe_t* a){
  int i=0;
  char mot[100];
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL && i<30000){
      inserer_phrase(a,mot);
      i++;
    }
  }
  fclose(dictio);
}

void verif_ortho(arbreprefixe_t dico,char * texte){
  char phrase[300];
  char* mot;
  FILE * tex = fopen(texte,"r");
  if(tex==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(phrase,300,tex)!=NULL){
      mot=strtok(phrase," : ,. ' ");
      while(mot!=NULL){
        if(recherche_mot(dico,mot)==0){
          printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, ": ,.");
      }
    }
  }
}


void construct_dico_implementation1(char * dico, table_hachage* a){
  int i=0;
  char mot[100];
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL && i<13){
      T element;
      element.mot =mot;
      if(est_present(element,a)==1){
        printf("L'element %s déja présent dans la liste\n", element.mot);
      }
      else{
        //printf("%s\n", mot );
        inserer_sans_redimensionner(mot,a);
        // hashtable_print(a);
        // printf("\n\n\n" );
        i++;
      }
    }
  }
  fclose(dictio);
}
