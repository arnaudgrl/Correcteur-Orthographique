#include "arbreprefixe.h"


int main(){
  arbreprefixe_t a=creer_arbre();
  inserer_mot(&a,"Aled");
  inserer_mot(&a,"Oskour ");
  printf("%d\n",recherche_mot(a,"Salut"));
  printf("%d\n",recherche_mot(a,"Oskour"));
  printf("%d\n",recherche_mot(a,"Osko azertyuiopqsdfghjklmwxcvbn,;:!?./§ "));
  //parcours_infixe(a,1,1);
  arbre_delete(a);
  return EXIT_SUCCESS;
}
