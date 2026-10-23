
#include <stdio.h>
#include "carre.h"

/**
 * @brief Creates a square or rectangle in an SVG file.
 *
 * Writes an SVG rectangle element using the coordinates,
 * length and width provided by the square structure.
 * The shape is filled with light blue and outlined in black.
 *
 * @param fichier Pointer to the SVG file.
 * @param carre Structure containing the shape's coordinates and dimensions.
 * @return No value.
 */
void creerCarre(FILE *fichier, struct Carre carre)
{
    fprintf(fichier,
            "<rect x=\"%d\" y=\"%d\" "
            "width=\"%d\" height=\"%d\" "
            "fill=\"lightblue\" stroke=\"black\"/>\n",
            carre.x, carre.y,
            carre.longueur, carre.largeur);
}
