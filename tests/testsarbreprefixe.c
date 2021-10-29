#include "arbreprefixe.h"


int main(){
  arbreprefixe_t a=creer_arbre();
  inserer_phrase(&a,"Aled");
  arbre_delete(a);
  return EXIT_SUCCESS;
}
