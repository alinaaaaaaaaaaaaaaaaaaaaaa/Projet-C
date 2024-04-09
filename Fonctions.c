#include "fonctions.h"
#include <stdlib.h>



COLUMN * create_column(char * titre){
    COLUMN colonne;
    COLUMN* ptr_col;
    ptr_col = &colonne;
    ptr_col->titre = titre;
    ptr_col->taille_ph = 0;
    return ptr_col;
}


int insert_value(COLUMN* col, int value){
    if (col->taille_ph == 0 ){
        col->donnees = (int*)malloc(256*sizeof(int));
        col->taille_ph+=256;
    }
    if (col->taille_log==col->taille_ph){
        col->donnees = realloc(col->donnees,col->taille_ph+256);
        col->taille_ph+=256;
    }
    if (col->taille_ph>col->taille_log && col->taille_ph!=0){
        col->donnees[col->taille_log]=value;
        col->taille_log++;
        return 1;
    } else {
        return 0;
    }
}
/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/




