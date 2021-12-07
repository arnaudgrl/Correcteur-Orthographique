#include "lecture.h"
int main(int argc, char **argv){
  assert(argc==3);
  int entree;
  char * dico = strdup(argv[0]);
  char* texte = strdup(argv[1]);
  printf("-----------------------------------------------------------\n");
  printf("ENTREZ LE NUMERO DE L'IMPLEMENTATION QUE VOUS VOULEZ TESTER\n");
  printf("1)Verification avec une liste chainée(Très long !)\n");
  printf("2)Verification avec une table de hachage par collision\n");
  printf("3)Verification avec un arbre prefixe\n");
  printf("4)Verification avec un arbre radix\n");
  printf("-------------------------------------------------------------\n");
  scanf("%d",&entree);
  printf("%d\n",entree);
  while(entree>4 || entree <1){

    printf("Vous avez entré un mauvais numéro recommencez !");
    scanf("%d",&entree);
  }
  if(entree==1){
    //verif_ortho_liste(char * dico,char* texte);
    printf("1");
    return EXIT_SUCCESS;
  }
  if(entree==2){
    //verif_ortho_hachage(char * dico,char* texte);
    printf("2");
    return EXIT_SUCCESS;
  }
  if(entree==3){
    //verif_ortho_prefixe(char * dico,char* texte);
    printf("3");
    return EXIT_SUCCESS;
  }
  if(entree==4){
    //verif_ortho_radix(char * dico,char* texte);
    printf("4");
    return EXIT_SUCCESS;
  }
  return EXIT_SUCCESS;
}
