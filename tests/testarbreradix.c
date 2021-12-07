#include "arbreradix.h"


int main(){
  printf("%d\n",estprefixe("mot","motisma"));
  arbreradix_t a =arbreradix_new();
  inserer_mot_radix(&a,"sa");
  compresser_arbre(&a);
//  printf("Pere %s fils %s\n",pere,fils);
  arbre_radix_delete(a);
  return EXIT_SUCCESS;
}
