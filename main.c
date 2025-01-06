// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"  // Inclusion du fichier d'en-tête

int main() {
    char** dictionnaire = NULL;
    int taille = dico(&dictionnaire);

    if (taille > 0) {
        printf("Dictionnaire chargé avec succès, nombre de mots : %d\n", taille);
        for (int i = 0; i < taille; i++) {
            printf("%s\n", dictionnaire[i]);
            free(dictionnaire[i]);
        }
        free(dictionnaire);
    }
    else {
        printf("Échec du chargement du dictionnaire\n");
    }

    return 0;
}
