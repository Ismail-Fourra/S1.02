#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "joueur.h"
#include "pioche.h"
#include "partie.h"




// Fonction d'initialisation de la pioche
void initialiser_Pioche(Partie* jeu) {
    
    char lettresJeu[NB_LETTRES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequencesJeu[NB_LETTRES] ={9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2};
    int index = 0;

    malloc();
    for (int i = 0; i < NB_LETTRES; ++i) {
        for (int j = index; j < frequencesJeu[i]+index; ++j) {
            jeu->pioche[j] = lettresJeu[i];
           
        } 
        ++index;
    }

   

   
    
}


// Fonction pour mélanger un tableau de caractères
void melanger_chevalets(char* pioche) {
    for (int i = TAILLE_PIOCHE; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }
}


// Fonction pour tirer une main de chevalets
void tirer_main(Partie* jeu, Joueur* joueur_act) {

    int nb = 0;
    int taille_pio = (char*)malloc(sizeof(TAILLE_PIOCHE) - nb);
    for (int i = 0; i < TAILLE_MAIN; i++) {
        int j = rand() % (TAILLE_PIOCHE - nb);
        joueur_act->main_joueur[i] = jeu->pioche[j];
        jeu->pioche[TAILLE_PIOCHE - nb];
        ++nb;
    }


// Fonction pour trier une chaîne de caractères par ordre alphabétique
void trier_main(char* main) {
    int taille = strlen(main);
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (main[i] > main[j]) {
                char temp = main[i];
                main[i] = main[j];
                main[j] = temp;
            }
        }
    }
}