
// joueur.c
#pragma warning (disable : 4996)
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"


// Fonction pour demander un mot � un joueur
void demander_mot(char* mot, int joueur) {
do {
        printf("%d> ", joueur);
        scanf("%s", mot);      // Lire le mot de 4 lettres du joueur
        assert(strlen(mot) == 4); //Plante si le mot d�passe les 4 lettres
    } while (!verifDico(mot));
    
}




