#include "implementation2."




noeud* creer_noeud(char c){
  noeud*p=calloc(1,sizeof(*p));
  char s =strdup(strtolower(c));
  p->lettre=s;
  return p;
}


void* destruct_noeud(noeud* p){
  free(p->lettre);
  free(p);
}


arbresuffixe_t creer_arbre(){
  arbreprefixe_t p=creer_noeud(' ');
  return p;
}
//Construire une table de hachage qui contient les suffixes déja obtenus(penser au free qui decremente juste le dernier un compteur)
