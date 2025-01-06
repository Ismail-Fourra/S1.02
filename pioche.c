#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Définition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de chevalets
    TAILLE_MAIN = 12     // Nombre de chevalets par joueur
} Constantes;

// Tableau des fréquences des lettres
typedef enum {
    A = 9, B = 1, C = 2, D = 3, E = 14, // A, B, C, D, E
    F = 1, G = 1, H = 1, I = 7, J = 1,  // F, G, H, I, J
    L = 5, M = 3, N = 6, O = 5, P = 2,  // L, M, N, O, P
    Q = 1, R = 6, S = 7, T = 6, U = 5,  // Q, R, S, T, U
    V = 2                              // V
} Lettres;

// Fonction pour remplir la pioche avec les lettres selon leurs fréquences
void remplir_pioche(char* pioche) {
    int index = 0;
    // Remplissage de la pioche avec les lettres en fonction de leurs fréquences
    for (char lettre = 'A'; lettre <= 'V'; lettre++) {
        int freq;
        switch (lettre) {
        case 'A': freq = A; break;
        case 'B': freq = B; break;
        case 'C': freq = C; break;
        case 'D': freq = D; break;
        case 'E': freq = E; break;
        case 'F': freq = F; break;
        case 'G': freq = G; break;
        case 'H': freq = H; break;
        case 'I': freq = I; break;
        case 'J': freq = J; break;
        case 'L': freq = L; break;
        case 'M': freq = M; break;
        case 'N': freq = N; break;
        case 'O': freq = O; break;
        case 'P': freq = P; break;
        case 'Q': freq = Q; break;
        case 'R': freq = R; break;
        case 'S': freq = S; break;
        case 'T': freq = T; break;
        case 'U': freq = U; break;
        case 'V': freq = V; break;
        default: freq = 0; break;
        }
        // Ajouter les lettres dans la pioche selon leur fréquence
        for (int i = 0; i < freq; i++) {
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

    printf("1 :  %s\n", main_joueur1);
    printf("2 :  %s\n", main_joueur2);

    return 0;
}
