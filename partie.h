#pragma once
#include "joueur.h"
#include "rail.h"
#include "pioche.h"


typedef struct {
    char pioche[TAILLE_PIOCHE + 1];
    Joueur joueur1;
    Joueur joueur2;
    Rails rail;
}Partie;



bool verifier_mot(const char* mot, const char* main_joueur);