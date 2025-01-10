#pragma once
#include "joueur.h"
#include "rail.h"
#include "pioche.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char pioche[TAILLE_PIOCHE+1];
    Joueur joueur1;
    Joueur joueur2;
    Rails rail;
}Partie;


