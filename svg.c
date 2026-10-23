
#include <stdio.h>
#include "forme.h"
#include "carre.h"
#include "cercle.h"
#include "ligne.h"
#include "svg.h"

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
