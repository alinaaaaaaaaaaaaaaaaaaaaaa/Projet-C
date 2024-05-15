

#include "column.h"
//On a décide de faire un tableau de pointeurs qui pointes sur chaque colonne du CData
// Structure cdata

typedef struct {
    int nombre_elem; //taille logique
    COLUMN ** columns;
}CDATAFRAME;



//Fonction de gestion du CDataFrame
//1.Alimentation
CDATAFRAME * create_cdata(int nbr);
int fill_cdata(CDATAFRAME* cdata);
CDATAFRAME * remplissage_en_dur(CDATAFRAME ** cdata);
//2.Affichage
void afficher_cdata (CDATAFRAME* cdata);
void afficher_cdata_lignes(CDATAFRAME* cdata,int lim);
void afficher_cdata_col(CDATAFRAME* cdata, int lim);

//3.Opération usuelles
int ajouter_ligne(CDATAFRAME* cdata);
int delete_ligne(CDATAFRAME* cdata,int ind);
int ajouter_col(CDATAFRAME** cdata);

void supr_col(CDATAFRAME* cdata, int ind);
void renommer_col(CDATAFRAME* cdata,int ind);
int val_existance(CDATAFRAME* cdata,int val);
int remplacer_val(CDATAFRAME* cdata,int pos_col,int pos_lig,int val);
void afficher_titres(CDATAFRAME* cdata,int nbcol);


//4.Analyse et statistiques
void afficher_nb_lignes(CDATAFRAME* cdata);
void afficher_nb_col(CDATAFRAME* cdata);
int occ_val_cdata(CDATAFRAME* cdata,int val);
int sup_val_cdata(CDATAFRAME* cdata,int val); //supérieur
int inf_val_cdata(CDATAFRAME* cdata,int val);

//En plus
void afficher_menu();
void delete_column(COLUMN **col);




`

