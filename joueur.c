
// joueur.c
#pragma warning (disable : 4996)
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Fonction pour demander un mot � un joueur
void demander_mot1(char* mot) {
    printf("1> ");
    scanf("%s", mot);      // Lire le mot de 4 lettres du joueur
    assert(strlen(mot) == 4); //Plante si le mot d�passe les 4 lettres
}

void demander_mot2(char* mot) {
    printf("%2> ");         // 
    scanf("%s", mot);      // Lire le mot de 4 lettres du joueur
    assert(strlen(mot) == 4); //Plante si le mot d�passe les 4 lettres
}
 

