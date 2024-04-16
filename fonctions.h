
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

//1.Alimentation
COLUMN ** create_cdata(int nbr);
int fill_cdata(int nbr,COLUMN ** tab);
//Manque le remplissage en dur

//2.Affichage
void afficher_cdata (COLUMN ** tab,int nbr);
void afficher_cdata_lignes(COLUMN ** tab, int nbr,int lim);
void afficher_cdata_col(COLUMN ** tab, int nbr);

//3.Opération usuelles
int ajouter_ligne(COLUMN ** tab, int nbr);
int delete_ligne(COLUMN ** tab, int nbr,int ind);
//int ajouter_col(COLUMN ** tab,int nbr);
//Manque supr col
int supr_col(COLUMN ** tab, int* nbr,int ind);
int renommer_col(COLUMN ** tab,int ind);
int val_existance(COLUMN ** tab,int nbcol,int val);
int remplacer_val(COLUMN ** tab,int pos_col,int pos_lig,int val,int nbr);
void afficher_titres(COLUMN ** tab,int nbcol);

//4.Analyse et statistiques















#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
