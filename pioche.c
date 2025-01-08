#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "joueur.h"
#include "pioche.h"





void remplir_pioche(char* pioche) {
    int index = 0;

    // Remplissage de la pioche avec les lettres en fonction de leurs fréquences
    for (int i = 0; i < NB_LETTRES; i++) {
        char lettre = 'A' + i;  // Convertir l'index en lettre
        int freq = frequences[i];

        // Ajouter les lettres dans la pioche selon leur fréquence
        for (int j = 0; j < freq; j++) {
            pioche[index++] = lettre;
        }
    }

    pioche[index] = '\0'; // Terminer la chaîne de caractères
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

