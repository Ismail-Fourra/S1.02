#pragma once

enum{
	MAX_MAIN=17
};
typedef struct {
    int id_joueur;             // Identifiant du joueur
    char main_joueur[MAX_MAIN];// Main du joueur (lettres qu'il possède)
} Joueur;




enum { TAILLE_MAXMOTS = 5 };



void demander_mot1(char* mot1);
/**
* @brief Une fonction demandant au premier joueur d'entrer un mot tout en vérifiant qu'il ne dépasse par les 4 lettres exigées par les régles du jeu
* @param[out] mot Le mot que le joueur va écrire
*/

void demander_mot2(char* mot2);
/**
* @brief Une fonction demandant au premier joueur d'entrer un mot tout en vérifiant qu'il ne dépasse par les 4 lettres exigées par les régles du jeu
* @param[out] mot Le mot que le joueur va écrire
*/