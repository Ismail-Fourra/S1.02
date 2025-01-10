#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "joueur.h"
#include "pioche.h"
#include "partie.h"

void melangerPioche(char* pioche) {
    for (int i = TAILLE_PIOCHE - 1; i > 0; i--) { // Parcourir de taille_pioche - 1 � 1
        int j = rand() % (i + 1); // G�n�rer un indice al�atoire valide
        // �changer les caract�res entre les positions i et j
        char temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;

    }
}

void initialiser_Pioche(char* pioche) {

    char lettresJeu[NB_LETTRES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequencesJeu[NB_LETTRES] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    int somme = 0;

    for (int i = 0; i < NB_LETTRES; ++i) {
        for (int j = somme; j < frequencesJeu[i] + somme; ++j) {
            pioche[j] = lettresJeu[i];
          
        }
        somme += frequencesJeu[i];
        
    }

    melangerPioche(pioche);
}




// Fonction pour tirer une main de chevalets
void tirer_main(char* pioche, Joueur* joueur_act, int* taille_pioche) {
  
  
    //PIOCHE joueur 1



   
        for (int i = 0; i < *taille_pioche; ++i) {
            joueur_act->main_joueur[i] = pioche[*taille_pioche - i-1];
            
        }
        *taille_pioche -= TAILLE_MAIN;

     
     
   
}

void affiche_main(Joueur* joueur_act) {

    printf("%d : ", joueur_act->NoJoueur);
    for (int i = 0; i < TAILLE_MAIN; ++i) {
        printf("%c", joueur_act->main_joueur[i]);  // Affiche chaque lettre dans la main
    }
    printf("\n");
}


// Fonction pour trier la main d'un joueur
void trier_et_afficher_main(Joueur* joueur_act) {
  
    for (int i = 0; i < TAILLE_MAIN - 1; i++) {
        for (int j = i + 1; j < TAILLE_MAIN; j++) {
            if (joueur_act->main_joueur[i] > joueur_act->main_joueur[j]) {
                char temp = joueur_act->main_joueur[i];
                joueur_act->main_joueur[i] = joueur_act->main_joueur[j];
                joueur_act->main_joueur[j] = temp;
            }
        }
    }

    affiche_main(joueur_act);
}


