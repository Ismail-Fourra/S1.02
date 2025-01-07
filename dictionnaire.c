
#pragma warning(disable : 4996)
#define MAX_LIGNE 28 //Le nombre maximum de lettre dans le plus long mot du dictionnaire de la langue française (+1)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verifDico(const char* mot) {
	FILE* dico = fopen("ods4.txt", "r");
	if (dico == NULL) {
		printf("Le dictionnaire est introuvable\n");
        return false;  
    }
    char ligne[MAX_LIGNE];  
    // Lire le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), dico)) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprime le saut de ligne pour pouvoir comparer la ligne avec le mot
        // Comparer directement la ligne avec le mot
        if (strcmp(ligne, mot) == 0) {
            fclose(dico);  // Fermer le fichier après avoir trouvé le mot
            return true;  // Le mot a été trouvé
        }
    }

    fclose(dico);  // Fermer le fichier si le mot n'est pas trouvé
    return false;  
}




