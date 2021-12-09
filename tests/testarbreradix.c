#include "arbreradix.h"


int main(){
  char radix[7] = "BONJOUR";
  printf("%d\n",estprefixe("mot","motisma"));
  //noeud_radix_t* a = creer_noeud_radix(radix);
  //printf("%s\n",a->radix);
  arbreradix_t a =creer_arbre_radix();
  inserer_mot_radix(&a,"sa");
  inserer_mot_radix(&a,"j");
  inserer_mot_radix(&a,"je");
  inserer_mot_radix(&a,"jeu");
  printf("%d\n",a->alp[1]->alp[0]->estunmot);
  compresser_arbre(&a);
  printf("%d\n",recherche_mot_radix(a,"je"));
  arbre_radix_delete(a);
  return EXIT_SUCCESS;
}
