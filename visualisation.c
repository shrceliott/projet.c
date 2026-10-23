#include <stdio.h>
#include <stdlib.h>
#include "forme.h"
#include "saisie.h"
#include "affichage.h"
#include "svg.h"
#include "visualisation.h"

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