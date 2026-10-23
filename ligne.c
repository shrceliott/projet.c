
#include <stdio.h>
#include "ligne.h"

void creerLigne(FILE *fichier, struct Ligne ligne)
{
    fprintf(fichier,
            "<line x1=\"%d\" y1=\"%d\" "
            "x2=\"%d\" y2=\"%d\" "
            "stroke=\"black\" stroke-width=\"2\"/>\n",
            ligne.x1, ligne.y1,
            ligne.x2, ligne.y2);
}
