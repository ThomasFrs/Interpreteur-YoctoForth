#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"

#define TAILLE_MOT_MAX 31
#define NB_MOTS_MAX 2048

struct sProgramme
{
    int NbMots;
    char *TabMots[NB_MOTS_MAX];
};

Programme LectureProg(char NomFichier[])
{
    FILE *fichier = fopen(NomFichier, "rt");
    Programme prog = Allouer(sizeof(struct sProgramme));
    int Mots=0, charactere, isParantheses=0;
    char c;
    
    while( !feof(fichier) )
    {
        charactere = 0;
        prog->TabMots[Mots] = Allouer(sizeof(char) * TAILLE_MOT_MAX);

        while( (c = fgetc(fichier)) && (c != ' ' && c != '\n') && charactere < TAILLE_MOT_MAX )
        {
            if( c >= 65 && c <= 90 ) c += 32; // pour les majuscules
            if( c == '(' ) isParantheses = 1;
            else if( c == ')' )
            {
                isParantheses = 0;
                Mots--;
            }
            else if( isParantheses == 0 )
            {
                prog->TabMots[Mots][charactere] = c;
                charactere++;
            }
        }
        if( isParantheses == 0 ) Mots++;
    }
    Liberer(prog->TabMots[Mots-1]);
    prog->NbMots = Mots-1;

    fclose(fichier);
    return prog;
}

int LongueurProg(Programme Prog)
{
    return Prog->NbMots;
}

char *MotProg(Programme Prog, int i)
{
    return Prog->TabMots[i];
}

void AfficherProg(Programme Prog)
{
    for( int i=0; i<Prog->NbMots; i++ )
    {
        printf("%s", Prog->TabMots[i]);
    }
}

void LibererProg(Programme Prog)
{
    for( int i=0; i<Prog->NbMots; i++ )
    {
        Liberer(Prog->TabMots[i]);
    }
    Liberer(&Prog->NbMots);
}
