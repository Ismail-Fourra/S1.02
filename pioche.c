#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "joueur.h"
#include "pioche.h"




// Fonction d'initialisation de la pioche
void initialiserPioche(Lettre pioche[]) {
    // Définition des lettres de A à V et leurs fréquences
    char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequences[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 0, 5, 3, 6, 5, 2, 1, 1, 7, 6, 5, 2 }; // Fréquences fournies

    // Initialisation de la pioche avec les lettres et fréquences
    int index = 0;
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < frequences[i]; j++) {
            pioche[index].lettre = lettres[i];
            pioche[index].frequence = frequences[i];
            index++;
        }
    }
}

int main() {
    Lettre pioche[TAILLE_PIOCHE];
    initialiserPioche(pioche);

    // Affichage des lettres et de leurs fréquences
    for (int i = 0; i < TAILLE_PIOCHE; i++) {
        printf("%c : %d\n", pioche[i].lettre, pioche[i].frequence);
    }

    return 0;
}


// Fonction pour mélanger un tableau de caractères
void melanger_chevalets(char* chevalets, int taille) {
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = chevalets[i];
        chevalets[i] = chevalets[j];
        chevalets[j] = temp;
    }
}

// Fonction pour tirer une main de chevalets
void tirer_main(char* pioche, Joueur* joueur_act, int taille_main, int* taille_pioche) {
    for (int i = 0; i < taille_main; i++) {
        joueur_act->main_joueur[i] = pioche[*taille_pioche - 1];
        (*taille_pioche)--;
    }
    joueur_act->main_joueur[taille_main] = '\0'; // Terminer la chaîne de caractères
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