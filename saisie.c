#include <stdio.h>
#include "saisie.h"

int lireNombre(const char *message)
{
    int nombre;
    int resultat;
    int caractere;

    while (1) {
        printf("%s", message);
        resultat = scanf("%d", &nombre);

        if (resultat == 1) {
            while ((caractere = getchar()) != '\n' &&
                   caractere != EOF) {
                /* Vide le reste de la ligne */
            }

            return nombre;
        }

        if (resultat == EOF) {
            return 0;
        }

        printf("Entre un nombre entier valide.\n");

        while ((caractere = getchar()) != '\n' &&
               caractere != EOF) {
            /* Vide la saisie incorrecte */
        }
    }
}

int lirePositif(const char *message)
{
    int nombre;

    do {
        nombre = lireNombre(message);

        if (nombre <= 0) {
            printf("Le nombre doit etre superieur a zero.\n");
        }
    } while (nombre <= 0);

    return nombre;
}