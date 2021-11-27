#include "implementation1.h"


unsigned int hash1(char* mot){
  return (unsigned int)strlen(mot)*(mot[0]);
}

bool identiques(char* mot1, char* mot2){
  return (strcmp(mot1,mot2));
}

bool est_present_1(char* mot, table_hachage* ht){
  int h = (hash1(mot))%(ht->capacite);
  while(ht->table[h]!=NULL){
    if(identiques(mot,ht->table[h]->mot)){
      return true;
    }
    ht->table[h] = ht->table[h]->next;
  }
  return false;
}

void inserer(char* mot, liste* pl){
  liste l = malloc(sizeof(liste));            /* allocation de la cellule */
  if(NULL==l){
    fprintf(stderr,"Fatal : Unable to allocate new list link.\n");
  }
  l->mot = mot;
  l->next = *pl;
  *pl = l;
}

void list_print(liste l){
  if(l!=NULL){
    printf("(");
    for(liste p=l;p!=NULL;p=p->next){
      printf(" ");
      printf("%s",l->mot);
    }
    printf(")");
    printf(",");
  }
}
table_hachage hashtable_new(int taille){
  table_hachage tab;
  tab.table=calloc(taille,sizeof(*tab.table));
  tab.capacite=taille;
  tab.capacite_initiale=taille;
  tab.nb_elements=0;
  int i;
  for(i=0;i<taille;i++){
    tab.table[i]=NULL;
  }
  return tab;
}


table_hachage redimensionner(table_hachage ht){
  if(3*ht.nb_elements > 2*ht.capacite){
    table_hachage nouv=hashtable_new(2*ht.capacite);
    for(unsigned int i=0;i<ht.capacite;i++){
      for(liste p=ht.table[i];p!=NULL;p=p->next){
        inserer_sans_redimensionner(p->mot,&nouv);
      }
    }
    free(ht.table);
    return nouv;
  }
  else{
    return ht;
  }
}

void inserer_sans_redimensionner(char* mot, table_hachage* ht){
  if(est_present_1(mot,ht)){
    printf("Element déja présent dans la liste\n");
  }
  else{
    inserer(mot,&ht->table[hash1(mot)]);
    ht->nb_elements++;
    *ht=redimensionner(*ht);
  }
}

void hashtable_print(table_hachage ht){
  printf("(");
  for(unsigned int i=0;i<ht.capacite;i++){
    list_print(ht.table[i]);
  }
  printf(")\n");
}
