#include "arbreprefixe2.h"


int main(){
  printf("%d\n",estprefixe("mot","motisma"));
  noeud_t* a = creer_noeud("BONJOUR");
  printf("%s\n",a->compteurfils);
  return EXIT_SUCCESS;
}
