#ifndef LECTURE
#define LECTURE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbreprefixe.h"
#include "arbreradix.h"
#include "implementation1.h"

void decoupe_mot(char * lec);
void lecture_ligne(char* src,char* lec);
void construct_dico(char * dico,arbreprefixe_t* a);
void verif_ortho(arbreprefixe_t dico,char * texte);
table_hachage construct_dico_implementation1(char * dico);
void construct_dico_radix(char * dico, arbreradix_t* a);
void verif_ortho_radix(arbreradix_t dico,char * texte);
#endif
