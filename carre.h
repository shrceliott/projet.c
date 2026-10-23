
#ifndef CARRE_H
#define CARRE_H

#include <stdio.h>

struct Carre
{
    int x;
    int y;
    int largeur;
    int longueur;
};

void creerCarre(FILE *fichier, struct Carre carre);

#endif
