#include "implementation1.h"


flaot hash1(T element){
  return strlen(element.mot)*(element.mot[0]);
}

bool identiques(T element_1, T element_2){
  if(element_1.mot==element_2.mot){
    return true;
  }
  return false;
}

bool est_present_1(T element, table_hachage* ht){
  int h = (hach1(element))%(ht->capacite);
  while(ht->table[h]!=NULL){
    if(identiques(element,ht->table[h]->element)){
      return true;
    }
    ht->table[h] = ht->table[h]->next;
  }
  return false;
}

void inserer(T element , table_hachage* ht){
  int h=hash(element)%(ht->capacite);
  liste l = malloc(sizeof(liste));            /* allocation de la cellule */
  l->element = element;
  l->next = ht->table[h];
  ht->table[h]=l;
}
