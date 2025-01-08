﻿#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "joueur.h"

enum { TAILLE_MAXMOTS = 5 };

typedef struct {
	int NoJoueur;
	char* main_joueur;
	char* mot_initial;
}Joueur;


bool verifier_mot(const char* mot, Joueur* joueur_act);

/**
* @brief Une fonction indiquant aux joueurs d'entrer un mot tout en v�rifiant qu'il ne d�passe par les 4 lettres exig�es par les r�gles du jeu
* @param [in][out] mot Le mot que le joueur va �crire
*/






