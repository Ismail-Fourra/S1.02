#define NB_LETTRES 21

// Définition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de chevalets
    TAILLE_MAIN = 12     // Nombre de chevalets par joueur
} Constantes;

typedef struct {
    char lettre;
    int frequence;
} Lettre;



char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
int frequences[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 0, 5, 3, 6, 5, 2, 1, 1, 7, 6, 5, 2 }; // Fréquences fournies