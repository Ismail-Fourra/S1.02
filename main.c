// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"  // Inclusion du fichier d'en-t�te
#include "partie.h"
#include "joueur.h"
#include "rail.h"
 // Inclure le fichier o� la fonction `demarrer_partie` est d�finie

int main() {
    Rail r;
    char* mot1, mot2;
    demander_mot1(&mot1);
    demander_mot2(&mot2);
    initRail(&mot1, &mot2, &r);
    return 0;
}

