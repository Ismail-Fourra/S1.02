

#define MAX_RAIL 9
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char recto[MAX_RAIL];
	char verso[MAX_RAIL];
} Rails; 


void initRail(const char* mot1, const char* mot2, Rails* rail_jeu);
/**
*@brief Une fonction permettant de v�rifier l'ordre alphab�tique des deux mots afin de cr�er le recto du rail 
*@param[in] mot1 Le  mot entr� par le premier joueur
*@param[in] mot2 Le  mot entr� par le deuxi�me joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis c�te � c�te (respectant l'ordre alphab�tique)
*/

void inverserRail(Rails* rail_jeu);