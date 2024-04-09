#include "fonctions.h"
#include <stdlib.h>



COLUMN * create_column(char * titre){
    COLUMN* ptr_col;
    ptr_col = (COLUMN *)malloc(sizeof(COLUMN));
    ptr_col->titre = titre;
    ptr_col->taille_ph = 0;
    ptr_col->taille_log = 0;
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
    }
    return 0;

}





