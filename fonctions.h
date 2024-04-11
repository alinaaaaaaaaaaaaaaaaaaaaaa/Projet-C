
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
int sup_x(COLUMN* col, int x);
int inf_x(COLUMN* col, int x);
int equal_x(COLUMN * col,int x);


COLUMN ** create_cdata(int nbr);
int fill_cdata(int nbr,COLUMN ** tab);
void afficher_cdata (COLUMN ** tab,int nbr);














#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
