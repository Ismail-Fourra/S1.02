
// joueur.c

#pragma warning (disable : 4996)
#include "pioche.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"
#include "joueur.h"

char saisirMot(Joueur* joueur_act, int nbJoueur) {
    joueur_act->NoJoueur = nbJoueur;

    do {
        do {
            printf("%d> ", joueur_act->NoJoueur);
            scanf("%s", &joueur_act->mot_initial);      // Lire le mot de 4 lettres du joueur
            
            
           assert(strlen(joueur_act->mot_initial) == 4); //Plante si le mot d�passe les 4 lettres
        } while (!verifDico(joueur_act->mot_initial));

    } while (!verifier_mot(joueur_act->mot_initial, joueur_act->NoJoueur));
    
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


void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche) {
     
    joueur_act->NoJoueur = *nbJoueur;
    tirer_main(pioche, joueur_act, taille_pioche);
    trier_et_afficher_main(joueur_act);
   
    ++(*nbJoueur);


}









