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
void demarrer_partie(Partie* jeu) {
    srand(time(NULL));
    int* nbJoueur = 1;
    Joueur* joueurs;
    initialiser_Pioche(jeu->pioche);
    creation_joueur(jeu->pioche, jeu->joueur1, &nbJoueur);
    creation_joueur(jeu->pioche, jeu->joueur2, &nbJoueur);

    initRail(jeu->joueur1, jeu->joueur2, jeu->rail);
}



