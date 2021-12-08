#include "implementation1.h"
#include "implementation3.h"
#include <stdbool.h>

/*
================================================================
                     - Implementation 1 -

Cette première implementation est une table de hachage dont le
hash est fais grace à la fonction de hachage djb2.

================================================================
*/


// void insere_tete(T element, liste* pl){
//   //printf("%s\n",element.mot );
//   liste p=calloc(1,sizeof(*p));
//   if(NULL==p){
//     fprintf(stderr,"Fatal : Unable to allocate new list link.\n");
//   }
//   p->element=element;
//   p->suivante = *pl;
//   *pl=p;
// }
// //
// void list_delete(liste l){
//   liste p = l;
//   while(p != NULL){
//     l = p->suivante;
//     free(p);
//     p=l;
//   }
// }

void list_print(liste l){
  if(l!=NULL){
    printf("(");
    int i = 0;
    liste p;
    for(p=l;p!=NULL;p=p->suivante){
      printf(" %d", i);
      printf(" ");
      //element_print(p->element);
      printf("%s", p->mot );
      i++;
    }
    printf(")");
    printf(",");
  }
}


void insere_tete(T nouv, liste* pl){
  liste p = malloc(sizeof(*p));
  if (*pl == NULL){
    strcpy(p->mot, nouv);
    *pl = p;
  }
  strcpy(p->mot, nouv);
  p->suivante = *pl ;
  *pl = p ;
}


int hash (T mot, int taille){
  unsigned long hash = 5381;
    int c;

    while ((c = *(mot)++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    hash %= taille;
  return hash;
}

bool identiques(T mot1, T mot2){
  if(strcmp(mot1,mot2)==0){
    return true;
  }
  return false;
}

int est_present(T mot, table_hachage* ht){
  //printf("%d\n",ht->capacite);
  int hashcode=hash(mot,ht->capacite);
  liste p=ht->table[hashcode];
  while(p!=NULL){
    //printf("%s comparé à %s\n", element.mot, p->element.mot );
    if(identiques(mot,p->mot)==1){
      //printf("ils sont identiques");
      return 1;
    }
    p=p->suivante;
  }
  return 0;
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

void redimensionner(T mot, table_hachage* ht){
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
    //free_hashtable(ht);
    *ht = nouv;
  }
  inserer_sans_redimensionner(mot,ht);
}


void inserer_sans_redimensionner(T mot, table_hachage* ht){
  int hashcode = hash(mot,ht->capacite);
  ht->nb_elements++;
  insere_tete(mot,&ht->table[hashcode]);
}

void hashtable_print(table_hachage *ht){
  printf("{\n");
  unsigned int i;
  for(i=0;i<ht->capacite;i++){
    if(ht->table[i]!=NULL){
      printf("(");
      printf("%d :", i);
      list_print(ht->table[i]);
      printf(")");
      printf("\n");
    }
  }
  printf("}\n");
}

void free_hashtable(table_hachage ht){
  unsigned int i;
  for ( i = 0; i < ht.capacite; i++) {
    free(ht.table[i]);
  }
  free(ht.table);
}




//
// int main(){
//   T a,b,c,d,e;
//   a.mot = "chapeau";
//   b.mot = "masque";
//   c.mot = "manger";
//   e.mot = "marche";
//   d.mot = "ah";
//   printf("%d\n",hash(a,10));
//   //printf("%d\n",identiques(a,b));
//   table_hachage ht = hashtable_new(3);
//   printf("%d\n",ht.capacite);
//   inserer_sans_redimensionner(a,&ht); //chapeau
//   //printf("%d\n",est_present(a,&ht));
//   hashtable_print(ht);
//   printf("\n");
//   inserer_sans_redimensionner(b,&ht); // masque
//   //printf("%d\n",ht.capacite);
//   inserer_sans_redimensionner(c,&ht); // manger
//   inserer_sans_redimensionner(d,&ht); // ah
//   inserer_sans_redimensionner(a,&ht); // chapeau
//   inserer_sans_redimensionner(e,&ht); // marche
//   inserer_sans_redimensionner(e,&ht); // marche
//   inserer_sans_redimensionner(b,&ht); // masque
//   inserer_sans_redimensionner(c,&ht); // manger
//
//     printf("\n");
// hashtable_print(ht);
//   printf("%d\n",ht.capacite);
//   return EXIT_SUCCESS;
// }
