#ifndef __LECTURE_H__
#define __LECTURE_H__

#include "memoire.h"

typedef struct sProgramme *Programme;

extern Programme LectureProg(char NomFichier[]);

extern int LongueurProg(Programme Prog);

extern char *MotProg(Programme Prog, int i);

extern void AfficherProg(Programme Prog);

extern void LibererProg(Programme Prog);

#endif
