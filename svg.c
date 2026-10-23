
#include <stdio.h>
#include "forme.h"
#include "carre.h"
#include "cercle.h"
#include "ligne.h"
#include "svg.h"

/**
 * @brief Generates an SVG file for a specific shape.
 *
 * Checks whether the specified shape number is valid.
 * Creates an SVG filename and opens the file in write mode.
 *
 * Writes the SVG header, then calls the appropriate function
 * to draw the shape according to its type.
 *
 * If the file cannot be opened, displays an error message.
 * If the shape type is unknown, displays an error message.
 *
 * Writes the closing SVG tag and closes the file.
 *
 * @param numero Number of the shape to generate, starting at 1.
 * @return No value.
 */
void genererSVG(int numero)
{
    if (numero < 1 || numero > nbFormes)
        return;

    char nomFichier[50];

    snprintf(nomFichier, sizeof(nomFichier),
             "forme_%d.svg", numero);

    FILE *fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        printf("Erreur lors de la creation du SVG.\n");
        return;
    }

    fprintf(fichier,
            "<svg xmlns=\"http://www.w3.org/2000/svg\" "
            "width=\"800\" height=\"600\">\n");

    switch (formes[numero - 1].type) {
        case 1:
            creerCarre(fichier,
                       formes[numero - 1].donnees.carre);
            break;

        case 2:
            creerEllipse(fichier,
                         formes[numero - 1].donnees.ellipse);
            break;

        case 3:
            creerLigne(fichier,
                       formes[numero - 1].donnees.ligne);
            break;

        default:
            printf("Type de forme inconnu.\n");
            break;
    }

    fprintf(fichier, "</svg>\n");
    fclose(fichier);
}
