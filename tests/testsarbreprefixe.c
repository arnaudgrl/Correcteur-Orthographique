#include "arbreprefixe.h"


int main(){
  arbreprefixe_t a=creer_arbre_prefixe();
  inserer_mot(&a,"je");
  inserer_mot(&a,"jeu");
  inserer_mot(&a,"jacasser");
  inserer_mot(&a,"jiraiauboutdemesreves");
  printf("%d\n",recherche_mot(a,"je"));
  //printf("%d\n",recherche_mot(a,"revoir"));
  //printf("%d\n",recherche_mot(a,"BONJOUR"));
  //parcours_infixe(a,1,1);
  arbre_prefixe_delete(a);
  return EXIT_SUCCESS;
}
