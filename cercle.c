
#include <stdio.h>
#include "cercle.h"

/**
 * @brief Creates a circle or an ellipse in an SVG file.
 *
 * If the horizontal and vertical radii are equal, writes
 * an SVG circle element.
 * Otherwise, writes an SVG ellipse element.
 *
 * The circle is filled with light coral, while the ellipse
 * is filled with khaki. Both shapes have a black outline.
 *
 * @param fichier Pointer to the SVG file.
 * @param e Structure containing the ellipse's coordinates and radii.
 * @return No value.
 */
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