
#include <stdio.h>
#include "forme.h"
#include "saisie.h"
#include "affichage.h"
#include "svg.h"
#include "suppression.h"

/**
 * @brief Deletes an existing shape.
 *
 * Checks whether any shapes are registered. If none exist,
 * displays a message and stops the function.
 *
 * Displays the list of shapes and asks the user to select
 * a shape by its number. Checks whether the selected number
 * is valid.
 *
 * Removes the SVG file, shifts the remaining shapes in the
 * array to fill the empty position, and decreases the number
 * of registered shapes.
 *
 * Regenerates the SVG files for the remaining shapes and
 * displays a confirmation message.
 *
 * @return No value.
 */
void supprimerForme(void)
{
    if (nbFormes == 0) {
        printf("Aucune forme a supprimer.\n");
        return;
    }

    afficherFormes();

    int numero = lireNombre("Numero de la forme a supprimer : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    char nomFichier[50];
    snprintf(nomFichier, sizeof(nomFichier),
             "forme_%d.svg", nbFormes);

    remove(nomFichier);

    for (int i = numero - 1; i < nbFormes - 1; i++) {
        formes[i] = formes[i + 1];
    }

    nbFormes--;

    for (int i = 1; i <= nbFormes; i++) {
        genererSVG(i);
    }

    printf("Forme supprimee.\n");
}
