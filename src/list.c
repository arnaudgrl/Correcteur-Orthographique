#include "list.h"





void list_print(list l){
  if(!list_is_empty(l)){
    printf("(");
    for(list p=l;!list_is_empty(p);p=p->suivante){
      printf(" ");
      element_print(l->element);
    }
    printf(")");
    printf(",");
  }
}
