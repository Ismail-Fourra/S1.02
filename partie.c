
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pioche.h"  // Inclure le fichier o� la fonction `remplir_pioche` est d�finie   // Inclure le fichier o� les fonctions `tirer_main` et `trier_main` sont d�finies

void demarrer_partie() {
    srand(time(NULL));  // Initialiser le g�n�rateur al�atoire

    // Cr�ation de la pioche
    char pioche[TAILLE_PIOCHE + 1];
    remplir_pioche(pioche);

    // M�langer la pioche
    melanger_chevalets(pioche, TAILLE_PIOCHE);

    // Tirer et trier les mains des joueurs
    char main_joueur1[TAILLE_MAIN + 1];
    char main_joueur2[TAILLE_MAIN + 1];
    int taille_pioche = TAILLE_PIOCHE;

    tirer_main(pioche, main_joueur1, TAILLE_MAIN, &taille_pioche);
    tirer_main(pioche, main_joueur2, TAILLE_MAIN, &taille_pioche);

    trier_main(main_joueur1);
    trier_main(main_joueur2);

    printf("1 :  %s\n", main_joueur1);
    printf("2 :  %s\n", main_joueur2);
}
