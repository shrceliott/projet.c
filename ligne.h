
#ifndef LIGNE_H
#define LIGNE_H

#include <stdio.h>

struct Ligne
{
    int x1;
    int y1;
    int x2;
    int y2;
};

void creerLigne(FILE *fichier, struct Ligne ligne);

#endif
