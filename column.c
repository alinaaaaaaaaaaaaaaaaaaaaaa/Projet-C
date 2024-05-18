
#include "column.h"
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

void delete_column(COLUMN *col) {
    if ( col != NULL) {
        free((col)->donnees);
        free(col);

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


// Fonction avancées

// Partionnement des elements du tableau d'index d'une colonne
int partition (COLUMN* col,int gauche,int droite) {

    int pivot = col->donnees[droite];
    int i = gauche - 1;

    for (int j = gauche; j < droite; j++) {
        if (col->donnees[j] <= pivot) {
            i++;
            int tmp = col->index[i];
            col->index[i] = col->index[j];
            col->index[j] = tmp;
        }
    }
    int tmp = col->index[i + 1];
    col->index[i + 1] = col->index[droite];
    col->index[droite] = tmp;
    return i + 1;
}

void quicksort (COLUMN* col,int gauche,int droite ){
    if (gauche < droite) {
        int pi = partition(col, gauche, droite);
        quicksort(col, gauche, pi - 1);
        quicksort(col, pi + 1, droite);
    }
}

void sort(COLUMN* col, int sort_dir){

    col->index = (unsigned long long*) malloc(col->taille_log * sizeof(unsigned long long));
    if (!col->index) {
        fprintf(stderr, "Erreur d'allocation mémoire pour l'index.\n");
        return;
    }

    // Remplir le tableau d'index
    for (int i = 0; i < col->taille_log; i++) {
        col->index[i] = i;
    }

    if (sort_dir == 0) { // Trier en ascendant
        if (col->valid_index == 0) { // Colonne non triée
            quicksort(col, 0, col->taille_log - 1);
            col->valid_index = 1; // On a trié

        }
        else if ( col->valid_index==-1)  // colonne partiellement triée
        {
            // tri par insertion
            for (int i = 1; i < col->taille_log; i++) {
                unsigned long long k_index = col->index[i]; // Récupère l'indice à partir de l'index
                int k_value = col->donnees[k_index]; // Récupère la valeur correspondante à cet indice dans les données

                int j = i - 1;

                while (j >= 0 && col->donnees[col->index[j]] > k_value) {
                    col->index[j + 1] = col->index[j];
                    j=j-1;
                }
                col->index[j + 1] = k_index; // Place l'indice à sa position correcte dans l'ordre croissant
            }
            col->valid_index = 1; // On a trié

        }
        else if ( col->valid_index==1){
            printf("Votree tableau est deja trié il ne sera pas modifié\n");
        }
        else{
            printf("Erreur.\n");
        }


    }
    else if (sort_dir==1){ // descendant
        if (col->valid_index == 0) { // Colonne non triée
            quicksort(col, 0, col->taille_log - 1);
            // Inverser les index pour le tri descendant
            for (int i = 0; i < col->taille_log / 2; i++) {
                unsigned long long tmp = col->index[i];
                col->index[i] = col->index[col->taille_log - 1 - i];
                col->index[col->taille_log - 1 - i] = tmp;
            }
            col->valid_index = 1;
        }
        else if ( col->valid_index==-1)  // colonne partiellement triée
        {
            // tri par insertion en ordre décroissant
            for (int i = 1; i < col->taille_log; i++) {
                unsigned long long k_index = col->index[i]; // Récupère l'indice à partir de l'index
                int k_value = col->donnees[k_index]; // Récupère la valeur correspondante à cet indice dans les données

                int j = i - 1;

                while (j >= 0 && col->donnees[col->index[j]] < k_value) { // Changement ici : < pour décroissant
                    col->index[j + 1] = col->index[j];
                    j--;
                }
                col->index[j + 1] = k_index; // Place l'indice à sa position correcte dans l'ordre décroissant
            }
            col->valid_index = 1;
        }
        else if ( col->valid_index==1){
            printf("Votree tableau est deja trié il ne sera pas modifié");
        }
        else
        {
            printf("Erreur.");
        }


    }else{
        printf("Valeur incorrect");
    }

}

void print_col_by_index(COLUMN *col){

    for (int i = 0; i< col->taille_log; i ++){
        printf("[%d] %d\n",i,col->donnees[col->index[i]]);
    }
}

void erase_index(COLUMN *col){
    free(col->index);
    col->index = NULL;
    col->valid_index = 0;
}


int check_index(COLUMN *col){

    if (col->valid_index==1){
        printf("L'index existe\n");
    }
    else if (col->valid_index==0){
        printf("L'index n'existe pas \n");
    }
    else{
        printf("L'index est invalide \n");
    }
}

void update_index(COLUMN *col){
    sort(col,col->sort_dir);
}

int search_value_in_column(COLUMN *col, int val){

    int arret=0,g=0,pos,m;
    int d = col->taille_log - 1;

    if (col->valid_index==1){
        do {
            m = (d + g) / 2; // calcul de l'indice central
            if(val == col->donnees[col->index[m]]) {
                arret = 1; pos = m;
            }
            else {
                if(val > col->donnees[col->index[m]])
                    g = m + 1; // aller vers la moitié supérieure
                else
                    d = m - 1; // aller vers la moitié inférieure
                if(g > d) {
                    arret = 1; pos = -1;}
            }
        }while(arret != 1);

        if (pos == -1) {
            return 0;
        }else{
            return 1;
        }

    }
}


