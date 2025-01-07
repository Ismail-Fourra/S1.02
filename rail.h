#pragma once
#define TAILLE_RAIL 9

typedef struct {
	char recto[TAILLE_RAIL];
	char verso[TAILLE_RAIL];
}Rail;


void initRail(const char* mot1, const char* mot2, Rail* r);
/**
*@brief Une fonction permettant de v�rifier l'ordre alphab�tique des deux mots afin de cr�er le recto du rail
*@param[in] mot1 Le  mot entr� par le premier joueur
*@param[in] mot2 Le  mot entr� par le deuxi�me joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis c�te � c�te (respectant l'ordre alphab�tique)
*/

void inverserRail(Rail* r);