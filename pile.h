#ifndef __PILE_H__
#define __PILE_H__
#include <stdbool.h>

typedef struct sPile *Pile;

extern Pile CreerPile(void);

extern bool PileVide(Pile p);

extern bool PilePleine(Pile p);

extern unsigned int HauteurPile(Pile p);

extern void Empiler(Pile p, int Elt);

extern int SommetPile(Pile p);

extern int Depiler(Pile p);

extern void AfficherPile(Pile p);

extern void LibererPile(Pile p);

extern void ExitOnError(char *exitMessage);

#endif
