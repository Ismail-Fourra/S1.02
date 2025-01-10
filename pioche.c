#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "joueur.h"
#include "pioche.h"
#include "partie.h"




// Fonction d'initialisation de la pioche
void initialiser_Pioche(char* pioche) {

    char lettresJeu[NB_LETTRES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequencesJeu[NB_LETTRES] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    int somme = 0;


    for (int i = 0; i < NB_LETTRES; ++i) {
        for (int j = somme; j < frequencesJeu[i]+somme ; ++j) {
            pioche[j] = lettresJeu[i];
        }
        somme += frequencesJeu[i];
        
    }


}


// Fonction pour tirer une main de chevalets
void tirer_main(char* pioche,Joueur* joueur_act) {
    int taille_pio = TAILLE_PIOCHE;
        



    for (int i = 0; i < TAILLE_MAIN; i++) {
        int aleatoire = rand() % taille_pio;


        joueur_act->main_joueur[i] = pioche[aleatoire];

        // Réduire la pioche en décalant les lettres restantes vers la gauche
        for (int j = aleatoire; j < taille_pio - 1; j++) {
            pioche[j] = pioche[j + 1];
        }
        taille_pio--; // Réduire la taille de la pioche
    }
}

// Fonction pour trier la main d'un joueur
void trier_main(Joueur* joueur_act) {
    int taille = strlen(joueur_act->main_joueur);
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (joueur_act->main_joueur[i] > joueur_act->main_joueur[j]) {
                char temp = joueur_act->main_joueur[i];
                joueur_act->main_joueur[i] = joueur_act->main_joueur[j];
                joueur_act->main_joueur[j] = temp;
            }
        }
    }
}