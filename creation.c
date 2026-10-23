
#include <stdio.h>
#include "forme.h"
#include "saisie.h"
#include "svg.h"
#include "creation.h"

void creerForme(void)
{
    if (nbFormes >= MAX_FORMES) {
        printf("Nombre maximum de formes atteint.\n");
        return;
    }

    Forme nouvelle;

    printf("\n--- CREATION D'UNE FORME ---\n");
    printf("1. Rectangle\n");
    printf("2. Ellipse\n");
    printf("3. Ligne\n");

    int choix = lireNombre("Votre choix : ");

    switch (choix) {
        case 1:
            nouvelle.type = 1;
            nouvelle.donnees.carre.x =
                lireNombre("Position X : ");
            nouvelle.donnees.carre.y =
                lireNombre("Position Y : ");
            nouvelle.donnees.carre.largeur =
                lirePositif("Largeur : ");
            nouvelle.donnees.carre.longueur =
                lirePositif("Longueur : ");
            break;

        case 2:
            nouvelle.type = 2;
            nouvelle.donnees.ellipse.x =
                lireNombre("Position X : ");
            nouvelle.donnees.ellipse.y =
                lireNombre("Position Y : ");
            nouvelle.donnees.ellipse.rayonX =
                lirePositif("Rayon X : ");
            nouvelle.donnees.ellipse.rayonY =
                lirePositif("Rayon Y : ");
            break;

        case 3:
            nouvelle.type = 3;
            nouvelle.donnees.ligne.x1 =
                lireNombre("Position X1 : ");
            nouvelle.donnees.ligne.y1 =
                lireNombre("Position Y1 : ");
            nouvelle.donnees.ligne.x2 =
                lireNombre("Position X2 : ");
            nouvelle.donnees.ligne.y2 =
                lireNombre("Position Y2 : ");
            break;

        default:
            printf("Choix invalide.\n");
            return;
    }

    formes[nbFormes] = nouvelle;
    nbFormes++;

    genererSVG(nbFormes);

    printf("Forme creee avec succes !\n");
}
