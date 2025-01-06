typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de chevalets
    TAILLE_MAIN = 12     // Nombre de chevalets par joueur
} Constantes;


// Tableau des fréquences des lettres
typedef enum {
    A, B, C, D, E, F, G, H, I, J, L, M, N, O, P, Q, R, S, T, U, V
} Lettre;

const int frequences[26];  // Déclaration des fréquences des lettres

void remplir_pioche(char* pioche);
void melanger_chevalets(char* pioche, int taille);
void tirer_main(char* pioche, char* main, int taille_main, int* taille_pioche);
void trier_main(char* main);


