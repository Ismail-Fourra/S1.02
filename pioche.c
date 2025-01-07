#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pioche.h"



// Définition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de chevalets
    TAILLE_MAIN = 12     // Nombre de chevalets par joueur
} Constantes;

// Tableau des fréquences des lettres
typedef enum {
    A, B, C, D, E, F, G, H, I, J, L, M, N, O, P, Q, R, S, T, U, V
} Lettre;

// Fonction pour remplir la pioche avec les lettres selon leurs fréquences
int frequences[NB_LETTRES] = { 8, 1, 3, 4, 15, 2, 2, 2, 9, 1, 4, 2, 6, 6, 6, 6, 6, 6, 5, 7, 3 };
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
void tirer_main(char* pioche, char* main, int taille_main, int* taille_pioche) {
    for (int i = 0; i < taille_main; i++) {
        main[i] = pioche[*taille_pioche - 1];
        (*taille_pioche)--;
    }
    main[taille_main] = '\0'; // Terminer la chaîne de caractères
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


void remplir_pioche(Pioche* pioche, const int* frequences) {
    int index = 0;
    for (int i = 0; i < TAILLE_FRRQUENCES; i++) {
        char lettre = 'A' + i;  // Convertir l'index en lettre
        for (int j = 0; j < frequences[i]; j++) {
            pioche->lettres[index++] = lettre;
        }
    }
    pioche->lettres[index] = '\0'; // Terminer la chaîne de caractères
    pioche->taille = index;
}

void melanger_pioche(Pioche* pioche) {
    for (int i = pioche->taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = pioche->lettres[i];
        pioche->lettres[i] = pioche->lettres[j];
        pioche->lettres[j] = temp;
    }
}

void tirer_main(Pioche* pioche, Joueur* joueur) {
    if (pioche->taille < TAILLE_MAIN) {
        printf("Erreur : La pioche ne contient pas assez de lettres.\n");
        return;
    }

    for (int i = 0; i < TAILLE_MAIN; i++) {
        joueur->main_joueur[i] = pioche->lettres[pioche->taille - 1];
        pioche->taille--;
    }
    joueur->main_joueur[TAILLE_MAIN] = '\0'; // Terminer la chaîne de caractères
}

void trier_main(Joueur* joueur) {
    int taille = strlen(joueur->main_joueur);
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (joueur->main_joueur[i] > joueur->main_joueur[j]) {
                char temp = joueur->main_joueur[i];
                joueur->main_joueur[i] = joueur->main_joueur[j];
                joueur->main_joueur[j] = temp;
            }
        }
    }
}

void afficher_pioche(const Pioche* pioche) {
    printf("Pioche (%d lettres) : %s\n", pioche->taille, pioche->lettres);
}

void afficher_main(const Joueur* joueur) {
    printf("Joueur %d - Main : %s\n", joueur->id_joueur, joueur->main_joueur);
}



