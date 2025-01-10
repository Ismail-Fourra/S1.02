﻿
// joueur.c

#pragma warning (disable : 4996)
#include "pioche.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"
#include "joueur.h"




    bool verifier_mot(Joueur* joueur_act) {
        int temoin = 0;

        if (strlen(joueur_act->mot_initial) != 4) {
            return false;
        }

        for (int i = 0; i < strlen(joueur_act->mot_initial); ++i) { //On parcours l'entiereté du mot entré, jusqu'arriver au caractère nul

            for (int j = 0; j < TAILLE_MAIN; ++j) { //Pour chaque lettre, on regarde l'entièreté de la main du joueur..

                if (joueur_act->mot_initial[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond à une lettre du chevalet, on incrémente la valeur témoin et on continue la boucle
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


void demanderMot(Joueur* joueur_act) {
    char mot[TAILLE_MAXMOTS];
    
    do {
        printf("%d> ", joueur_act->NoJoueur);
        scanf("%s", mot); 
        strcpy(joueur_act->mot_initial, mot);
       
        
         //Plante si le mot dépasse les 4 lettres
    } while (!verifDico(joueur_act->mot_initial));
    
}
void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche) {
     
    joueur_act->NoJoueur = *nbJoueur;
    tirer_main(pioche, joueur_act, taille_pioche);
    trier_et_afficher_main(joueur_act);
   
    ++(*nbJoueur);


}









