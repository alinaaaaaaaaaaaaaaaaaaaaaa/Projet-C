#include <stdio.h>
#include "fonctions.h"
#include <stdlib.h>



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

    afficher_cdata(tab,nbr);
    afficher_titres(tab,nbr);
    int research,nb_inf;
    printf("Saisir la valeur à trouver si elle existe dans le Cdata :\n");
    scanf("%d",&research);
    nb_inf = inf_cdata(tab,nbr,research);
    printf("le nombre de valeur inferieur a %d est %d\n",research,nb_inf); */




    COLUMN** tab = NULL;
    int nbr_col = 0;
    int choix;

    do {
        afficher_menu();
        printf("Entrez votre choix : \n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (tab == NULL) {
                    int choix_alim;
                    do {
                        printf("Alimentation\n");
                        printf("1. Creation de un CDataframe vide\n2. Remplissage du CDataframe a partir de saisies utilisateurs\n3. Remplissage en dur du CDataframe\n0. Retour\n ");
                        printf("Entrez votre choix : ");
                        scanf("%d", &choix_alim);
                        switch (choix_alim) {
                            case 1:
                                if (tab == NULL) {
                                    printf("Saisir le nombre de colonne du cdata\n");
                                    scanf("%d",&nbr_col);
                                    tab = create_cdata(nbr_col);
                                    printf("Le CdataFrame vide a ete cree.\n");
                                } else {
                                    printf("Le CdataFrame est déjà initialisé.\n");
                                }
                                break;

                            case 2:
                                if (fill_cdata(nbr_col,tab)) {
                                    printf("Le CdataFrame a ete remplis\n");
                                }else {
                                    printf("Le CdataFrame n'a pas ete remplis\n");
                                }
                                break;

                            case 3:
                                printf("Fonctionnalité a implementer");
                                break;

                            case 0 :
                                break;

                        }
                    } while (choix_alim>0 && choix_alim<=3  );
                } else {
                    printf("Le CdataFrame est déjà initialisé.\n");
                }
                break;
            case 2:
                if (tab != NULL) {
                    int choix_aff;
                    int n;
                    do {
                        printf("Affichage\n");
                        printf("1. Afficher tout le CDataframe\n2. Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur\n3. Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur\n0. Retour\n ");
                        printf("Entrez votre choix : ");
                        scanf("%d", &choix_aff);
                        switch (choix_aff) {
                            case 1:
                                afficher_cdata(tab,nbr_col);
                                break;

                            case 2:
                                printf("Saisir le nombre de lignes a afficher :\n");
                                scanf("%d",&n);
                                afficher_cdata_lignes(tab,nbr_col,n);
                                break;

                            case 3:
                                printf("Saisir le nombre de colonnes a afficher :\n");
                                scanf("%d",&n);
                                afficher_cdata_col(tab,n);
                                break;

                            case 0 :
                                break;

                        }
                    } while (choix_aff<0 || choix_aff >3  );
                } else {
                    printf("Le CdataFrame n'est pas initialisé.\n");
                }
                break;
            case 3:
                printf("Opérations usuelles :\n");
                printf("1. Ajouter une ligne\n");
                printf("2. Supprimer une ligne\n");
                printf("3. Ajouter une colonne\n");
                printf("4. Supprimer une colonne\n");
                printf("5. Renommer une colonne\n");
                printf("6. Vérifier l'existence d'une valeur\n");
                printf("7. Remplacer une valeur\n");
                printf("8. Afficher les titres des colonnes\n");
                // Ajoutez d'autres options si nécessaire
                printf("0. Retour\n");
                int choix_operations;
                printf("Entrez votre choix : ");
                scanf("%d", &choix_operations);
                switch (choix_operations) {
                    case 1:
                        if (tab != NULL) {
                            ajouter_ligne(tab, nbr_col);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 2:
                        if (tab != NULL) {
                            int index;
                            printf("Entrez l'indice de la ligne à supprimer : ");
                            scanf("%d", &index);
                            delete_ligne(tab, nbr_col, index);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 3:
                        if (tab != NULL) {
                            //ajouter_col(tab, nbr_col);
                            continue;
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 4:
                        if (tab != NULL) {
                            int index;
                            printf("Entrez l'indice de la colonne à supprimer : ");
                            scanf("%d", &index);
                            supr_col(tab, &nbr_col, index);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 5:
                        if (tab != NULL) {
                            int index;
                            printf("Entrez l'indice de la colonne à renommer : ");
                            scanf("%d", &index);
                            renommer_col(tab, index);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 6:
                        if (tab != NULL) {
                            int val;
                            printf("Entrez la valeur à rechercher : ");
                            scanf("%d", &val);
                            val_existance(tab, nbr_col, val);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 7:
                        if (tab != NULL) {
                            int pos_col, pos_lig, new_val;
                            printf("Entrez la position de la colonne : ");
                            scanf("%d", &pos_col);
                            printf("Entrez la position de la ligne : ");
                            scanf("%d", &pos_lig);
                            printf("Entrez la nouvelle valeur : ");
                            scanf("%d", &new_val);
                            remplacer_val(tab, pos_col, pos_lig, new_val, nbr_col);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 8:
                        if (tab != NULL) {
                            afficher_titres(tab, nbr_col);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 0:
                        break;
                    default:
                        printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
                }
                break;
            case 4:
                printf("Analyse et statistiques :\n");
                printf("1. Afficher le nombre de lignes\n");
                printf("2. Afficher le nombre de colonnes\n");
                printf("3. Occurrence d'une valeur\n");
                printf("4. Supprimer une valeur\n");
                printf("5. Inférieures à une valeur\n");
                // Ajoutez d'autres options si nécessaire
                printf("0. Retour\n");
                int choix_analyse;
                printf("Entrez votre choix : ");
                scanf("%d", &choix_analyse);
                switch (choix_analyse) {
                    case 1:
                        if (tab != NULL) {
                            afficher_nb_lignes(tab);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 2:
                        if (tab != NULL) {
                            afficher_nb_col(nbr_col);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 3:
                        if (tab != NULL) {
                            int val;
                            printf("Entrez la valeur à rechercher : ");
                            scanf("%d", &val);
                            occ_val_cdata(tab, nbr_col, val);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 4:
                        if (tab != NULL) {
                            int val;
                            printf("Entrez la valeur à supprimer : ");
                            scanf("%d", &val);
                            supp_val_cdata(tab, nbr_col, val);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 5:
                        if (tab != NULL) {
                            int val;
                            printf("Entrez la valeur seuil : ");
                            scanf("%d", &val);
                            inf_val_cdata(tab, nbr_col, val);
                        } else {
                            printf("Le CdataFrame n'est pas initialisé.\n");
                        }
                        break;
                    case 0:
                        break;
                    default:
                        printf("Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n");
                }
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 4.\n");
        }
    } while (choix != 0);

    // Libération de la mémoire allouée pour le CdataFrame
    if (tab != NULL) {
        for (int i=0; i < nbr_col; i++){
            delete_column(&tab[i]);
        }
        free(tab);
    }

    return 0;
}










