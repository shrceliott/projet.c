
#ifndef CERCLE_H
#define CERCLE_H

#include <stdio.h>

struct Ellipse
{
    int x;
    int y;
    int rayonX;
    int rayonY;
};

void creerEllipse(FILE *fichier, struct Ellipse e);

#endif
