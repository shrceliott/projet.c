
#include <stdio.h>
#include "saisie.h"

/**
 * @brief Reads a valid integer entered by the user.
 *
 * Displays the provided message and attempts to read an integer.
 * If the input is invalid, displays an error message and clears
 * the input buffer before asking again.
 *
 * If the end of the input is reached, returns 0.
 *
 * @param message Message displayed to the user.
 * @return The integer entered by the user, or 0 if the input ends.
 */
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
            }

            return nombre;
        }

        if (resultat == EOF) {
            return 0;
        }

        printf("Entre un nombre entier valide.\n");

        while ((caractere = getchar()) != '\n' &&
               caractere != EOF) {

        }
    }
}

/**
 * @brief Reads a strictly positive integer.
 *
 * Repeatedly calls lireNombre() until the user enters
 * an integer greater than zero.
 *
 * Displays an error message whenever the entered number
 * is zero or negative.
 *
 * @param message Message displayed to the user.
 * @return The positive integer entered by the user.
 */
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
