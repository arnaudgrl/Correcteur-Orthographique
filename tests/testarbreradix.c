#include "arbreradix.h"


int main(){
<<<<<<< HEAD
  // printf("%d\n",estprefixe("mot","motisma"));
  // noeud_t* a = creer_noeud("BONJOUR");
  // printf("%s\n",a->compteurfils);
=======
  printf("%d\n",estprefixe("mot","motisma"));
  arbreradix_t a =arbreradix_new();
  inserer_mot_radix(&a,"salut");
  arbreradix_t p=a;
  printf("%s\n",p->alp[0]->radix);
  p=p->alp[0];
  printf("%s\n",p->alp[0]->radix);
  p=p->alp[0];
  printf("%s\n",p->alp[0]->radix);
  p=p->alp[0];
  printf("%s\n",p->alp[0]->radix);
  p=p->alp[0];
  printf("%s\n",p->alp[0]->radix);
  printf("Compteur %d\n",p->compteurfils);
  compresser_arbre(&a);
  printf("%d\n",recherche_mot_radix(a,"salutation"));
  printf("Cond dd %d\n",estprefixe("salut","salut"));
  printf("%d\n",recherche_mot_radix(a,"bonjour"));
>>>>>>> 8c32d44b8d42742a0834680de0a964554057ae5c
  return EXIT_SUCCESS;
}
