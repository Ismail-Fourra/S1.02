// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"  // Inclusion du fichier d'en-t�te
#include "partie.h"
#include "joueur.h"
#include "pioche.h"
 // Inclure le fichier o� la fonction `demarrer_partie` est d�finie

int main() {

    // D�marrer la partie
    int* nbJoueur = 0;
    Partie* octoverso;
    demarrer_partie(&octoverso, nbJoueur);

    return 0;
}
