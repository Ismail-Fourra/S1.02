#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NB_LETTRES 21

// D�finition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de chevalets
    TAILLE_MAIN = 12     // Nombre de chevalets par joueur
} Constantes;

// Tableau des fr�quences des lettres
typedef enum {
    A, B, C, D, E, F, G, H, I, J, L, M, N, O, P, Q, R, S, T, U, V
} Lettre;

// Fonction pour remplir la pioche avec les lettres selon leurs fr�quences
int frequences[NB_LETTRES] = { 8, 1, 3, 4, 15, 2, 2, 2, 9, 1, 4, 2, 6, 6, 6, 6, 6, 6, 5, 7, 3 };

void remplir_pioche(char* pioche) {
    int index = 0;

    // Remplissage de la pioche avec les lettres en fonction de leurs fr�quences
    for (int i = 0; i < NB_LETTRES; i++) {
        char lettre = 'A' + i;  // Convertir l'index en lettre
        int freq = frequences[i];

        // Ajouter les lettres dans la pioche selon leur fr�quence
        for (int j = 0; j < freq; j++) {
            pioche[index++] = lettre;
        }
    }

    pioche[index] = '\0'; // Terminer la cha�ne de caract�res
}

// Fonction pour m�langer un tableau de caract�res
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
    main[taille_main] = '\0'; // Terminer la cha�ne de caract�res
}

// Fonction pour trier une cha�ne de caract�res par ordre alphab�tique
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

