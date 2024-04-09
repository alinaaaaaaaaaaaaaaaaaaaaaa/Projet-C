
#ifndef CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
#define CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H

typedef struct {
    char* titre;
    int * donnees;
    int taille_log;
    int taille_ph;
}COLUMN;

COLUMN * create_column(char * titre);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);

//4.1.5
int nbr_occ(COLUMN* col,int x);
int pos_x(COLUMN* col,int x);













#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
