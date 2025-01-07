#pragma warning(disable:4996)
#include "rail.h"
/*void initRail(const char* mot1, const char* mot2, Rails* rail_jeu) {
	
	//Si le premier mot est plus proche de A (ordre alphab�tique) que le second, alors le rail est compos� du premier mot suivi du deuxi�me
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
    


    // Boucle pour inverser les caract�res du recto dans le verso
    for (int i = 0; i < (MAX_RAIL-1); ++i) {
        rail_jeu->verso[i] = rail_jeu->recto[(MAX_RAIL - 1) -1 - i]; //Les -1 permettent de sauter les deux caract�res vides (/0), sans eux, le programme ne compile pas correctement
    }

    // Ajout du caract�re nul � la fin de la cha�ne verso
    rail_jeu->verso[(MAX_RAIL - 1)] = '\0';

    // Affichage du r�sultat
    printf("V: %s\n", rail_jeu->verso);
}

void initRail(const char* mot1, const char* mot2, Rails* rail_jeu) {
    // Si le premier mot est plus proche de A (ordre alphab�tique) que le second
    // alors le rail est compos� du premier mot suivi du deuxi�me
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

    // Ajout du caract�re nul � la fin de recto si n�cessaire
    rail_jeu->recto[MAX_RAIL - 1] = '\0';

    printf("R: %s\n", rail_jeu->recto);
    inverserRail(rail_jeu);
}
