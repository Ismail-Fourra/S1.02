#pragma once
#include "rail.h"  // Pour manipuler le rail
#include "dictionnaire.h"// Pour l'acc�s au dictionnaire
#include "joueur.h"
#include "pioche.h"

typedef struct {
	char pioche[TAILLE_PIOCHE + 1];
	Joueur joueur1;
	Joueur joueur2;
	Rails rail;
}Partie;


bool verifier_mot(const char* mot, const char* main_joueur);