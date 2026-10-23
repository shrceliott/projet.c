
#include <stdio.h>
#include "carre.h"

void creerCarre(FILE *fichier, struct Carre carre)
{
    fprintf(fichier,
            "<rect x=\"%d\" y=\"%d\" "
            "width=\"%d\" height=\"%d\" "
            "fill=\"lightblue\" stroke=\"black\"/>\n",
            carre.x, carre.y,
            carre.longueur, carre.largeur);
}
