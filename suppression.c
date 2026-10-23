#include <stdio.h>
#include "forme.h"
#include "saisie.h"
#include "affichage.h"
#include "svg.h"
#include "suppression.h"

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