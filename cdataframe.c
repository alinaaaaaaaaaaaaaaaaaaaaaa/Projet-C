/*
Projet CdataFrame par Alina Frederic et Abdel Derra.
Ce fichier contient les corps des fonctions qui nous permettent de manipuler le cdataframe.
*/



#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Creer nbr colonnes dans un cdataframe en prenant en paramètre un pointeur sur un CdataFrame et le nombre de colonnes de ce dernier.
//Il retourne un pointeur sur le CdataFrame.
CDATAFRAME * create_cdata(CDATAFRAME * cdata,int nbr){
    cdata->nombre_elem = nbr;
    cdata->columns = (COLUMN**) malloc(cdata->nombre_elem*sizeof (COLUMN*)); // Allocation dymanique des colonnes
    for (int i=0; i <cdata->nombre_elem;i++){
        cdata->columns[i] = create_column("");
    }
    return cdata;
}

//Creer une cdata vide en ne prenant rien en paramètres  il retourne un pointeur sur le cdataframe créé
CDATAFRAME * create_empty_cdata() {
    CDATAFRAME * cdata;
    cdata = (CDATAFRAME *) malloc(sizeof (CDATAFRAME)); //Allocation dynamique du cdataframe
    cdata->nombre_elem = 0;
    cdata->columns = NULL;
    return cdata;
}

//Remplis un cdataframe de valeur saisies par l'utilisateur, en prenant en paramètre un pointeur sur le cdataframe
//Il retourne 1 si le cdataframe est bien remplis et 0 sinon.
int fill_cdata(CDATAFRAME* cdata) {
    int test;
    int n;
    printf("Saisir le nombre de valeurs pour les colonnes\n");
    scanf("%d", &n);

    for (int i = 0; i < cdata->nombre_elem; i++) {
        char titre[100]; // Allocation d'un espace pour stocker le titre

        printf("Saisir le titre de la %deme colonne\n", i + 1);
        scanf("%s", titre);

        // Allouer de l'espace pour stocker le titre et copier la saisie
        cdata->columns[i]->titre = malloc(strlen(titre) + 1);
        strcpy(cdata->columns[i]->titre, titre);


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

//Permet de remplir en dur un cdataframe en prenant en paramètres un pointeur sur un pointeur de cdataframe
//Il retourne ce pointeur.
CDATAFRAME * auto_fill(CDATAFRAME * cdata){

    cdata = create_empty_cdata();
    cdata = create_cdata(cdata,3);


    // Remplissage des titles de colonne
    cdata->columns[0] = create_column("col1");
    cdata->columns[1] = create_column("col2");
    cdata->columns[2] = create_column("col3");


    // Remplissage des valeurs
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!insert_value(cdata->columns[i], i + j)) {
                printf("Erreur lors de l'insertion de la valeur dans la colonne %d.\n", i + 1);
            }
        }
    }
    return cdata;
}

//Permet l'affichage entier d'un cdataframe,en prenant en paramètre un pointeur sur cdataframe.
//Il ne retourne rien car il ne contient que des printf.
void print_cdata (CDATAFRAME* cdata){
    printf("\n==============================================\n");
    // affichage des titres des colonnes
    for (int i = 0;i<cdata->nombre_elem;i++) {
        printf("%s\t", cdata->columns[i]->titre);
    }
    printf("\n");

    COLUMN ** data = cdata->columns;
    // affichage des lignes du cdataframe
    for (int i = 0; i < data[0]->taille_log;++i) {
        for (int j = 0; j < cdata->nombre_elem; ++j) {
            printf("%d\t", data[j]->donnees[i]);
        }
        printf("\n");
    }


    printf("\n==============================================\n");
}

//Permet l'affichage d'une partie des lignes d'un cdataframe en prenant en paramètre un pointeur sur cdataframe et le nombre de lignes à afficher.
//Il ne retourne rien car il ne contient que des printf.
void print_cdata_lines(CDATAFRAME* cdata,int lim){
    printf("\n==============================================\n");
    for (int i = 0;i<cdata->nombre_elem;i++) {
        printf(" %s      ", cdata->columns[i]->titre);
    }
    printf("\n");
    for (int i = 0;i<lim;i++) {
        for (int j = 0; j < cdata->nombre_elem; j++) {
            printf(" [%d] %d     ", i, cdata->columns[j]->donnees[i]);
        }
        printf("\n");
    }

    printf("\n==============================================\n");
}

//Permet l'affichage d'une partie des colonnes d'un cdataframe en prenant en paramètre un pointeur sur cdataframe et le nombre de colonnes à afficher.
//Il ne retourne rien car il ne contient que des printf.
void print_cdata_col(CDATAFRAME* cdata, int lim){
    printf("\n==============================================\n");
    for (int i = 0;i<lim;i++) {
        printf(" %s      ", cdata->columns[i]->titre);
    }
    printf("\n");
    for (int i = 0;i<cdata->nombre_elem;i++) {
        for (int j = 0; j < lim; j++) {
            printf(" [%d] %d     ", i, cdata->columns[j]->donnees[i]);
        }
        printf("\n");
    }

    printf("\n==============================================\n");
}

//Permet d'ajouter une lignes à la fin du cdataframe en prenant en paramètres un pointeur sur cdataframe.
//Il retoune 1 si la ligne a été bien ajouté et 0 sinon.
int add_line(CDATAFRAME* cdata){
    int val,test;
    for (int i = 0;i<cdata->nombre_elem;i++){
        printf("Saisir la valeur a ajoute a la derniere position de la colonne %d\n",i+1);
        scanf("%d",&val);
        test = insert_value(cdata->columns[i],val);
    }
    return test;
}

//Permet de supprimmer une lignes à la fin du cdataframe en prenant en paramètres un pointeur sur cdataframe et l'indice de la colonne à ajouter.
//Il retoune 1 si la ligne a été bien supprimé et 0 sinon.
int delete_line(CDATAFRAME* cdata,int ind) {
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

//Permet d'ajouter une colonne à la fin du cdataframe en prenant en paramètres un pointeur sur cdataframe et le titre de la nouvelle colonne.
//Il retoune 1 si la colonne a été bien ajouté et 0 sinon.
int add_col (CDATAFRAME * cdata, char * titre) {
    COLUMN * c = create_column(titre);

    if (cdata->nombre_elem == 0) {
        cdata->columns = (COLUMN **) malloc(sizeof(COLUMN *));
    } else {
        cdata->columns = (COLUMN **) realloc(cdata->columns, (sizeof (COLUMN *)) * (cdata->nombre_elem + 1));
    }

    // Si le realloc echoue
    if (!cdata->columns) {
        fprintf(stderr, "Ajout de colonne echoue\n");
        delete_column(c);
        return 0;
    }

    int val ;
    cdata->columns[cdata->nombre_elem] = c;
    cdata->nombre_elem += 1;

    cdata->columns[cdata->nombre_elem-1]->taille_log = cdata->columns[cdata->nombre_elem-2]->taille_log;

    for (int i = 0; i< cdata->columns[0]->taille_log;i++){
        printf("Saisir la %de valeur a ajoute dans la nouvelle colonne\n",i+1);
        scanf("%d",&val);
        insert_value(cdata->columns[cdata->nombre_elem-1], val);
    }

    return 1;
}

//Permet de supprimmer une colonne à la fin du cdataframe en prenant en paramètre un pointeur sur cdataframe et l'indice de la colonne à supprimmer.
//Il ne retoune rien.
void delete_col(CDATAFRAME* cdata, int ind) {
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

//Permet de renommer une colonne à un indice ind en prenant en paramètres un pointeur sur cdataframe et l'indice de la colonne.
//Il ne retourne rien.
void rename_col(CDATAFRAME* cdata,int ind){
    char s[100];
    printf("Saisir le titre de la colonne indice %d :\n",ind);
    scanf("%s",s);
    strcpy(cdata->columns[ind]->titre, s);

}

// Permet de recherhcer l'existance d'une valeur dans le cdataframe en prenant en paramètres un pointeur sur le cdataframe et la valeur à rechercher.
// Il retourne 1 si la valeur existe et 0 sinon.
int val_exist(CDATAFRAME* cdata,int val){ //cdata->nombre_elem=nbcol
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

//Permet d'accéder à une valeur du cdataframe et de la remplacer, en prenant en paramètres un pointeur sur cdataframe la nouvelle valeur et la position de l'ancienne valeur.
//Elle retourne 1 si la valeur a été remplacer et 0 sinon.
int replace_val(CDATAFRAME* cdata,int pos_col,int pos_lig,int val){
    if (pos_col<cdata->nombre_elem && pos_lig < (*cdata->columns)->taille_log && pos_col >= 0 && pos_lig>=0 ){
        cdata->columns[pos_col]->donnees[pos_lig]=val;
        return 1;
    }
    return 0;

}

//Permet d'afficher le titre des colonnes cdataframe en prenant en paramètres un pointeur sur cdataframe.
//Elle ne retourne rien car elle ne contient que des printf.
void print_titles(CDATAFRAME* cdata){
    for(int i=0;i<cdata->nombre_elem;i++){
        printf("Le titre de la colonne a lindice %d est : %s\n",i,cdata->columns[i]->titre);
    }
}

//Permet d'afficher le nombre de lignes du cdataframe en prenant en paramètres un pointeur sur cdataframe.
//Elle ne retourne rien car elle ne contient que des printf.
void print_nb_lines(CDATAFRAME* cdata){
    printf("Ce CdataFrame contient %d lines.\n",(*cdata->columns)->taille_log+1);
}

//Permet d'afficher le nombre de colonnes du cdataframe en prenant en paramètres un pointeur sur cdataframe
//Elle ne retourne rien car elle ne contient que des printf.
void print_nb_col(CDATAFRAME* cdata){
    printf("Ce CdataFrame contient %d colonnes.\n",cdata->nombre_elem);
}

//Permet de connaitre le nombre d'occurence d'une valeur du cdataframe en prenant en paramètres un pointeur sur cdataframe et la valeur en question.
// Elle retourne le nombre d'occurence de la valeur.
int occ_val_cdata(CDATAFRAME* cdata,int val){ //cdata->nombre_elem=nbcol
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++){ //parcours les colonnes
        for (int j=0;j<cdata->columns[i]->taille_log;j++){ //parcours les lignes
            if (cdata->columns[i]->donnees[j]==val)
            {
                cpt++;
            }

        }
    }
    return cpt;
}

//Permet de connaître le nombre de valeur supérieure à une valeur du cdataframe, en prenant en paramètres un pointeur sur cdataframe et la valeur en question.
//Elle retourne le nombre de valeurs supérieures à la valeur choisie.
int sup_val_cdata(CDATAFRAME* cdata,int val){
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++) {//parcours les col
        cpt += sup_x(cdata->columns[i],val);
    }
    return cpt;
}

//Permet de connaître le nombre de valeurs inférieures à une valeur du cdataframe en prenant en paramètres un pointeur sur cdataframe et la valeur en question.
//Elle retourne le nombre de valeurs inférieures à la valeur.
int inf_val_cdata(CDATAFRAME* cdata,int val){
    int cpt = 0;
    for(int i=0;i<cdata->nombre_elem;i++) {//parcours les col
        cpt += inf_x(cdata->columns[i],val);
    }
    return cpt;
}

//Permet de supprimer le cdataframe en prenant en paramètres un pointeur sur cdataframe.
//Elle ne retourne rien.
void delete_cdata(CDATAFRAME* cdata){
    if (cdata != NULL){
        for (int i = 0; i< cdata->nombre_elem ;i++) {
            delete_column(cdata->columns[i]);
        }
        free(cdata->columns);
        free(cdata);
    }
    else{
        printf("Le tableau est deja nul");
    }
}

//Fonction qui affiche le Menu.
//Elle ne retourne rien.
void print_menu() {
    printf("Menu :\n");
    printf("1. Alimentation\n");
    printf("2. Affichage\n");
    printf("3. Operations usuelles\n");
    printf("4. Analyse et statistiques\n");
    printf("0. Quitter\n");
}





