
// joueur.c

#pragma warning (disable : 4996)
#include "pioche.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"
#include "joueur.h"




// Fonction pour demander un mot � un joueur
char saisirMot(Joueur* joueur_act) {
    char* mot[TAILLE_MAXMOTS];
    do {
        do {
            printf("%d> ", joueur_act->NoJoueur);
            scanf("%s", mot);      // Lire le mot de 4 lettres du joueur
            assert(strlen(mot) == 4); //Plante si le mot d�passe les 4 lettres
        } while (!verifDico(mot));

    } while (!verifier_mot(mot, joueur_act->NoJoueur));
        joueur_act->mot_initial = mot;
}

void affiche_main(Joueur* joueur_act) {
    printf("%d :  %s\n", joueur_act->NoJoueur, joueur_act->main_joueur);
}

void creation_joueur(Partie* jeu, Joueur* joueur_act, int* nbJoueur) {
   
    tirer_main(jeu->pioche, joueur_act->main_joueur);
    trier_main(joueur_act);
    affiche_main(joueur_act);
    joueur_act->NoJoueur = (*nbJoueur)++;
     saisirMot();
}

bool verifier_mot(const char* mot, Joueur* joueur_act) {
    int temoin = 0;
    for (int i = 0; mot[i] != '\0'; ++i) { //On parcours l'entieret� du mot entr�, jusqu'arriver au caract�re nul

        for (int j = 0; joueur_act->main_joueur[j] != '\0'; ++j) { //Pour chaque lettre, on regarde l'enti�ret� de la main du joueur..

            if (mot[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond � une lettre du chevalet, on incr�mente la valeur t�moin et on continue la boucle
                ++temoin;
                break;
            }
        }
    }

    if (temoin == (TAILLE_MAXMOTS - 1)) {
        return true;
    }
    return false;
}





