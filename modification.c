
#include <stdio.h>
#include "forme.h"
#include "saisie.h"
#include "affichage.h"
#include "svg.h"
#include "modification.h"

/**
 * @brief Modifies an existing shape.
 *
 * Checks whether any shapes are registered. If none exist,
 * displays a message and stops the function.
 *
 * Displays the list of shapes and asks the user to select
 * a shape by its number. Checks whether the selected number
 * is valid.
 *
 * Uses a pointer to access the selected shape and updates
 * its coordinates and dimensions according to its type.
 *
 * If the shape type is unknown, displays an error message.
 *
 * Regenerates the SVG file with the updated values and
 * displays a confirmation message.
 *
 * @return No value.
 */
void modifierForme(void)
{
    if (nbFormes == 0) {
        printf("Aucune forme a modifier.\n");
        return;
    }

    afficherFormes();

    int numero = lireNombre("Numero de la forme a modifier : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    Forme *f = &formes[numero - 1];

    switch (f->type) {
        case 1:
            f->donnees.carre.x =
                lireNombre("Nouvelle position X : ");
            f->donnees.carre.y =
                lireNombre("Nouvelle position Y : ");
            f->donnees.carre.largeur =
                lirePositif("Nouvelle largeur : ");
            f->donnees.carre.longueur =
                lirePositif("Nouvelle longueur : ");
            break;

        case 2:
            f->donnees.ellipse.x =
                lireNombre("Nouvelle position X : ");
            f->donnees.ellipse.y =
                lireNombre("Nouvelle position Y : ");
            f->donnees.ellipse.rayonX =
                lirePositif("Nouveau rayon X : ");
            f->donnees.ellipse.rayonY =
                lirePositif("Nouveau rayon Y : ");
            break;

        case 3:
            f->donnees.ligne.x1 =
                lireNombre("Nouvelle position X1 : ");
            f->donnees.ligne.y1 =
                lireNombre("Nouvelle position Y1 : ");
            f->donnees.ligne.x2 =
                lireNombre("Nouvelle position X2 : ");
            f->donnees.ligne.y2 =
                lireNombre("Nouvelle position Y2 : ");
            break;

        default:
            printf("Type de forme inconnu.\n");
            return;
    }

    genererSVG(numero);
    printf("Forme modifiee.\n");
}
