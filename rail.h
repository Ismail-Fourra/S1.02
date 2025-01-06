#define RAIL_H

#include <stdbool.h>


void initRail(const char* mot1, const char* mot2, char* rail);
/**
*@brief Une fonction permettant de vérifier l'ordre alphabétique des deux mots afin de créer le recto du rail 
*@param[in] mot1 Le  mot entré par le premier joueur
*@param[in] mot2 Le  mot entré par le deuxième joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis côte à côte (respectant l'ordre alphabétique)
*/
