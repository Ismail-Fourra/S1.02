#pragma once

enum{
	MAX_MAIN=17
};
typedef struct {
    int id_joueur;             // Identifiant du joueur
    char main_joueur[MAX_MAIN];// Main du joueur (lettres qu'il poss�de)
} Joueur;




enum { TAILLE_MAXMOTS = 5 };



void demander_mot1(char* mot1);
/**
* @brief Une fonction demandant au premier joueur d'entrer un mot tout en v�rifiant qu'il ne d�passe par les 4 lettres exig�es par les r�gles du jeu
* @param[out] mot Le mot que le joueur va �crire
*/

void demander_mot2(char* mot2);
/**
* @brief Une fonction demandant au premier joueur d'entrer un mot tout en v�rifiant qu'il ne d�passe par les 4 lettres exig�es par les r�gles du jeu
* @param[out] mot Le mot que le joueur va �crire
*/