
#ifndef FORME_H
#define FORME_H

#include "carre.h"
#include "cercle.h"
#include "ligne.h"

#define MAX_FORMES 100

typedef struct {
    int type;

    union {
        struct Carre carre;
        struct Ellipse ellipse;
        struct Ligne ligne;
    } donnees;
} Forme;

extern Forme formes[MAX_FORMES];
extern int nbFormes;

#endif
