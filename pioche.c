#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Définition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  
    TAILLE_MAIN = 12     
} Constantes;


typedef enum {
    A = 9, B = 1, C = 2, D = 3, E = 14, 
    F = 1, G = 1, H = 1, I = 7, J = 1,  
    L = 5, M = 3, N = 6, O = 5, P = 2,  
    Q = 1, R = 6, S = 7, T = 6, U = 5,  
    V = 2             
} Lettres;


void remplir_pioche(char* pioche) {
    int index = 0;
    for (int lettre = A; lettre <= V; lettre++) {
        int freq = lettre; 
        for (int i = 0; i < freq; i++) {
            pioche[index++] = 'A' + (lettre - A);  
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

int main() {
    srand(time(NULL)); // Initialiser le générateur aléatoire

    // Création de la pioche
    char pioche[TAILLE_PIOCHE + 1];
    remplir_pioche(pioche);

    // Mélanger la pioche
    melanger_chevalets(pioche, TAILLE_PIOCHE);

    // Tirer et trier les mains des joueurs
    char main_joueur1[TAILLE_MAIN + 1];
    char main_joueur2[TAILLE_MAIN + 1];
    int taille_pioche = TAILLE_PIOCHE;

    tirer_main(pioche, main_joueur1, TAILLE_MAIN, &taille_pioche);
    tirer_main(pioche, main_joueur2, TAILLE_MAIN, &taille_pioche);

    trier_main(main_joueur1);
    trier_main(main_joueur2);

    // Afficher les mains des joueurs
    printf("Joueur 1 : %s\n", main_joueur1);
    printf("Joueur 2 : %s\n", main_joueur2);

    // Afficher la taille restante de la pioche
    printf("Pioche restante : %d lettres\n", taille_pioche);

    return 0;
}
