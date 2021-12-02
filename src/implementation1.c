#include "implementation1.h"

/*
================================================================
                     - Implementation 1 -

Cette première implementation est une table de hachage dont le
hash est la longueur du mot fois l'indice de sa première lettre.

================================================================
*/

void element_print(T element){
  printf("%s",element.mot);
}

void insere_tete(T element, liste* pl){
  //printf("%s\n",element.mot );
  liste p=calloc(1,sizeof(*p));
  if(NULL==p){
    fprintf(stderr,"Fatal : Unable to allocate new list link.\n");
  }
  p->element=element;
  p->suivante = *pl;
  *pl=p;
}
void list_print(liste l){
  if(l!=NULL){
    printf("(");
    int i = 0;
    for(liste p=l;p!=NULL;p=p->suivante){
      printf(" %d", i);
      printf(" ");
      element_print(p->element);
      i++;
    }
    printf(")");
    printf(",");
  }
}

int hash(T element, int taille){
  return (int)(strlen(element.mot))%taille;
}

int identiques(T element_1,T element_2){
  return (strcmp(element_1.mot,element_2.mot)==0);
}

int est_present(T element, table_hachage* ht){
  //printf("%d\n",ht->capacite);
  int hashcode=hash(element,ht->capacite);
  liste p=ht->table[hashcode];
  while(p!=NULL){
    if(identiques(element,p->element)){
      return 1;
    }
    p=p->suivante;
  }
  return 0;
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
  if(3*ht.nb_elements>2*ht.capacite){
    table_hachage nouv=hashtable_new(2*ht.capacite);
    for(unsigned int i=0;i<ht.capacite;i++){
      for(liste p=ht.table[i];p!=NULL;p=p->suivante){
        inserer_sans_redimensionner(p->element.mot,&nouv);
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
  T element;
  element.mot = mot;
  printf("%s\n", element.mot );
  //printf("%s\n",element.mot );
  // if(est_present(element,ht)==1){
  //   printf("L'element %s déja présent dans la liste\n", element.mot);
  // }
  // else{

    insere_tete(element,&ht->table[hash(element,ht->capacite)]);
    // liste* l = &ht->table[hash(element,ht->capacite)];
    // list_print(*l);
    ht->nb_elements++;
    *ht=redimensionner(*ht);
  // }
}

void hashtable_print(table_hachage *ht){
  printf("(");
  for(unsigned int i=0;i<ht->capacite;i++){
    list_print(ht->table[i]);
  }
  printf(")\n");
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
//   hashtable_print(ht);
//   printf("%d\n",ht.capacite);
//   return EXIT_SUCCESS;
// }
