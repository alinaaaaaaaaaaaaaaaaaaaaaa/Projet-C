
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
void afficher_cdata_lignes(COLUMN ** tab, int nbr,int lim);
void afficher_cdata_col(COLUMN ** tab, int nbr);
int ajouter_ligne(COLUMN ** tab, int nbr);
int delete_ligne(COLUMN ** tab, int nbr,int ind);
//int ajouter_col(COLUMN ** tab,int nbr);
int supr_col(COLUMN ** tab, int* nbr,int ind);














#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
