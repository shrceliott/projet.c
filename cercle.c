
#include <stdio.h>
#include "cercle.h"

void creerEllipse(FILE *fichier, struct Ellipse e)
{
    if (e.rayonX == e.rayonY)
    {
        fprintf(fichier,
                "<circle cx=\"%d\" cy=\"%d\" "
                "r=\"%d\" fill=\"lightcoral\" "
                "stroke=\"black\"/>\n",
                e.x, e.y, e.rayonX);
    }
    else
    {
        fprintf(fichier,
                "<ellipse cx=\"%d\" cy=\"%d\" "
                "rx=\"%d\" ry=\"%d\" "
                "fill=\"khaki\" stroke=\"black\"/>\n",
                e.x, e.y, e.rayonX, e.rayonY);
    }
}
