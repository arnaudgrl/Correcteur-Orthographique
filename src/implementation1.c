#include "implementation1.h"
/*
================================================================
                     - Implementation 2 -

Cette première implementation est une table de hachage dont le
hash est fais grace à la fonction de hachage djb2.

================================================================
*/


int hash (char* mot, int taille){
  unsigned long hash = 5381;
    int c;

    while ((c = *(mot)++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    hash %= taille;
  return hash;
}

bool identiques(char* mot1, char* mot2){
  if(strcmp(mot1,mot2)==0){
    return true;
  }
  return false;
}

int est_present(char* mot, table_hachage* ht){
  int hashcode=hash(mot,ht->capacite);
  liste p=ht->table[hashcode];
  while(p!=NULL){
    if(identiques(mot,p->mot)==1){
      return 1;
    }
    p=p->suivante;
  }
  return 0;
}

void compteur_de_collisions(table_hachage a){
 unsigned int i =0 ;
 unsigned int nbr_collisions = 0;
 unsigned int case_remplie = 0;
 for ( i = 0; i < a.capacite; i++) {
   liste p = a.table[i];
   int cpt = 0 ;
   while(p != NULL){
     cpt++;
     p = p->suivante;
   }
   if(cpt>1){
     nbr_collisions++;
   }
   if(cpt==1){
     case_remplie++;
   }
 }
 printf("nombre de collisions dans la table de hachage : %d \n", nbr_collisions );
 printf("nombre de case remplie dans la table de hachage : %d \n", case_remplie );
}

table_hachage hashtable_new(unsigned int capacite,int capacite_initiale){
  table_hachage ht;
  ht.capacite = capacite;
  ht.capacite_initiale = capacite_initiale;
  ht.nb_elements = 0;
  ht.table = calloc(ht.capacite,sizeof(liste));
  for(unsigned int i=0 ; i<ht.capacite ; i++){
    ht.table[i] = NULL;
  }
  return ht;
}

void free_hashtable(table_hachage* ht){
  unsigned int i;
  for ( i = 0; i < ht->capacite; i++) {
    list_delete(ht->table[i]);
  }
  free(ht->table);
}

void hashtable_print(table_hachage ht){
  printf("{\n");
  unsigned int i;
  for(i=0;i<ht.capacite;i++){
    if(ht.table[i]!=NULL){
      printf("(");
      printf("%d :", i);
      list_print(ht.table[i]);
      printf(")");
      printf("\n");
    }
  }
  printf("}\n");
}


void redimensionner(char* mot, table_hachage* ht){
  if(3*ht->nb_elements>2*ht->capacite){
    // printf("%d\n",ht->capacite );
    table_hachage nouv = hashtable_new(2*ht->capacite, ht->capacite_initiale);
    //printf("%d,   %d \n",nouv.capacite, nouv.capacite_initiale );
    unsigned int i;
    for(i=0;i<ht->capacite;i++){
      liste p;
      for( p=ht->table[i];p!=NULL;p=p->suivante){
        inserer_sans_redimensionner(p->mot, &nouv);
      }
    }
    free_hashtable(ht);
    *ht = nouv;
  }
  inserer_sans_redimensionner(mot,ht);
}

void redimensionner_conflits(char* mot, table_hachage* ht){
  if(3*ht->nb_elements>2*ht->capacite){
    // printf("%d\n",ht->capacite );
    table_hachage nouv = hashtable_new(2*ht->capacite, ht->capacite_initiale);
    //printf("%d,   %d \n",nouv.capacite, nouv.capacite_initiale );
    unsigned int i;
    for(i=0;i<ht->capacite;i++){
      liste p;
      for( p=ht->table[i];p!=NULL;p=p->suivante){
        inserer_sans_redimensionner(p->mot, &nouv);
      }
    }
    free_hashtable(ht);
    *ht = nouv;
  }
  inserer_sans_redimensionner_conflits(mot,ht);
}

void inserer_sans_redimensionner(char* mot, table_hachage* ht){
  int hashcode = hash(mot,ht->capacite);
  ht->nb_elements++;
  insere_tete(mot,&ht->table[hashcode]);
}

void inserer_sans_redimensionner_conflits(char* mot, table_hachage* ht){
  if(est_present(mot,ht)){
  }
  else{
    insere_tete(mot,&ht->table[hash(mot,ht->capacite)]);
    ht->nb_elements++;
  }
}
