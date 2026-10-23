
#include <stdio.h>
#include "ligne.h"

/**
 * @brief Creates a line in an SVG file.
 *
 * Writes an SVG line element using the starting and ending
 * coordinates provided by the line structure.
 * The line is black and has a stroke width of 2.
 *
 * @param fichier Pointer to the SVG file.
 * @param ligne Structure containing the line's starting and ending coordinates.
 * @return No value.
 */
void creerLigne(FILE *fichier, struct Ligne ligne)
{
    fprintf(fichier,
            "<line x1=\"%d\" y1=\"%d\" "
            "x2=\"%d\" y2=\"%d\" "
            "stroke=\"black\" stroke-width=\"2\"/>\n",
            ligne.x1, ligne.y1,
            ligne.x2, ligne.y2);
}
