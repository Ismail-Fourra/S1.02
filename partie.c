// partie.c
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include "pioche.h"
#include "joueur.h"
#include "rail.h"


// Fonction pour démarrer la partie
void demarrer_partie() {
    srand(time(NULL)); // Initialiser le générateur aléatoire

    // Création de la pioche
    char* pioche[TAILLE_PIOCHE + 1];
    remplir_pioche(pioche);

    // Mélanger la pioche
    melanger_chevalets(pioche, TAILLE_PIOCHE);

    // Tirer et trier les mains des joueurs
    char main_joueur1[TAILLE_MAIN + 1];
    char main_joueur2[TAILLE_MAIN + 1];
    int taille_pioche = TAILLE_PIOCHE;

    // Tirer les mains des joueurs
    tirer_main(pioche, main_joueur1, TAILLE_MAIN, &taille_pioche);
    tirer_main(pioche, main_joueur2, TAILLE_MAIN, &taille_pioche);

    // Trier les mains des joueurs
    trier_main(main_joueur1);
    trier_main(main_joueur2);

    // Afficher les mains des joueurs
    printf("1 :  %s\n", main_joueur1);
    printf("2 :  %s\n", main_joueur2);

    // Demander à chaque joueur de saisir un mot de 4 lettres
    char mot1[TAILLE_MAXMOTS], mot2[TAILLE_MAXMOTS];

    // Saisie pour joueur 1
    demander_mot(mot1, 1);

    // Saisie pour joueur 2
    demander_mot(mot2, 2);
    Rails* rail_jeu[MAX_RAIL];
    initRail(mot1, mot2, rail_jeu);
}
