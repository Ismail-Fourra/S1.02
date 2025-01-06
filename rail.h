#define RAIL_H

#include <stdbool.h>


void initRail(const char* mot1, const char* mot2, char* rail);
/**
*@brief Une fonction permettant de v�rifier l'ordre alphab�tique des deux mots afin de cr�er le recto du rail 
*@param[in] mot1 Le  mot entr� par le premier joueur
*@param[in] mot2 Le  mot entr� par le deuxi�me joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis c�te � c�te (respectant l'ordre alphab�tique)
*/
