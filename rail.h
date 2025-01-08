

#define MAX_RAIL 9
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char recto[MAX_RAIL];
	char verso[MAX_RAIL];
} Rails; 



/**
*@brief Une fonction permettant de vérifier l'ordre alphabétique des deux mots afin de créer le recto du rail 
*@param[in] joueur1->mot_initial Le  mot entré par le premier joueur
*@param[in] joueur2->mot_initial Le  mot entré par le deuxième joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis côte à côte (respectant l'ordre alphabétique)
*/

void inverserRail(Rails* rail_jeu);