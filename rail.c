#pragma warning(disable:4996)
#include "rail.h"
/*void initRail(const char* mot1, const char* mot2, Rails* rail_jeu) {
	
	//Si le premier mot est plus proche de A (ordre alphabétique) que le second, alors le rail est composé du premier mot suivi du deuxième
	if (strcmp(mot1, mot2) < 0) {
		strcpy(rail_jeu->recto, mot1);
		strcat(rail_jeu->recto, mot2);
		printf("R: %s\n", rail_jeu->recto);
		inverserRail(&rail_jeu);
	}

	//Sinon, inversement
	if (strcmp(mot1, mot2) > 0) {
		strcpy(rail_jeu->recto, mot2);
		strcat(rail_jeu->recto, mot1);
		printf("R: %s\n", rail_jeu->recto);
		inverserRail(&rail_jeu);
	}

	else;

		
}
*/

void inverserRail(Rails* rail_jeu) {
    int len = strlen(rail_jeu->recto);  // Longueur de la chaîne recto

    // Vérifier que la chaîne recto est valide et terminée par un caractère nul
    if (len > MAX_RAIL - 1) {
        printf("Erreur : La longueur du recto dépasse la taille maximale.\n");
        return;
    }

    // Boucle pour inverser les caractères du recto dans le verso
    for (int i = 0; i < len; ++i) {
        rail_jeu->verso[i] = rail_jeu->recto[len - 1 - i];
    }

    // Ajout du caractère nul à la fin de la chaîne verso
    rail_jeu->verso[len] = '\0';

    // Affichage du résultat
    printf("V: %s\n", rail_jeu->verso);
}

void initRail(const char* mot1, const char* mot2, Rails* rail_jeu) {
    // Si le premier mot est plus proche de A (ordre alphabétique) que le second
    // alors le rail est composé du premier mot suivi du deuxième
    if (strcmp(mot1, mot2) < 0) {
        strncpy(rail_jeu->recto, mot1, MAX_RAIL - 1);
        strncat(rail_jeu->recto, mot2, MAX_RAIL - strlen(rail_jeu->recto) - 1);
    }
    // Sinon, inversement
    else if (strcmp(mot1, mot2) > 0) {
        strncpy(rail_jeu->recto, mot2, MAX_RAIL - 1);
        strncat(rail_jeu->recto, mot1, MAX_RAIL - strlen(rail_jeu->recto) - 1);
    }
    else {
        printf("Erreur : les deux mots sont identiques.\n");
        return;
    }

    // Ajout du caractère nul à la fin de recto si nécessaire
    rail_jeu->recto[MAX_RAIL - 1] = '\0';

    printf("R: %s\n", rail_jeu->recto);
    inverserRail(rail_jeu);
}
