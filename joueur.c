
// joueur.c
#pragma warning (disable : 4996)
#include <stdio.h>

// Fonction pour demander un mot à un joueur
void demander_mot(char* mot, int joueur) {
    printf("%d> ", joueur); // Afficher le prompt 1> ou 2> selon le joueur
    scanf("%4s", mot);      // Lire le mot de 4 lettres du joueur
}

