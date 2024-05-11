#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CDATAFRAME * create_cdata(int nbr){
    CDATAFRAME * cdata;
    cdata = (CDATAFRAME *) malloc(sizeof (CDATAFRAME));
    cdata->nombre_elem = nbr;
    cdata->columns = (COLUMN**) malloc(cdata->nombre_elem*sizeof (COLUMN*));
    for (int i=0; i <cdata->nombre_elem;i++){
        cdata->columns[i] = create_column("");
    }
    return cdata;
}

int fill_cdata(CDATAFRAME* cdata) {
    int test;
    // Demander à l'utilisateur de saisir le nombre de valeurs pour la colonne
    int n;
    printf("Saisir le nombre de valeurs pour les colonnes\n");
    scanf("%d", &n);

    for (int i = 0; i < cdata->nombre_elem; i++) {
        char titre[100]; // Allocation d'un espace pour stocker le titre

        // Demander à l'utilisateur de saisir le titre de la colonne
        printf("Saisir le titre de la %deme colonne\n", i + 1);
        scanf("%s", titre);

        // Allouer de l'espace pour stocker le titre et copier la saisie
        cdata->columns[i]->titre = malloc(strlen(titre) + 1);
        strcpy(cdata->columns[i]->titre, titre);


        // Demander à l'utilisateur de saisir les valeurs pour la colonne
        for (int j = 0; j < n; j++) {
            int val;
            printf("Saisir la %deme valeur de la %deme colonne\n", j + 1, i + 1);
            scanf("%d", &val);
            // Insérer la valeur dans la colonne
            test = insert_value(cdata->columns[i], val);
        }
    }
    return test;
}

void remplissage_en_dur(CDATAFRAME* cdata){

    cdata->nombre_elem = 3; // Nombre arbitraire
    cdata->columns = (COLUMN**)malloc(3 * sizeof(COLUMN*));
    if (cdata->columns == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour les colonnes du CDATAFRAME.\n");
        return ;
    }

    // Création et remplissage des colonnes
    for (int i = 0; i < 3; i++) {
        char titre[20];
        sprintf(titre, "Colonne %d", i + 1);
        cdata->columns[i] = create_column(titre);
        if (cdata->columns[i] == NULL) {
            printf("Erreur lors de la création de la colonne %d.\n", i + 1);
            return ;
        }
        for (int j = 0; j < 3; j++) {
            if (!insert_value(cdata->columns[i], (i + 1) * (j + 1))) {
                printf("Erreur lors de l'insertion de la valeur dans la colonne %d.\n", i + 1);
                return;
            }
        }
    }
    return;
}

void afficher_cdata (CDATAFRAME* cdata){
    for (int i = 0;i<cdata->nombre_elem;i++){
        printf("%s\n",cdata->columns[i]->titre);
        print_col(cdata->columns[i]); // *(cdata->columns+i)
        printf("==============================================\n");
    }
}


void afficher_cdata_lignes(CDATAFRAME* cdata,int lim){ //modifier affichage
    for (int i = 0;i<cdata->nombre_elem;i++){
        printf("%s\n",cdata->columns[i]->titre);
        for (int j=0;j<lim;j++){
            printf("[%d] %d\n",j,cdata->columns[i]->donnees[j]);
        }
        printf("==============================================\n");
    }
}


void afficher_cdata_col(CDATAFRAME* cdata, int lim){
    for (int i = 0;i<lim;i++){
        printf("%s\n",cdata->columns[i]->titre);
        print_col(cdata->columns[i]); // *(cdata->columns+i)
        printf("==============================================\n");
    }
}


int ajouter_ligne(CDATAFRAME* cdata){
    int val,test;
    for (int i = 0;i<cdata->nombre_elem;i++){
        printf("Saisir la valeur a ajoute a la derniere position de la colonne %d\n",i+1);
        scanf("%d",&val);
        test = insert_value(cdata->columns[i],val);
    }
    return test;
}


int delete_ligne(CDATAFRAME* cdata,int ind) {
    if (ind < (*cdata->columns)->taille_log) {
        for (int i = 0; i < cdata->nombre_elem; i++) {
            for (int j = ind; j < cdata->columns[i]->taille_log - 1; j++) {
                cdata->columns[i]->donnees[j] = cdata->columns[i]->donnees[j + 1];
            }
            cdata->columns[i]->taille_log--;
        }
        return 1;
    } else if(ind ==  (* cdata->columns)->taille_log) {
        for (int i = 0; i < cdata->nombre_elem; i++) {
            cdata->columns[i]->taille_log--;
        }
        return 1;
    } else {
        return 0;
    }

}
/*
int ajouter_col(CDATAFRAME* cdata){
    char titre [100];
    cdata->columns = realloc(cdata->columns,cdata->nombre_elem +1);
    printf("Saisir le titre de la nouvelle colonne :\n");
    scanf("%s",titre);
    cdata->columns[cdata->nombre_elem] = create_column(titre);
    cdata->columns[cdata->nombre_elem]->taille_log = cdata->columns[cdata->nombre_elem-1]->taille_log;
    cdata->columns[cdata->nombre_elem]->taille_ph = cdata->columns[cdata->nombre_elem-1]->taille_ph;


    int test;

    for (int j = 0; j < cdata->nombre_elem; j++) {
        int val;
        printf("Saisir la %deme valeur de la nouvelle colonne\n", j + 1);
        scanf("%d", &val);
        // Insérer la valeur dans la colonne
        test = insert_value(cdata->columns[cdata->nombre_elem], val);
    }
    return test;
} */

void supr_col(CDATAFRAME* cdata, int ind) {
    if (ind < 0 || ind >= cdata->nombre_elem) {
        printf("La colonne na pas ete supprimee en raison dindice invalide\n");
    }

    delete_column(&cdata->columns[ind]); // Supprimer la colonne à l'index ind

    for (int i = ind; i < cdata->nombre_elem - 1; i++) {
        cdata->columns[i] = cdata->columns[i + 1];
    }

    (cdata->nombre_elem)--;
    printf("La colonne a ete supprimee\n");
}

int renommer_col(CDATAFRAME* cdata,int ind){
    char s[100];
    printf("Saisir le titre de la colonne indice %d :\n",ind);
    scanf("%s",s);
    strcpy(cdata->columns[ind]->titre, s);
}

int val_existance(CDATAFRAME* cdata,int val){ //cdata->nombre_elem=nbcol
    for(int i=0;i<cdata->nombre_elem;i++){ //parcours les col
        for (int j=0;j<cdata->columns[i]->taille_log;j++){ //parcours les lig
            if (cdata->columns[i]->donnees[j]==val)
            {
                return 1;
            }

        }
    }
    return 0;
}

int remplacer_val(CDATAFRAME* cdata,int pos_col,int pos_lig,int val){
    if (pos_col<cdata->nombre_elem && pos_lig < (*cdata->columns)->taille_log && pos_col >= 0 && pos_lig>=0 ){
        cdata->columns[pos_col]->donnees[pos_lig]=val;
        return 1;
    }
    return 0;

}

void afficher_titres(CDATAFRAME* cdata,int nbcol){
    for(int i=0;i<nbcol;i++){
        printf("Le titre de la colonne a lindice %d est : %s\n",i,cdata->columns[i]->titre);
    }
}


void afficher_nb_lignes(CDATAFRAME* cdata){
    printf("Ce CdataFrame contient %d lignes.\n",(*cdata->columns)->taille_log+1);
}

void afficher_nb_col(CDATAFRAME* cdata){
    printf("Ce CdataFrame contient %d colonnes.\n",cdata->nombre_elem);
}


int occ_val_cdata(CDATAFRAME* cdata,int val){ //cdata->nombre_elem=nbcol
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++){ //parcours les col
        for (int j=0;j<cdata->columns[i]->taille_log;j++){ //parcours les lig
            if (cdata->columns[i]->donnees[j]==val)
            {
                cpt++;
            }

        }
    }
    return cpt;
}

int sup_val_cdata(CDATAFRAME* cdata,int val){
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++) {//parcours les col
        cpt += sup_x(cdata->columns[i],val);
    }
    return cpt;
}

int inf_val_cdata(CDATAFRAME* cdata,int val){
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++) {//parcours les col
        cpt += inf_x(cdata->columns[i],val);
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


