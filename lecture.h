#ifndef __LECTURE_H__
#define __LECTURE_H__

#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

#define TAILLE_MOT_MAX 31
#define NB_MOTS_MAX 2048

struct sProgramme;

typedef struct sProgramme *Programme;

extern Programme LectureProg(char NomFichier[]);

extern int LongueurProg(Programme Prog);

extern char *MotProg(Programme Prog, int i);

extern void AfficherProg(Programme Prog);

extern void LibererProg(Programme Prog);

#endif
