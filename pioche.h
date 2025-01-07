#include <stdio.h>
#include <stdlib.h>
#define TAILLE_FRRQUENCES 26


enum {TAILLE_PIOCHE = 89};


typedef struct {
    char lettres[TAILLE_PIOCHE]; // Tableau pour stocker les lettres de la pioche
    int taille;                      // Nombre de lettres actuellement dans la pioche
} Pioche;



// Tableau des fréquences des lettres
typedef enum {
    A, B, C, D, E, F, G, H, I, J, L, M, N, O, P, Q, R, S, T, U, V
} Lettre;

const int frequences[TAILLE_FRRQUENCES];  // Déclaration des fréquences des lettres

void remplir_pioche(char* pioche);
void melanger_chevalets(char* pioche, int taille);
void tirer_main(char* pioche, char* main, int taille_main, int* taille_pioche);
void trier_main(char* main);


