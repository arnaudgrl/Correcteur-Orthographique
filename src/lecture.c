#include "lecture.h"

const char* separateurs="  : ,. ' \t\"-!?\';()\n*0123456789%";

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

char* motlower(char* mot){
  for(int i=0;mot[i]!='\0';i++){
    mot[i]=tolower(mot[i]);
  }
  return mot;
}
void construct_dico_prefixe(char * dico, arbreprefixe_t* a){
  printf("%s\n",dico);
  char mot[30];
  int len;
  FILE * dictio;
  dictio=fopen(dico,"r");
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,30,dictio)!=NULL ){
      len=strlen(mot);
      if(mot[len-1]<32){
        mot[len-1]=0;
      }
      inserer_mot(a,mot);
    }
  }
  fclose(dictio);
}
void construct_dico_radix(char * dico, arbreradix_t* a){
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
    }
    compresser_arbre(a);
  }
  fclose(dictio);
}



void construct_dico_implementation1(char * dico, table_hachage* a){
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
      //inserer_sans_redimensionner(mot, a);
      redimensionner(mot,a);
      i++;
    }
  }
  fclose(dictio);
}

void construct_dico_implementation3(char * dico, liste* l){
  char mot[100];
  FILE * dictio;
  dictio=fopen(dico,"r");
  int len;
  if(dictio==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(mot,100,dictio)!=NULL){
      len=strlen(mot);
      if(mot[len-1]<32){
        mot[len-1]=0;
      }
      insere_tete(mot,l);
    }
  }

  fclose(dictio);
}



void verif_ortho_liste(char* dico, char* texte){
  char phrase[30000];
  char* mot;
  int compteurmotfaux=0;
  int printtable;
  liste verif = list_new();
  table_hachage motfaux = hashtable_new(200,200);
  construct_dico_implementation3(dico, &verif);
  FILE * tex = fopen(texte,"r");
  if(tex==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(phrase,30000,tex)!=NULL){
      mot=strtok(phrase,separateurs);
      while(mot!=NULL){
        for(int i=0;mot[i]!='\0';i++){
          mot[i]=tolower(mot[i]);
        }
        if(recherche_mot_dans_liste(verif, mot) == false){
          //printf("Mal ecrit : %s\n",mot);
          compteurmotfaux++;
          redimensionner_conflits(mot,&motfaux);
        }
        mot=strtok(NULL,separateurs);
      }
    }
  }
  printf("Nombre de mot faux : %d\n",compteurmotfaux);
  printf("Voulez vous voir la liste des mots faux ? 1 = oui , autre = non");
  scanf("%d",&printtable);
  if(printtable==1){
    hashtable_print(motfaux);
  }
  free_hashtable(&motfaux);
  list_delete(verif);
  fclose(tex);
}

void verif_ortho_hachage(char* dico,char * texte){
  table_hachage verif = hashtable_new(200,200);
  construct_dico_implementation1(dico,&verif);
  table_hachage motfaux =hashtable_new(200,200);
  int compteurmotfaux=0;
  int printtable;
  char phrase[30000];
  char* mot;
  FILE * tex = fopen(texte,"r");
  if(tex==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(phrase,30000,tex)!=NULL){
      mot=strtok(phrase,separateurs);
      while(mot!=NULL){
        for(int i=0;mot[i]!='\0';i++){
          mot[i]=tolower(mot[i]);
        }
        if(est_present(mot, &verif) == 0)
        {
          compteurmotfaux++;
          redimensionner_conflits(mot,&motfaux);
          //printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL,separateurs);
      }
    }
  }
<<<<<<< HEAD
  printf("Nombre de mots faux) %d\n",compteurmotfaux);
  printf("Voulez vous voir la liste des mots faux ? 1 = oui , autre = non");
  scanf("%d",&printtable);
  if(printtable==1){
    hashtable_print(motfaux);
  }
  free_hashtable(&motfaux);
=======
  compteur_de_collisions(verif);
  printf("taille de la table de hachage : %d\n", verif.capacite );
  printf("Nombre de mots faux: %d\n",compteurmotfaux);
>>>>>>> 6d13d759f9dc48ef9b4c1dcc4f5ab2afcc08fc92
  free_hashtable(&verif);
  fclose(tex);
}

void verif_ortho_prefixe(char* dico,char * texte){
  arbreprefixe_t verif = creer_arbre_prefixe();
  construct_dico_prefixe(dico,&verif);
  table_hachage motfaux =hashtable_new(200,200);
  char phrase[30000];
  char* mot;
  int i=0;
  int printtable;
  int compteurmotfaux=0;
  FILE * tex = fopen(texte,"r");
  if(tex==NULL){
    perror("Error opening file \n");
  }
  else{
    while(fgets(phrase,30000,tex)!=NULL){
      mot=strtok(phrase,separateurs);
      while(mot!=NULL){
        if(recherche_mot(verif,mot)==0){
          compteurmotfaux++;
          redimensionner_conflits(mot,&motfaux);
          //printf("Mal ecrit : %s\n",mot);
        }
        mot=strtok(NULL, separateurs);
      }
    }
  }
  printf("Nombre de mot faux : %d\n",compteurmotfaux);
  printf("Voulez vous voir la liste des mots faux ? 1 = oui , autre = non");
  scanf("%d",&printtable);
  if(printtable==1){
    hashtable_print(motfaux);
  }
  free_hashtable(&motfaux);
  arbre_prefixe_delete(verif);
  fclose(tex);
}

void verif_ortho_radix(char* dico,char * texte){
  arbreradix_t verif = creer_arbre_radix();
  table_hachage motfaux =hashtable_new(200,200);
  char phrase[30000];
  char* mot;
  int compteurmotfaux=0;
  int printtable;
  construct_dico_radix(dico,&verif);
  FILE * tex = fopen(texte,"r");

  if(tex==NULL){
    perror("Error opening file \n");
  }

  else{
    while(fgets(phrase,30000,tex)!=NULL){

      mot=strtok(phrase,separateurs);
      while(mot!=NULL){
        mot=motlower(mot);
        if(recherche_mot_radix(verif,mot)==0){
          redimensionner_conflits(mot,&motfaux);
          //printf("Mal ecrit : %s\n",mot);
          compteurmotfaux++;
        }
        mot=strtok(NULL,separateurs);
      }
    }
  }
  printf("Nombre de mot faux : %d\n",compteurmotfaux);
  printf("Voulez vous voir la liste des mots faux ? 1 = oui , autre = non");
  scanf("%d",&printtable);
  if(printtable==1){
    hashtable_print(motfaux);
  }
  free_hashtable(&motfaux);
  arbre_radix_delete(verif);
  fclose(tex);
}
