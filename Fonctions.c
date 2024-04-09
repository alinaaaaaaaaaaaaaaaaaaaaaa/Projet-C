#include "fonctions.h"



COLUMN * create_column(char * titre){
    COLUMN colonne;
    COLUMN* ptr_col;
    ptr_col = &colonne;
    ptr_col->titre = titre;
    ptr_col->taille_ph = 256;
    return ptr_col;
}



