#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "memoire.h"
#include "lecture.h"
#include "pile.h"

static void OperationsPile(Pile pile, char *currentMot)
{
    if( isdigit(currentMot[0]) ) Empiler(pile, (int)strtol(currentMot, (char **)NULL, 10));
    else if( strcmp(currentMot, ".s") == 0 ) AfficherPile(pile);
    else if( strcmp(currentMot, ".") == 0 ) printf("%d\n", SommetPile(pile));
    else if( strcmp(currentMot, "dup") == 0 ) Empiler(pile, SommetPile(pile));
    else if( strcmp(currentMot, "drop") == 0 ) Depiler(pile);
    else if( strcmp(currentMot, "swap") == 0 )
    {
        int topValeur = Depiler(pile);
        int bottomValeur = Depiler(pile);
        Empiler(pile, topValeur);
        Empiler(pile, bottomValeur);
    }
    else if( strcmp(currentMot, "over") == 0 )
    {
        int topValeur = Depiler(pile);
        int bottomValeur = Depiler(pile);
        Empiler(pile, bottomValeur);
        Empiler(pile, topValeur);
        Empiler(pile, bottomValeur);
    }

    else if( strcmp(currentMot, "+") == 0 || strcmp(currentMot, "-") == 0 || strcmp(currentMot, "*") == 0 || strcmp(currentMot, "/") == 0 || strcmp(currentMot, "mod") == 0 )
    {
        int topElt = Depiler(pile), bottomElt = Depiler(pile);
        if( strcmp(currentMot, "+") == 0 ) Empiler(pile, bottomElt + topElt);
        else if( strcmp(currentMot, "-") == 0 ) Empiler(pile, bottomElt - topElt);
        else if( strcmp(currentMot, "*") == 0 ) Empiler(pile, bottomElt * topElt);
        else if( strcmp(currentMot, "/") == 0 ) Empiler(pile, bottomElt / topElt);
        else if( strcmp(currentMot, "mod") == 0 ) Empiler(pile, bottomElt % topElt);
    }

    else if( strcmp(currentMot, "=") == 0 || strcmp(currentMot, "<") == 0 || strcmp(currentMot, "<=") == 0 || strcmp(currentMot, ">") == 0 || strcmp(currentMot, ">=") == 0 || strcmp(currentMot, "and") == 0 || strcmp(currentMot, "or") == 0 )
    {
        int topElt = Depiler(pile), bottomElt = Depiler(pile);
        if( strcmp(currentMot, "=" ) == 0 ) Empiler(pile, (bottomElt == topElt) ? 1 : 0 );
        else if( strcmp(currentMot, "<" ) == 0 ) Empiler(pile, (bottomElt < topElt) ? 1 : 0 );
        else if( strcmp(currentMot, "<=" ) == 0 ) Empiler(pile, (bottomElt <= topElt) ? 1 : 0 );
        else if( strcmp(currentMot, ">" ) == 0 ) Empiler(pile, (bottomElt > topElt) ? 1 : 0 );
        else if( strcmp(currentMot, ">=" ) == 0 ) Empiler(pile, (bottomElt >= topElt) ? 1 : 0 );
        else if( strcmp(currentMot, "and" ) == 0 ) Empiler(pile, (bottomElt != 0 && topElt != 0) ? 1 : 0 );
        else if( strcmp(currentMot, "or" ) == 0 ) Empiler(pile, (bottomElt != 0 || topElt != 0) ? 1 : 0 );
    }
    else if( strcmp(currentMot, "not" ) == 0 ) Empiler(pile, (Depiler(pile) == 0) ? 1 : 0 );

    else
    {
        ExitOnError("Désolé mais je ne connais pas ce mot.");
    }
}

int main(int argc, char *argv[])
{
    Programme prog = LectureProg(argv[1]);
    Pile pile = CreerPile();

    for( int i=0; i<LongueurProg(prog); i++ )
    {
        char *currentMot = MotProg(prog, i);
        /*printf("\n%s ", currentMot);*/
        
        OperationsPile(pile, currentMot);
    }
    return 0;
}
