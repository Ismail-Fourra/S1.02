#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAINE 30 // Taille maximale pour chaque mot

// Fonction pour compter le nombre de mots dans le fichier
int count_words(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Fichier non accessible\n");
        return 0;
    }

    size_t nbm = 0, nbc = 0;
    char mot[CHAINE] = { 0 };
    int n;

    n = fscanf(f, "%29s", mot);
    while (n == 1) {
        ++nbm;
        nbc += strlen(mot);
        n = fscanf(f, "%29s", mot);
    }

    if (ferror(f)) {
        printf("Erreur - %s\n", strerror(errno));
    }
    else {
        printf("Nombre de mots : %zd, Nombre moyen de lettres : %.2f\n", nbm, nbc / (float)nbm);
    }

    fclose(f);
    return nbm; // Retourne le nombre de mots
}

// Fonction pour charger le dictionnaire dans la mémoire
int load_dictionary(const char* filename, char*** dictionary) {
    int nbm = count_words(filename); // Compte les mots dans le fichier
    if (nbm == 0) {
        return 0; // Erreur si le fichier est vide ou inaccessible
    }

    // Allouer la mémoire pour le dictionnaire (pointeur de pointeurs)
    *dictionary = (char**)malloc(nbm * sizeof(char*));
    if (*dictionary == NULL) {
        printf("Erreur d'allocation mémoire pour le dictionnaire\n");
        return 0;
    }

    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Fichier non accessible\n");
        return 0;
    }

    char mot[CHAINE];
    int index = 0;
    while (fscanf(f, "%29s", mot) == 1) {
        (*dictionary)[index] = (char*)malloc((strlen(mot) + 1) * sizeof(char));
        if ((*dictionary)[index] == NULL) {
            printf("Erreur d'allocation mémoire pour le mot %s\n", mot);
            return 0;
        }
        strcpy((*dictionary)[index], mot); // Copier le mot dans le dictionnaire
        index++;
    }

    fclose(f);
    return nbm;
}

// Fonction pour rechercher un mot en utilisant un index par lettre
int search_word(char** dictionary, int nbm, const char* word) {
    // Création de l'index basé sur la première et la deuxième lettre
    char first_letter = word[0];
    char second_letter = word[1];

    for (int i = 0; i < nbm; i++) {
        if (dictionary[i][0] == first_letter && dictionary[i][1] == second_letter) {
            if (strcmp(dictionary[i], word) == 0) {
                return i; // Mot trouvé, retourne l'index
            }
        }
    }

    return -1; // Mot non trouvé
}

int main() {
    const char* filename = "ods4.txt"; // Nom du fichier contenant les mots
    char** dictionary = NULL;

    int nbm = load_dictionary(filename, &dictionary); // Charger le dictionnaire
    if (nbm == 0) {
        return 0; // Erreur lors du chargement
    }

    // Recherche d'un mot
    const char* word_to_search = "exemple"; // Remplace par le mot à rechercher
    int index = search_word(dictionary, nbm, word_to_search);
    if (index != -1) {
        printf("Le mot '%s' a été trouvé à l'index %d.\n", word_to_search, index);
    }
    else {
        printf("Le mot '%s' n'a pas été trouvé.\n", word_to_search);
    }

    // Libérer la mémoire allouée
    for (int i = 0; i < nbm; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}
