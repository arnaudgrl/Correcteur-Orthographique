#include "list.h"

list_t list_new(){
  list_t p=NULL;
  p->
}

void list_print(list_t l){
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
