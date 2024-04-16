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


void afficher_cdata_col(COLUMN ** tab, int nbr){
    afficher_cdata(tab,nbr);
}

int ajouter_ligne(COLUMN ** tab, int nbr){
    int val,test;
    for (int i = 0;i<nbr;i++){
        printf("Saisir la valeur a ajouté a la derniere position de la colonne %d\n",i+1);
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

/*void ajouter_col(COLUMN ** tab,int nbr){
    char titre [100];
    tab = realloc(tab,(nbr +1)* sizeof(COLUMN**));
    printf("Saisir le titre de la nouvelle colonne :\n");
    scanf("%s",titre);
    tab[nbr] = create_column(titre);
    tab[nbr]->taille_log = tab[nbr-1]->taille_log;
    tab[nbr]->taille_ph = tab[nbr-1]->taille_ph;




    for (int j = 0; j < nbr; j++) {
        int val;
        printf("Saisir la %deme valeur de la nouvelle colonne\n", j + 1);
        scanf("%d", &val);
        // Insérer la valeur dans la colonne
        if (insert_value(tab[nbr], val)) {
            continue;
        }else {
            break;
        }
    }
} */

int supr_col(COLUMN ** tab, int* nbr, int ind) {
    if (ind < 0 || ind >= *nbr) {
        // Vérifier si l'indice est valide
        return 0; // Indice invalide
    }

    delete_column(tab[ind]); // Supprimer la colonne à l'index ind
    free(tab[ind]); // Libérer la mémoire de la colonne supprimée

    // Déplacer les colonnes suivantes vers la gauche pour combler l'espace
    for (int i = ind; i < *nbr - 1; i++) {
        tab[i] = tab[i + 1];
    }

    (*nbr)--; // Décrémenter le nombre de colonnes

    return 1; // Suppression réussie
}
