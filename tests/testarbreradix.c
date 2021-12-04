#include "arbreradix.h"


int main(){
  char radix[7] = "BONJOUR";
  printf("%d\n",estprefixe("mot","motisma"));
  noeud_radix_t* a = creer_noeud_radix(radix);
  printf("%s\n",a->radix);
  return EXIT_SUCCESS;
}
