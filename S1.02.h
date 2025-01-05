#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file octo_verso.h
 * @brief Déclarations des structures, constantes, et fonctions pour le jeu Octo-Ver so.
 */

#define MAX_CHEVALETS 88
#define MAX_JOUEURS 2
#define LONGUEUR_RAIL 8


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 /**
  * @brief Structure représentant un chevalet.
  */
typedef struct {
    char lettre; /**< Lettre présente sur le chevalet. */
} Chevalet;

/**
 * @brief Structure représentant un joueur.
 */
typedef struct {
    Chevalet chevalets[MAX_CHEVALETS]; /**< Tableau de chevalets du joueur. */
    int nb_chevalets; /**< Nombre de chevalets actuellement détenus. */
} Joueur;

/**
 * @brief Structure représentant le rail central.
 */
typedef struct {
    Chevalet rail[LONGUEUR_RAIL]; /**< Tableau représentant les lettres sur le rail. */
    int longueur; /**< Nombre de lettres actuellement sur le rail. */
} Rail;

/**
 * @brief Mélange les chevalets pour simuler une pioche aléatoire.
 *
 * @param[in, out] chevalets Tableau des chevalets à mélanger.
 * @param[in] taille Nombre total de chevalets dans le tableau.
 */
void melanger_chevalets(Chevalet* chevalets, int taille);

/**
 * @brief Distribue les chevalets initialement aux joueurs.
 *
 * @param[out] joueurs Tableau des joueurs.
 * @param[in, out] pioche Tableau des chevalets disponibles dans la pioche.
 * @param[in] taille_pioche Taille actuelle de la pioche.
 */
void distribuer_chevalets(Joueur* joueurs, Chevalet* pioche, int taille_pioche);

/**
 * @brief Affiche l'état actuel du jeu : chevalets des joueurs et rail.
 *
 * @param[in] joueurs Tableau des joueurs.
 * @param[in] rail Pointeur vers la structure représentant le rail.
 */
void afficher_jeu(Joueur joueurs[], const Rail* rail);

/**
 * @brief Valide un mot saisi par un joueur.
 *
 * @param[in] mot Mot saisi par le joueur.
 * @param[in] joueur Pointeur vers la structure représentant le joueur actuel.
 * @param[in, out] rail Pointeur vers la structure représentant le rail.
 * @param[in] cote Indique le côté du rail où le mot doit être ajouté ('R' pour recto, 'V' pour verso).
 * @return 1 si le mot est valide, 0 sinon.
 */
int valider_mot(const char* mot, Joueur* joueur, Rail* rail, char cote);

/**
 * @brief Effectue un tour de jeu pour un joueur.
 *
 * @param[in, out] joueurs Tableau des joueurs.
 * @param[in, out] rail Pointeur vers la structure représentant le rail.
 * @param[in] joueur_actuel Indice du joueur actuel dans le tableau des joueurs.
 * @param[in, out] pioche Tableau des chevalets disponibles dans la pioche.
 */
void jouer_tour(Joueur joueurs[], Rail* rail, int joueur_actuel, Chevalet* pioche);

/**
 * @brief Permet à un joueur d'échanger un chevalet avec la pioche.
 *
 * @param[in, out] joueur Pointeur vers la structure représentant le joueur.
 * @param[in, out] pioche Tableau des chevalets disponibles dans la pioche.
 */
void echanger_chevalet(Joueur* joueur, Chevalet* pioche);

/**
 * @brief Vérifie si un mot appartient au dictionnaire.
 *
 * @param[in] mot Mot à valider.
 * @return 1 si le mot est valide, 0 sinon.
 */
int est_mot_valide(const char* mot);

#endif // OCTO_VERSO_H

