
#include <stdio.h>
#include "saisie.h"
#include "creation.h"
#include "modification.h"
#include "suppression.h"
#include "visualisation.h"

int main(void)
{
    int choix;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Creer une forme\n");
        printf("2. Modifier une forme\n");
        printf("3. Supprimer une forme\n");
        printf("4. Visualiser une forme\n");
        printf("0. Quitter\n");

        choix = lireNombre("Votre choix : ");

        switch (choix) {
            case 1:
                creerForme();
                break;

            case 2:
                modifierForme();
                break;

            case 3:
                supprimerForme();
                break;

            case 4:
                visualiserForme();
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}
