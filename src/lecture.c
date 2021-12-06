#include "lecture.h"



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
      //inserer_mot(a,mot);
      i++;
    }
  }
  fclose(dictio);
}
void construct_dico_radix(char * dico, arbreradix_t* a){
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
      inserer_mot_radix(a,mot);
      i++;
    }
    compresser_arbre(a);
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
    while(fgets(phrase,18000,tex)!=NULL){
      mot=strtok(phrase," : ,. ' \"-!?\';()\n");
      while(mot!=NULL){
        if(recherche_mot(dico,mot)==0){
          printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, " : ,. ' \"-!?\';()\n");
      }
    }
  }
}
void verif_ortho_radix(arbreradix_t dico,char * texte){
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
        if(recherche_mot_radix(dico,mot)==0){
          printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, ": ,.");
      }
    }
  }
}


void construct_dico_implementation1(char * dico, table_hachage* a){
  char mot[100];
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL){
      //printf("%s\n", mot );

      T element;
      element.mot = strdup(mot);
      //printf("adresse : %d\n", &element);
      redimensionner(element,a);
    }
  }

  fclose(dictio);
}

void verif_ortho_hachage(table_hachage dico,char * texte){
  char phrase[300];
  char* mot;
  T element;
  FILE * tex = fopen(texte,"r");
  if(tex==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(phrase,300,tex)!=NULL){
      mot=strtok(phrase," : ,. ' \"");
      while(mot!=NULL){
        element.mot = strdup(mot);
        //printf("%s\n", mot );
        if(est_present(element, &dico)==0){
          printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, ": ,.");
      }
    }
  }
}

<<<<<<< HEAD

=======
>>>>>>> 4c2e267ce2c6fbe4b59c3a274d1385e3765af9d5
void construct_dico_implementation3(char * dico, liste* l){
  char mot[100];
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL){
      //printf("%s\n", mot );

      //printf("adresse : %d\n", &element);
      insere_tete_liste(strdup(mot),l);
    }
  }

  fclose(dictio);
}


void verif_ortho_liste(liste dico,char * texte){
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
        if(recherche_mot_dans_liste(dico, strdup(mot)) == false){
          printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, ": ,.");
      }
    }
  }
}
