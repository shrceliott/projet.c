
#include <stdio.h>
#include "forme.h"
#include "affichage.h"

/**
 * @brief Displays the list of registered shapes.
 *
 * If no shapes are registered, displays a message
 * and stops the function.
 *
 * Otherwise, iterates through the shapes array and displays
 * the number and type of each shape: rectangle, ellipse or line.
 * If the type is unknown, displays an appropriate message.
 *
 * @return No value.
 */
void afficherFormes(void)
{
    if (nbFormes == 0) {
        printf("Aucune forme enregistree.\n");
        return;
    }

    printf("\n--- LISTE DES FORMES ---\n");

    for (int i = 0; i < nbFormes; i++) {
        printf("%d. ", i + 1);

        switch (formes[i].type) {
            case 1:
                printf("Rectangle\n");
                break;

            case 2:
                printf("Ellipse\n");
                break;

            case 3:
                printf("Ligne\n");
                break;

            default:
                printf("Forme inconnue\n");
        }
    }
}

