#include "element.h"



void element_print(element x){
  printf("%s\n",x->rad);
  printf("Est un mot : %d\n",x->estunmot);
}

int est_un_mot(element x){
  return x->estunmot;
}
int compare_element(element chaine1,element chaine2){
  return strcmp(chaine1->rad,chaine2->rad);
}
