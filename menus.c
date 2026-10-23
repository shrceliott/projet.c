
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "formes.h"
#include "saisie.h"

/**
 * @brief Creates a new geometric shape.
 *
 * Checks whether the maximum number of shapes has been reached.
 * Asks the user to choose a shape type and enter its coordinates
 * and dimensions.
 *
 * Stores the new shape in the shapes array, increments the number
 * of registered shapes, and generates the corresponding SVG file.
 *
 * @return No value.
 */
void menu_creer(void)
{
    int choix;
    Forme nouvelleForme;

    if (nbFormes >= MAX_FORMES) {
        printf("Le nombre maximum de formes est atteint.\n");
        return;
    }

    printf("\n--- CREER UNE FORME ---\n");
    printf("1. Rectangle ou carre\n");
    printf("2. Ellipse ou cercle\n");
    printf("3. Ligne\n");

    choix = lireNombre("Ton choix : ");

    if (choix < 1 || choix > 3) {
        printf("Choix invalide.\n");
        return;
    }

    nouvelleForme.type = choix;

    switch (choix) {
        case 1:
            nouvelleForme.donnees.carre.x =
                lireNombre("Position X : ");

            nouvelleForme.donnees.carre.y =
                lireNombre("Position Y : ");

            nouvelleForme.donnees.carre.largeur =
                lirePositif("Largeur : ");

            nouvelleForme.donnees.carre.longueur =
                lirePositif("Hauteur : ");
            break;

        case 2:
            nouvelleForme.donnees.ellipse.x =
                lireNombre("Centre X : ");

            nouvelleForme.donnees.ellipse.y =
                lireNombre("Centre Y : ");

            nouvelleForme.donnees.ellipse.rayonX =
                lirePositif("Rayon horizontal : ");

            nouvelleForme.donnees.ellipse.rayonY =
                lirePositif("Rayon vertical : ");
            break;

        case 3:
            nouvelleForme.donnees.ligne.x1 =
                lireNombre("X du premier point : ");

            nouvelleForme.donnees.ligne.y1 =
                lireNombre("Y du premier point : ");

            nouvelleForme.donnees.ligne.x2 =
                lireNombre("X du deuxieme point : ");

            nouvelleForme.donnees.ligne.y2 =
                lireNombre("Y du deuxieme point : ");
            break;
    }

    formes[nbFormes] = nouvelleForme;
    nbFormes++;

    genererSVG(nbFormes);
}

/**
 * @brief Modifies an existing shape.
 *
 * Checks whether at least one shape exists, displays the list
 * of shapes, and asks the user to select one.
 *
 * Validates the selected number, then asks for new coordinates
 * and dimensions according to the shape type.
 *
 * Updates the shape in memory and regenerates its SVG file.
 *
 * @return No value.
 */
void modifierForme(void)
{
    int numero;
    int choix;

    if (nbFormes == 0) {
        printf("Aucune forme a modifier.\n");
        return;
    }

    afficherFormes();

    numero = lireNombre("\nNumero de la forme a modifier : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    switch (formes[numero - 1].type) {
        case 1:
            formes[numero - 1].donnees.carre.x =
                lireNombre("Nouvelle position X : ");

            formes[numero - 1].donnees.carre.y =
                lireNombre("Nouvelle position Y : ");

            formes[numero - 1].donnees.carre.largeur =
                lirePositif("Nouvelle largeur : ");

            formes[numero - 1].donnees.carre.longueur =
                lirePositif("Nouvelle hauteur : ");
            break;

        case 2:
            formes[numero - 1].donnees.ellipse.x =
                lireNombre("Nouveau centre X : ");

            formes[numero - 1].donnees.ellipse.y =
                lireNombre("Nouveau centre Y : ");

            formes[numero - 1].donnees.ellipse.rayonX =
                lirePositif("Nouveau rayon horizontal : ");

            formes[numero - 1].donnees.ellipse.rayonY =
                lirePositif("Nouveau rayon vertical : ");
            break;

        case 3:
            formes[numero - 1].donnees.ligne.x1 =
                lireNombre("Nouvelle coordonnee X1 : ");

            formes[numero - 1].donnees.ligne.y1 =
                lireNombre("Nouvelle coordonnee Y1 : ");

            formes[numero - 1].donnees.ligne.x2 =
                lireNombre("Nouvelle coordonnee X2 : ");

            formes[numero - 1].donnees.ligne.y2 =
                lireNombre("Nouvelle coordonnee Y2 : ");
            break;
    }

    genererSVG(numero);
    printf("Forme modifiee.\n");

    choix = 0;
    (void)choix;
}

/**
 * @brief Deletes an existing shape.
 *
 * Checks whether any shapes exist, displays the list, and asks
 * the user to select a shape to delete.
 *
 * Removes the corresponding SVG file and shifts the remaining
 * shapes in the array to fill the empty position.
 *
 * Decreases the number of registered shapes and renames the
 * remaining SVG files. If a file cannot be renamed, regenerates it.
 *
 * @return No value.
 */
void supprimerForme(void)
{
    int numero;
    int i;
    char ancienNom[50];
    char nouveauNom[50];

    if (nbFormes == 0) {
        printf("Aucune forme a supprimer.\n");
        return;
    }

    afficherFormes();

    numero = lireNombre("\nNumero de la forme a supprimer : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    snprintf(ancienNom, sizeof(ancienNom),
             "forme_%d.svg", numero);

    if (remove(ancienNom) != 0) {
        printf("Attention : le fichier %s n'a pas pu etre supprime.\n",
               ancienNom);
    }

    for (i = numero - 1; i < nbFormes - 1; i++) {
        formes[i] = formes[i + 1];
    }

    nbFormes--;

    for (i = numero; i <= nbFormes; i++) {
        snprintf(ancienNom, sizeof(ancienNom),
                 "forme_%d.svg", i + 1);

        snprintf(nouveauNom, sizeof(nouveauNom),
                 "forme_%d.svg", i);

        if (rename(ancienNom, nouveauNom) != 0) {
            genererSVG(i);
        }
    }

    printf("Forme supprimee.\n");
}

/**
 * @brief Opens an existing shape's SVG file.
 *
 * Checks whether any shapes exist, displays the list, and asks
 * the user to select a shape to visualize.
 *
 * Validates the selected number, generates the corresponding
 * SVG file, and attempts to open it using the system's default
 * application for SVG files.
 *
 * If the file cannot be opened automatically, displays a message
 * asking the user to open it manually.
 *
 * @return No value.
 */
void visualiserForme(void)
{
    int numero;
    char nomFichier[50];
    char commande[100];

    if (nbFormes == 0) {
        printf("Aucune forme a visualiser.\n");
        return;
    }

    afficherFormes();

    numero = lireNombre("\nNumero de la forme a visualiser : ");

    if (numero < 1 || numero > nbFormes) {
        printf("Numero invalide.\n");
        return;
    }

    genererSVG(numero);

    snprintf(nomFichier, sizeof(nomFichier),
             "forme_%d.svg", numero);

    snprintf(commande, sizeof(commande),
             "xdg-open \"%s\"", nomFichier);

    if (system(commande) != 0) {
        printf("Impossible d'ouvrir automatiquement le SVG.\n");
        printf("Ouvre le fichier %s manuellement.\n", nomFichier);
    }
}
