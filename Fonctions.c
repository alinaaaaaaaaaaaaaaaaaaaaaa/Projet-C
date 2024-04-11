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
    for (int i = 0; i < nbr; i++) {
        char titre[100]; // Allocation d'un espace pour stocker le titre

        // Demander à l'utilisateur de saisir le titre de la colonne
        printf("Saisir le titre de la %deme colonne\n", i + 1);
        scanf("%s", titre);

        // Allouer de l'espace pour stocker le titre et copier la saisie
        tab[i]->titre = malloc(strlen(titre) + 1);
        strcpy(tab[i]->titre, titre);


        // Demander à l'utilisateur de saisir le nombre de valeurs pour la colonne
        int n;
        printf("Saisir le nombre de valeurs pour la colonne %d\n", i + 1);
        scanf("%d", &n);

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

