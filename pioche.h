#define NB_LETTRES 21

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



