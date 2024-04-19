#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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

void delete_column(COLUMN **col) {
    if (col != NULL && *col != NULL) {
        free((*col)->titre);
        free((*col)->donnees);
        free(*col);
        *col = NULL;
    }
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
        return -1;
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


COLUMN ** create_cdata(int nbr){
    COLUMN ** tab;
    tab = (COLUMN**) malloc(nbr*sizeof (COLUMN*));
    for (int i=0; i <nbr;i++){
        tab[i] = create_column("");
    }
    return tab;
}

int fill_cdata(int nbr, COLUMN **tab) {
    int test;
    // Demander à l'utilisateur de saisir le nombre de valeurs pour la colonne
    int n;
    printf("Saisir le nombre de valeurs pour les colonnes\n");
    scanf("%d", &n);

    for (int i = 0; i < nbr; i++) {
        char titre[100]; // Allocation d'un espace pour stocker le titre

        // Demander à l'utilisateur de saisir le titre de la colonne
        printf("Saisir le titre de la %deme colonne\n", i + 1);
        scanf("%s", titre);

        // Allouer de l'espace pour stocker le titre et copier la saisie
        tab[i]->titre = malloc(strlen(titre) + 1);
        strcpy(tab[i]->titre, titre);


        // Demander à l'utilisateur de saisir les valeurs pour la colonne
        for (int j = 0; j < n; j++) {
            int val;
            printf("Saisir la %deme valeur de la %deme colonne\n", j + 1, i + 1);
            scanf("%d", &val);
            // Insérer la valeur dans la colonne
            test = insert_value(tab[i], val);
        }
    }
    return test;
}



void afficher_cdata (COLUMN ** tab, int nbr){
    for (int i = 0;i<nbr;i++){
        printf("%s\n",tab[i]->titre);
        print_col(tab[i]); // *(tab+i)
        printf("==============================================\n");
    }
}

void afficher_cdata_lignes(COLUMN ** tab, int nbr,int lim){
    for (int i = 0;i<nbr;i++){
        printf("%s\n",tab[i]->titre);
        for (int j=0;j<lim;j++){
            printf("[%d] %d\n",j,tab[i]->donnees[j]);
        }
        printf("==============================================\n");
    }
}


void afficher_cdata_col(COLUMN ** tab, int lim){
    afficher_cdata(tab,lim);
}

int ajouter_ligne(COLUMN ** tab, int nbr){
    int val,test;
    for (int i = 0;i<nbr;i++){
        printf("Saisir la valeur a ajoute a la derniere position de la colonne %d\n",i+1);
        scanf("%d",&val);
        test = insert_value(tab[i],val);
    }
    return test;
}

int delete_ligne(COLUMN ** tab, int nbr,int ind) {
        if (ind < (*tab)->taille_log) {
            for (int i = 0; i < nbr; i++) {
                for (int j = ind; j < tab[i]->taille_log - 1; j++) {
                    tab[i]->donnees[j] = tab[i]->donnees[j + 1];
                }
                tab[i]->taille_log--;
            }
            return 1;
        } else if(ind ==  (*tab)->taille_log) {
            for (int i = 0; i < nbr; i++) {
                tab[i]->taille_log--;
            }
            return 1;
        } else {
            return 0;
        }

}

/*int ajouter_col(COLUMN ** tab,int nbr){
    char titre [100];
    tab = realloc(tab,nbr +1);
    printf("Saisir le titre de la nouvelle colonne :\n");
    scanf("%s",titre);
    tab[nbr] = create_column(titre);
    tab[nbr]->taille_log = tab[nbr-1]->taille_log;
    tab[nbr]->taille_ph = tab[nbr-1]->taille_ph;


    int test;

    for (int j = 0; j < nbr; j++) {
        int val;
        printf("Saisir la %deme valeur de la nouvelle colonne\n", j + 1);
        scanf("%d", &val);
        // Insérer la valeur dans la colonne
        test = insert_value(tab[nbr], val);
    }
    return test;
}
*/
void supr_col(COLUMN ** tab, int* nbr, int ind) {
    if (ind < 0 || ind >= *nbr) {
        printf("La colonne na pas ete supprimee en raison dindice invalide\n");
    }

    delete_column(&tab[ind]); // Supprimer la colonne à l'index ind

    for (int i = ind; i < *nbr - 1; i++) {
        tab[i] = tab[i + 1];
    }

    (*nbr)--;
    printf("La colonne a ete supprimee\n");
}

int renommer_col(COLUMN ** tab,int ind){
    char s[100];
    printf("Saisir le titre de la colonne indice %d :\n",ind);
    scanf("%s",s);
    strcpy(tab[ind]->titre, s);
}

int val_existance(COLUMN ** tab,int nbcol,int val){ //nbr=nbcol
    for(int i=0;i<nbcol;i++){ //parcours les col
        for (int j=0;j<tab[i]->taille_log;j++){ //parcours les lig
            if (tab[i]->donnees[j]==val)
            {
                return 1;
            }

        }
    }
    return 0;
}

int remplacer_val(COLUMN ** tab,int pos_col,int pos_lig,int val,int nbr){
    if (pos_col<nbr && pos_lig < (*tab)->taille_log && pos_col >= 0 && pos_lig>=0 ){
        tab[pos_col]->donnees[pos_lig]=val;
        return 1;
    }
    return 0;

}

void afficher_titres(COLUMN ** tab,int nbcol){
    for(int i=0;i<nbcol;i++){
        printf("Le titre de la colonne à lindice %d est : %s\n",i,tab[i]->titre);
    }
}


void afficher_nb_lignes(COLUMN ** tab){
    printf("Ce CdataFrame contient %d lignes.\n",(*tab)->taille_log+1);
}

void afficher_nb_col(int nbr){
    printf("Ce CdataFrame contient %d colonnes.\n",nbr);
}


int occ_val_cdata(COLUMN ** tab,int nbcol,int val){ //nbr=nbcol
    int cpt = 0;
    for(int i=0;i<nbcol;i++){ //parcours les col
        for (int j=0;j<tab[i]->taille_log;j++){ //parcours les lig
            if (tab[i]->donnees[j]==val)
            {
                cpt++;
            }

        }
    }
    return cpt;
}

int sup_val_cdata(COLUMN ** tab,int nbcol,int val){
    int cpt = 0;
    for(int i=0;i<nbcol;i++) {//parcours les col
        cpt += sup_x(tab[i],val);
    }
    return cpt;
}

int inf_val_cdata(COLUMN ** tab,int nbcol,int val){
    int cpt = 0;
    for(int i=0;i<nbcol;i++) {//parcours les col
        cpt += inf_x(tab[i],val);
    }
    return cpt;
}




void afficher_menu() {
    printf("Menu :\n");
    printf("1. Alimentation\n");
    printf("2. Affichage\n");
    printf("3. Operations usuelles\n");
    printf("4. Analyse et statistiques\n");
    printf("0. Quitter\n");
}