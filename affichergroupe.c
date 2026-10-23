void afficherGroupe(void)
{
    int n, i;
MembreGroupe m;

    if (nbGroupes == 0) {
    puts("Aucun groupe.");
    return;
    }

    n = lireEntier("Numero du groupe : ");

    if (n < 1 || n > nbGroupes) {
    puts("Numero invalide.");
    return;
    }

    printf("Groupe %d :\n", n);

        for (i = 0; i < groupes[n - 1].nombreMembres; i++) {
            MembreGroupe m = groupes[n - 1].membres[i];
            printf("- %s numero %d\n", nomType(m.type), m.numero);
        }
}

