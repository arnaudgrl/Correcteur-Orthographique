#ifndef LECTURE
#define LECTURE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbreprefixe.h"
void decoupe_mot(char * lec);
void lecture_ligne(char* src,char* lec);
void construct_dico(char * dico,arbreprefixe_t* a);
void verif_ortho(arbreprefixe_t dico,char * texte);
#endif
