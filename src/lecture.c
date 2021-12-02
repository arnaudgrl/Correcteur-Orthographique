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
char *remove_white_spaces(char *str){
  int i = 0, j = 0;
  while (str[i]){
    if (str[i] != ' ' ){
      str[j++] = str[i];}
    i++;
  }
  str[j] = '\0';
  return str;
}
void construct_dico(char * dico, arbreprefixe_t* a){
  int i=0;
  char mot[30];
  int len;
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,30,dictio)!=NULL){
      len=strlen(mot);
      if(mot[len-1]<32){
        mot[len-1]=0;
      }
      inserer_mot(a,mot);
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
      mot=strtok(phrase," : ,. ' \"");
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
<<<<<<< HEAD
    while(fgets(mot,100,dictio)!=NULL && i<30000){
      T element;
      element.mot = mot;
      inserer_sans_redimensionner(element,a);
      i++;
=======
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
>>>>>>> 51b9fe8cb32eeea143428ac698b7d993ad83945a
    }
  }
  fclose(dictio);
}
