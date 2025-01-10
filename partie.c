// partie.c
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include "pioche.h"
#include "joueur.h"
#include "rail.h"
#include "partie.h"






//V�rifie que le mot appartient � la main du joueur






// Fonction pour d�marrer la partie
void initialiserPartie(Partie* jeu) {
    srand(time(NULL));
    int *nbrJoueur = 1;
    int taille_pioche = TAILLE_PIOCHE;

    jeu->pioche = (char*)malloc(TAILLE_PIOCHE * sizeof(char));

    initialiser_Pioche(&(jeu->pioche));

    creation_joueur(&(jeu->pioche), &(jeu->joueur1), &nbrJoueur, &taille_pioche); 
    creation_joueur(&(jeu->pioche), &(jeu->joueur2), &nbrJoueur, &taille_pioche);


    do {
        demanderMot(&jeu->joueur1);
    } while (!verifier_mot(jeu->joueur1));

    do {
        demanderMot(&jeu->joueur2);
    } while (!verifier_mot(jeu->joueur2));

    initRail(jeu->joueur1, jeu->joueur2, jeu->rail);
}



