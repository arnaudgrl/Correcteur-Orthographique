#include "arbreradix.h"


int main(){
  char radix[7] = "BONJOUR";
  printf("%d\n",estprefixe("mot","motisma"));
  //noeud_radix_t* a = creer_noeud_radix(radix);
  //printf("%s\n",a->radix);
  arbreradix_t a =arbreradix_new();
  inserer_mot_radix(&a,"sa");
  compresser_arbre(&a);
//  printf("Pere %s fils %s\n",pere,fils);
  arbre_radix_delete(a);
  return EXIT_SUCCESS;
}
