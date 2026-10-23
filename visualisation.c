
#include <stdio.h>
#include <stdlib.h>
#include "forme.h"
#include "saisie.h"
#include "affichage.h"
#include "svg.h"
#include "visualisation.h"

/**
 * @brief Opens a shape's SVG file in Visual Studio Code.
 *
 * Checks whether any shapes are stored in memory.
 * If no shapes exist, displays a message and stops the function.
 *
 * Displays the list of shapes and asks the user to select
 * one by its number. Checks whether the selected number is valid.
 *
 * Generates the corresponding SVG file, builds the filename
 * and executes a command to open the file in Visual Studio Code.
 *
 * If the command fails, displays an error message.
 *
 * @return No value.
 */
void visualiserForme(void)
{
    if (nbFormes == 0) {
        printf("Aucune forme en memoire.\n");
        return;
    }

    afficherFormes();

    int numero = (int)lireNombre("Numero de la forme a ouvrir : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    genererSVG(numero);

    char nomFichier[50];
    char commande[100];

    snprintf(nomFichier, sizeof(nomFichier),
             "forme_%d.svg", numero);

    snprintf(commande, sizeof(commande),
             "code --reuse-window ./%s", nomFichier);

    if (system(commande) != 0)
        printf("Impossible d'ouvrir %s.\n", nomFichier);
}
