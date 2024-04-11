#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>



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

void delete_column(COLUMN **col){
    free((*col)->donnees);
    free(*col);
}

void print_col(COLUMN* col){
    for (int i=0;i<col->taille_log;i++){
        printf("[%d] %d\n",i,col->donnees[i]);
    }
}

//4.1.5
int nbr_occ(COLUMN * col,int x){
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])==x)
        {
            cpt+=1;
        }
    }
    return cpt;
}

int pos_x(COLUMN* col, int x) {
    if (x >= 0 && x < col->taille_log) {
        return col->donnees[x];
    } else {
        return NULL;
    }
}

int sup_x(COLUMN* col, int x) {
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])>x)
        {
            cpt+=1;
        }
    }
    return cpt;
}

int inf_x(COLUMN* col, int x) {
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])<x)
        {
            cpt+=1;
        }
    }
    return cpt;
}

int equal_x(COLUMN * col,int x){
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])==x)
        {
            cpt+=1;
        }
    }
    return cpt;
}


