/*
Project : CDataframe par Alina Frederic et Abdel Derra.
Ce fichier contient les corps des fonctions qui nous permettent de manipuler les colonnes.
Ces fonctions sont aussi utilisées dans l'implémention des fonctions du CdataFrame.
*/

#include "column.h"
#include <stdlib.h>
#include <stdio.h>

/*
 Créer une colonne en prenant en paramètre le titre qu'obtiendra cette dernière.
 On retourne un pointeur de type COLUMN qui pointera la colonne créer.
 */
COLUMN * create_column(char * titre){
    COLUMN* ptr_col;
    ptr_col = (COLUMN *)malloc(sizeof(COLUMN)); // Allocation d'espace pour avoir une colonne
    ptr_col->titre = titre;
    ptr_col->taille_ph = 0;
    ptr_col->taille_log = 0;
    return ptr_col;
}

/*
 Insère une valeur dans la colonne plus précisément dans donnees, en prenant en paramètre la colonne dans laquelle on veut ajouter et la valeur que l'on souhaite y ajouter.
 On retourne un entier : 1 si la valeur a bien été ajouté et 0 dans le cas contraire.
 */

int insert_value(COLUMN* col, int value){
    if (col->taille_ph == 0 ){ // vide
        col->donnees = (int*)malloc(256*sizeof(int));
        col->taille_ph+=256;
    }
    if (col->taille_log==col->taille_ph){ // pas assez d'espace pour ajouter
        col->donnees = realloc(col->donnees,col->taille_ph+256);
        col->taille_ph+=256;
    }
    if (col->taille_ph>col->taille_log && col->taille_ph!=0){
        col->donnees[col->taille_log]=value; // on ajoute la valeur
        col->taille_log++;
        return 1;
    }
    return 0;

}

/*
 Supprime la colonne prise paramètre.
 On ne retourne rien car le but est de libérer tout l'espace contenu dans celle-ci.
 */
void delete_column(COLUMN *col) {
    if (col != NULL) {
        free(col->donnees);
        free(col);
    }
}


/*
 Affiche la colonne que l'on passe en paramètre.
 On ne retourne rien car le but est d'afficher.
 */
void print_col(COLUMN* col){
    for (int i=0;i<col->taille_log;i++){
        printf("[%d] %d\n",i,col->donnees[i]);
    }
}


//4.1.5
/*
 Permet de connaitre le nombre d'occurence d'une valeur prise paramètre dans la colonne voulue, également prise en paramètre. .
 On retourne l'entier qui donnera le nombre exacte d'occurence d'une valeur dans une colonne choisie.
 */
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

/*
 Permet de connaitre dans la colonne voulu prise en paramètre la valeur à une certaine position également prise en paramètre.
 On retourne un entier qui réprésente la valeur se trouvant à la position voulu ou -1 si la position dépasse la taille logique du tableau.
 */
int pos_x(COLUMN* col, int x) {
    if (x >= 0 && x < col->taille_log) {
        return col->donnees[x]; // Retourne la valeur à la position x
    } else {
        return -1;
    }
}

/*
 Permet de connaitre le nombre de valeurs supérieures à une certaine valeur prise en paramètre dans une colonne, également prise en paramètre.
 On retourne un entier qui réprésente le nombre de valeurs qui y seront supérieures.
 */
int sup_x(COLUMN* col, int x) {
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])>x)
        {
            cpt+=1;// Augmente le compteur si la valeur est supérieure à x
        }
    }
    return cpt;
}

/*
 Permet de connaitre le nombre de valeurs inférieures à une certaine valeur donné en paramètre dans une colonne, également donnée en paramètre.
 On retourne un entier qui réprésente le nombre de valeurs qui y seront inférieures.
 */
int inf_x(COLUMN* col, int x) {
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])<x)
        {
            cpt+=1; // Augmente le compteur si la valeur est inférieure à x
        }
    }
    return cpt;
}

/*
 Permet de connaitre le nombre de valeurs égale à une certaine valeur prise en paramètre dans une colonne, également prise en paramètre.
 On retourne un entier qui réprésente le nombre de valeurs qui y seront égales.
 */
int equal_x(COLUMN * col,int x){
    int cpt=0;
    for (int i=0;i<col->taille_log;i++){
        if ((col->donnees[i])==x)
        {
            cpt+=1; // Augmente le compteur si la valeur est égale à x
        }
    }
    return cpt;
}

// Fonction avancées

COLUMN_AVC * create_column_avc(char * titre){
    COLUMN_AVC * ptr_col;
    ptr_col = (COLUMN_AVC *)malloc(sizeof(COLUMN_AVC )); // Allocation d'espace pour avoir une colonne
    ptr_col->titre = titre;
    ptr_col->taille_ph = 0;
    ptr_col->taille_log = 0;
    ptr_col->valid_index = 0;
    ptr_col->index = NULL;
    ptr_col->sort_dir = 0;
    return ptr_col;
}

/* Partitionnement des elements du tableau d'index d'une colonne
 On divise en deux la colonne prise en paramètre, avec en paramètre gauche qui est l'index du début et droite l'index de fin
 Le dernier élément de la colonne est le pivot et compare tous les éléments avec ce dernier. Si l'élément est plus petit on déplace sa position dans le tableau d'index à gauche de l'indice du pivot mais si celui-ci est plus grand on le met à droite.
 On retourne l'indice du pivot bien placé.
 */
int partition (COLUMN_AVC * col,int gauche,int droite) {

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

/*
Permet de trier la colonne prise en paramètre par ordre croissant, avec en paramètre gauche qui est l'index du début et droite l'index de fin.
On ne retourne rien car on modifie le tableau.
 */
void quicksort (COLUMN_AVC * col,int gauche,int droite ){
    if (gauche < droite) { // plus petit au plus grand
        int pi = partition(col, gauche, droite);
        quicksort(col, gauche, pi - 1);
        quicksort(col, pi + 1, droite);
    }
}

/*
Permet de trier la colonne prise en paramètre par ordre croissant ou décroissant selon la valeur sort_dir prise en paramètre.
On ne retourne rien car on modifie le tableau selon le tri demandé.
 */
void sort(COLUMN_AVC * col, int sort_dir){

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
        if (col->valid_index == 0) { // Colonnes non triéee
            quicksort(col, 0, col->taille_log - 1);
            col->valid_index = 1; // On a trié

        }
        else if ( col->valid_index==-1)  // colonne partiellement triée
        {
            // tri par insertion en ordre croissant
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
            // Inverser les index pour le tri descendant. Tri adapté.
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
                int k_value = col->donnees[k_index];

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

/*
Permet d'afficher les valeurs de la colonne prise en paramètre selon le tableau d'index.
On ne retourne rien car on affiche uniquement.
 */
void print_col_by_index(COLUMN_AVC *col){

    for (int i = 0; i< col->taille_log; i ++){
        printf("[%d] %d\n",i,col->donnees[col->index[i]]);
    }
}

/*
Permet de supprimer l'association d'un index à une colonne prise en paramètre et donc d'effacer la mémoire allouée pour le tableau d'index.
On ne retourne rien car on modifie index et valid_index.
*/
void erase_index(COLUMN_AVC *col){
    free(col->index);
    col->index = NULL;
    col->valid_index = 0;
}

/*
Permet de vérifier l'existence d'un valid_index dans une colonne prise en paramètre.
Retourne 1 si valid_index existe, 0 s'il n'existe pas et -1 s'il est invalide.
 */
int check_index(COLUMN_AVC *col) {

    if (col->valid_index == 1) {
        printf("L'index existe\n");
        return 1;
    } else if (col->valid_index == 0) {
        printf("L'index n'existe pas \n");
        return 0;
    } else {
        printf("L'index est invalide \n");
        return -1;
    }
}

/*
Permet de mettre à jour le tableau d'index de la colonne prise en paramètre.
Ne retourne rien car on modifie uniquement.
 */
void update_index(COLUMN_AVC *col){
    sort(col,col->sort_dir);
}

/*
Permet à l'aide d'une recherche dichotomique de rechercher une valeur prise en paramètre dans une colonne également prise en paramètre.
Retourne 1 si la valeur existe dans le cas contraire on retourne 0.
*/
int search_value_in_column(COLUMN_AVC *col, int val){

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

