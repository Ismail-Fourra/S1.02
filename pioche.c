#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "joueur.h"
#include "pioche.h"
#include "partie.h"




// Fonction d'initialisation de la pioche
void initialiser_Pioche(char** pioche) {

    char lettresJeu[NB_LETTRES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequencesJeu[NB_LETTRES] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    int somme = 0;
   
    *pioche = (char*)malloc(TAILLE_PIOCHE * sizeof(char));
    for (int i = 0; i < NB_LETTRES; ++i) {
        for (int j = somme; j < frequencesJeu[i]+somme ; ++j) {
            pioche[j] = lettresJeu[i];
        }
        somme += frequencesJeu[i];
         
    }
        
}

void creer_main(char* pioche, Joueur* joueur_act) {
    for (int i = TAILLE_PIOCHE - 1; i > 0; i--) { // Parcourir de taille_pioche - 1 à 1
        int j = rand() % (i + 1); // Générer un indice aléatoire valide
        // Échanger les caractères entre les positions i et j
        char temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;

    }
}
    
// Fonction pour tirer une main de chevalets
void tirer_main(char* pioche, Joueur* joueur_act, int nb) {
  
    //PIOCHE joueur 1

    int taille_pioche_dynamique = TAILLE_PIOCHE;

    if (nb == 1) {
        for (int i = 0; i > TAILLE_MAIN; ++i) {
            joueur_act->main_joueur[i] = pioche[TAILLE_PIOCHE - i];
            --taille_pioche_dynamique;
        }
    }

    //PIOCHE joueur 2
    if (nb == 2) {
        for (int i = TAILLE_MAIN; i > 0; --i) {
            joueur_act->main_joueur[i] = pioche[TAILLE_PIOCHE - i - (TAILLE_MAIN)];
            --taille_pioche_dynamique;
        }
    }
    


    //Reduction taille pioche
    
    
  
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


