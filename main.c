#include <stdio.h>
#include "fonctions.h"



int main(){
  /*  printf("hello world\n");
    COLUMN * mycol ;
    mycol = create_column("My column");
    printf("%s %d\n",mycol ->titre,mycol->taille_ph);
    printf("%s %d\n",mycol ->titre,mycol->taille_ph);
    printf("%s %d\n",mycol ->titre,mycol->taille_ph);

    int val = 5;

    if (insert_value(mycol, val)) {
        printf("Value added successfully to my column\n");
    }
    else
    {
        printf("Error adding value to my column\n");

    }
    delete_column(&mycol);
    mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);

    printf("Saisir une valeur:\n");
    int y;
    scanf("%d",&y);
    int occ;
    occ=nbr_occ(mycol,y); //nbr d'occ de y
    printf("Nombre d'occurences :%d\n",occ);

    printf("Saisir une position:\n");
    int z;
    int pos;
    scanf("%d",&z);
    pos=pos_x(mycol,z);
    if (pos!= NULL) {
        printf("La valeur a la position %d est : %d\n", z, pos);
    } else {
        printf("La position %d est en dehors des limites de la colonne.\n", z);
    }

    printf("Saisir une valeur:\n");
    int a;
    scanf("%d",&a);
    int sup;
    sup=sup_x(mycol, a);
    printf("Le nombre de valeurs supérieurs à %d est de %d",a,sup);

    printf("Saisir une valeur:\n");
    int b;
    scanf("%d",&b);
    int inf;
    inf=inf_x(mycol,b);
    printf("Le nombre de valeurs inférieur à %d est de %d",b,inf);

    printf("\nSaisir une valeur:\n");
    int c;
    scanf("%d",&c);
    int equal;
    equal=equal_x(mycol,c);
    printf("Le nombre de valeurs égales à %d est de %d",c,equal);



    */
    int nbr;
    COLUMN ** tab;
    printf("Saisir le nombre de colonne du cdata\n");
    scanf("%d",&nbr);
    tab = create_cdata(nbr);
    if (fill_cdata(nbr,tab)) {
        printf("cdata remplis\n");
    }else {
        printf("pas rempli\n");
    }
    afficher_cdata(tab,nbr);
/*
    int n;
    printf("Saisir le nombre de lignes a afficher :\n");
    scanf("%d",&n);
    afficher_cdata_lignes(tab,nbr,n);

    if (ajouter_ligne(tab,nbr)) {
        printf("ligne ajoutee\n");
    }else {
        printf("pas ajoutee\n");
    }
    afficher_cdata(tab,nbr);
    int l;
    printf("Saisir l'indice de la ligne a supprimer :");
    scanf("%d",&l);
    if (delete_ligne(tab,nbr,l)) {
        printf("ligne supprimee\n");
    }else {
        printf("pas supprimee\n");
    }
    afficher_cdata(tab,nbr);*/


    /*if (ajouter_col(tab,nbr)) {
        printf("colonne ajoutée\n");
    }else {
        printf("colonne supprimee\n");
    }
    afficher_cdata(tab,nbr);*/


    /*int ind;
    printf("Saisir l'indice de la colonne a supprimer :");
    scanf("%d",&ind);
    if (supr_col(tab,&nbr,ind)) {
        printf("colonne supprimee\n");
    }else {
        printf("pas supprimee\n");
    }

    afficher_cdata(tab,nbr);*/

    /*int indice;
    printf("Saisir l'indice de la colonne dont le titre doit être modifié :");
    scanf("%d",&indice);
    if (renommer_col(tab,indice)) {
        printf("titre modifié\n");
    }else {
        printf("titre non modifié\n");
    }

    afficher_cdata(tab,nbr);*/

    /*int valeur;
    printf("Saisir la valeur à trouver si elle existe dans le Cdata :");
    scanf("%d",&valeur);
    if (val_existance(tab,nbr,valeur)){
        printf("valeur existante\n");
    }else {
        printf("valeur non existante\n");
    }*/


    /*int pos_col,pos_lig,nv_valeur;
    printf("Saisir l'indice de la colonne de la valeur à modifié:");
    scanf("%d",&pos_col);
    printf("Saisir l'indice de la ligne de la valeur à modifié:");
    scanf("%d",&pos_lig);
    printf("Saisir la valeur qui doit remplacer celle à la %d col et %d lig:",pos_col,pos_lig);
    scanf("%d",&nv_valeur);

    if (remplacer_val(tab,pos_col,pos_lig,nv_valeur,nbr)){
        printf("valeur modifié avec succès\n");
    }else {
        printf("la valeur ne peut être modifié\n");
    }

    afficher_cdata(tab,nbr);*/

    afficher_titres(tab,nbr);

    return 0;
}










