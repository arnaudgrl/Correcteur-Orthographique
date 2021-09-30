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

int main(){
  char lec[30];
  lecture_ligne("a_la_recherche_du_temps_perdu.txt",lec);
  printf("%s\n",lec);
  decoupe_mot(lec);
  return EXIT_SUCCESS;
}
