#pragma warning(disable:4996)
#include "partie.h"
#include "joueur.h"
#include "pioche.h"
#include "dictionnaire.h"
#include "rail.h"

void inverserRail(Rails* rail_jeu) {



    // Boucle pour inverser les caract�res du recto dans le verso
    for (int i = 0; i < (MAX_RAIL - 1); ++i) {
        rail_jeu->verso[i] = rail_jeu->recto[(MAX_RAIL - 1) - 1 - i]; //Les -1 permettent de sauter les deux caract�res vides (/0), sans eux, le programme ne compile pas correctement
    }

    // Ajout du caract�re nul � la fin de la cha�ne verso
    rail_jeu->verso[(MAX_RAIL - 1)] = '\0';

    // Affichage du r�sultat
    printf("V: %s\n", rail_jeu->verso);
}

void initRail(Joueur* joueur1, Joueur* joueur2, Rails* rail_jeu) {
    // Si le premier mot est plus proche de A (ordre alphab�tique) que le second
    // alors le rail est compos� du premier mot suivi du deuxi�me
    if (strcmp(joueur1->mot_initial, joueur2->mot_initial) < 0) {
        strncpy(rail_jeu->recto, joueur1->mot_initial, MAX_RAIL - 1);
        strncat(rail_jeu->recto, joueur2->mot_initial, MAX_RAIL - strlen(rail_jeu->recto) - 1);
    }
    // Sinon, inversement
    else if (strcmp(joueur1->mot_initial, joueur2->mot_initial) > 0) {
        strncpy(rail_jeu->recto, joueur2->mot_initial, MAX_RAIL - 1);
        strncat(rail_jeu->recto, joueur1->mot_initial, MAX_RAIL - strlen(rail_jeu->recto) - 1);
    }
    else {
        printf("Erreur : les deux mots sont identiques.\n");
        return;
    }

    // Ajout du caract�re nul � la fin de recto si n�cessaire
    rail_jeu->recto[MAX_RAIL - 1] = '\0';

    printf("R: %s\n", rail_jeu->recto);
    inverserRail(rail_jeu);
}


void modifier_chevalet(const char* delete, Joueur* joueur_act) {
    for (int i = 0; delete[i] != '\0'; ++i) { //On parcours l'entieret� du mot entr�, jusqu'arriver au caract�re nul

        for (int j = 0; joueur_act->main_joueur[j] != '\0'; ++j) { //Pour chaque lettre, on regarde l'enti�ret� de la main du joueur..

            if (delete[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond � une lettre du chevalet, on supprime la lettre de la main du joueur 

                break;
            }
        }
    }
}