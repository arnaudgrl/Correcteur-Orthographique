#include "arbreradix.h"

int estprefixe(char* prefixe,char* mot){
  for(int i=0;prefixe[i]!='\0';i++){
    if(prefixe[i]!=mot[i]){
      return 0;
    }
  }
  return 1;
}
