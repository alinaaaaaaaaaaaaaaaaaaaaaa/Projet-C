//fichier source contenant les définitions des fonctions
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>


COLUMN *create_column(char* titre){

    COLUMN* colonne; // nouveau pointeur colonne;
    colonne->titre = titre;
    colonne->taille_ph = 256; // existe uniquement le titre
    return colonne;
}





