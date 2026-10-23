
#include <stdio.h>
#include "forme.h"
#include "affichage.h"

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
