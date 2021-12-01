#include "arbreprefixe.h"


int main(){
  arbreprefixe_t a=creer_arbre();
  inserer_phrase(&a,"Aled");
  parcours_infixe(a,1,1);
  arbre_delete(a);
  return EXIT_SUCCESS;
}
