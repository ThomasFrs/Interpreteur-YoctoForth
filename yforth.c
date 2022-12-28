#include <stdio.h>
#include "memoire.h"
#include "lecture.h"
#include "pile.h"

int main(int argc, char *argv[])
{
    /*Programme prog = LectureProg("test.4th");
    printf("Nombre de mots: %d\n", LongueurProg(prog));
    printf("4ème mot: %s\n", MotProg(prog, 3));
    AfficherProg(prog);
    LibererProg(prog);*/

    Pile pile = CreerPile();
    Empiler(pile, 5);
    Empiler(pile, 2);
    Empiler(pile, 3);
    AfficherPile(pile);
    LibererPile(pile);
    /*AfficherPile(pile);*/

    return 0;
}
