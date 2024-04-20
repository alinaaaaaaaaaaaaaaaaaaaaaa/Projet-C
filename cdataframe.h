#include "column.h"
//On a décide de faire un tableau de pointeurs qui pointes sur chaque colonne du CData

//Fonction de gestion du CDataFrame
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
//int ajouter_col(COLUMN ** tab,int nbr);// A Implementer

void supr_col(COLUMN ** tab, int* nbr,int ind);
int renommer_col(COLUMN ** tab,int ind);
int val_existance(COLUMN ** tab,int nbcol,int val);
int remplacer_val(COLUMN ** tab,int pos_col,int pos_lig,int val,int nbr);
void afficher_titres(COLUMN ** tab,int nbcol);


//4.Analyse et statistiques
void afficher_nb_lignes(COLUMN ** tab);
void afficher_nb_col(int nbr);
int occ_val_cdata(COLUMN ** tab,int nbcol,int val);
int sup_val_cdata(COLUMN ** tab,int nbcol,int val); //supérieur
int inf_val_cdata(COLUMN ** tab,int nbcol,int val);

//En plus
void afficher_menu();
void delete_column(COLUMN **col);

