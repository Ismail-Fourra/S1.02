// partie.c
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include "pioche.h"
#include "joueur.h"
#include "rail.h"






//V�rifie que le mot appartient � la main du joueur
bool verifier_mot(const char* mot, const char* main_joueur) {
    int temoin = 0;
    for (int i = 0; mot[i] != '\0' ; ++i) { //On parcours l'entieret� du mot entr�, jusqu'arriver au caract�re nul

        for (int j = 0; main_joueur[j] != '\0'; ++j){ //Pour chaque lettre, on regarde l'enti�ret� de la main du joueur..

            if (mot[i] == main_joueur[j]) { //Si la lettre du mot correspond � une lettre du chevalet, on incr�mente la valeur t�moin et on continue la boucle
                ++temoin;
                break;
            }
        }
    }

    if (temoin == (TAILLE_MAXMOTS-1)){
        return true;
    }
    return false;
}



// Fonction pour d�marrer la partie
void demarrer_partie() {
    srand(time(NULL)); // Initialiser le g�n�rateur al�atoire

    // Cr�ation de la pioche
    char* pioche[TAILLE_PIOCHE + 1];
    remplir_pioche(pioche);

    // M�langer la pioche
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

    // Demander � chaque joueur de saisir un mot de 4 lettres
    char mot1[TAILLE_MAXMOTS], mot2[TAILLE_MAXMOTS];

    // Saisie pour joueur 1
    do {
        demander_mot(mot1, 1);
    } while (!verifier_mot(mot1, main_joueur1));

    // Saisie pour joueur 2
    do {
        demander_mot(mot2, 2);
    } while (!verifier_mot(mot2, main_joueur2));
    Rails* rail_jeu[MAX_RAIL];
    initRail(mot1, mot2, rail_jeu);
}




