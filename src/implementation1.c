#include "implementation1.h"
#include "implementation3.h"
#include <stdbool.h>

/*
================================================================
                     - Implementation 1 -

Cette première implementation est une table de hachage dont le
hash est la longueur du mot fois l'indice de sa première lettre.

================================================================
*/

void element_print(T element){
  printf("Le mot est : %s\n",element.mot);
}

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
//
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
      printf("%s", p->element.mot );
      i++;
    }
    printf(")");
    printf(",");
  }
}

int hash(T element, int taille){
  // char* str = element.mot;
  // unsigned long hash = 5381;
  //   int c;
  //
  //   while (c = *str++)
  //       hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  //
  // return hash % taille;
  //printf("%d\n", strlen(element.mot) );
  //printf("%d\n", taille );
  return (strlen(element.mot))%taille;
}

int identiques(T element_1,T element_2){
  //printf("%s comparé à %s\n", element_1.mot, element_2.mot );
  char a1 =  *element_1.mot;
  char a2 =  *element_2.mot;
  if (a2==a1) {
    return 1;
  }
  return 0;
}

int est_present(T element, table_hachage* ht){
  //printf("%d\n",ht->capacite);
  int hashcode=hash(element,ht->capacite)+1;
  liste p=ht->table[hashcode];
  while(p!=NULL){
    //printf("%s comparé à %s\n", element.mot, p->element.mot );
    if(identiques(element,p->element)==1){
      //printf("ils sont identiques");
      return 1;
    }
    p=p->suivante;
  }
  return 0;
}

table_hachage hashtable_new(unsigned int taille, unsigned int taille_initiale){
  table_hachage ht;
  ht.capacite=taille;
  ht.table=calloc(ht.capacite,sizeof(*ht.table));
  ht.capacite_initiale=taille_initiale;
  ht.nb_elements=0;
  int i;
  for(i=0;i<ht.capacite;i++){
    ht.table[i]=NULL;
  }
  return ht;
}

void redimensionner(T element, table_hachage* ht){
  if(3*ht->nb_elements>2*ht->capacite){
    // printf("%d\n",ht->capacite );
    table_hachage nouv = hashtable_new(2*ht->capacite, ht->capacite_initiale);
    //printf("%d,   %d \n",nouv.capacite, nouv.capacite_initiale );
    unsigned int i;
    for(i=0;i<ht->capacite;i++){
      liste p;
      for( p=ht->table[i];p!=NULL;p=p->suivante){
        inserer_sans_redimensionner(p->element,&nouv);
      }
    }
    //free_hashtable(ht);
    *ht = nouv;
  }
  inserer_sans_redimensionner(element,ht);


}
void inserer_sans_redimensionner(T element, table_hachage* ht){
  // T element;
  // element.mot = mot;
  //element_print(element);
  //printf("%s\n",element.mot );
  // if(est_present(element,ht)==1){
  //   printf("L'element %s déja présent dans la liste\n", element.mot);
  // }
  //else{
    //liste* p = &ht->table[hash(element,ht->capacite)];
    //insere_tete(element,p);
    //liste* l = &ht->table[hash(element,ht->capacite)];
    //list_print(*l);
    //hashtable_print(ht);
    //printf("\n");
    //ht->nb_elements++;
  //}
  int h = hash(element, ht->capacite);
  ht->nb_elements++;
  insere_tete(element,&ht->table[h]);
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
    list_delete(ht.table[i]);
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
