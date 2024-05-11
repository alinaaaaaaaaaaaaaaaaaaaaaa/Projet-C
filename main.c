#include <stdio.h>
#include "cdataframe.h"
#include <stdlib.h>

int main(){

    //Partie sur la colonne
    printf("hello world\n");
      COLUMN * mycol ;
      mycol = create_column("My column");
      printf("%s %d\n",mycol ->titre,mycol->taille_ph);

      int val = 5;

      if (insert_value(mycol, val)) {
          printf("Value added successfully to my column\n");
      }
      else
      {
          printf("Error adding value to my column\n");

      }
      insert_value(mycol, 52);
      insert_value(mycol, 44);
      insert_value(mycol, 15);
      print_col(mycol);

      printf("Saisir une valeur:\n");
      int y;
      scanf("%d",&y);
      int occ;
      occ=nbr_occ(mycol,y); //nbr d'occ de y
      printf("Nombre doccurences :%d\n",occ);

      printf("Saisir une position:\n");
      int z;
      int pos;
      scanf("%d",&z);
      pos=pos_x(mycol,z);
     /* if (pos!= NULL) {
          printf("La valeur a la position %d est : %d\n", z, pos);
      } else {
          printf("La position %d est en dehors des limites de la colonne.\n", z);
      } */

      printf("Saisir une valeur:\n");
      int a;
      scanf("%d",&a);
      int sup;
      sup=sup_x(mycol, a);
      printf("Le nombre de valeurs supérieurs à %d est de %d\n",a,sup);

      printf("Saisir une valeur:\n");
      int b;
      scanf("%d",&b);
      int inf;
      inf=inf_x(mycol,b);
      printf("Le nombre de valeurs inferieur à %d est de %d",b,inf);

      printf("\nSaisir une valeur:\n");
      int c;
      scanf("%d",&c);
      int equal;
      equal=equal_x(mycol,c);
      printf("Le nombre de valeurs egales à %d est de %d\n",c,equal);
      //delete_column(&mycol);


      //Partie sur le CDataframe
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
                                      printf("Le CdataFrame est deja initialise.\n");
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
                                  printf("Fonctionnalite a implementer");
                                  break;

                              case 0 :
                                  break;

                          }
                      } while (choix_alim>0 && choix_alim<=3  );
                  } else {
                      printf("Le CdataFrame nest pas initialise.\n");
                  }
                  break;
              case 2:
                  if (tab != NULL) {
                      int choix_aff;
                      int n;
                      do {
                          printf("Affichage\n");
                          printf("1. Afficher tout le CDataframe\n2. Afficher une partie des lignes du CDataframe selon une limite fournie par lutilisateur\n3. Afficher une partie des colonnes du CDataframe selon une limite fournie par lutilisateur\n0. Retour\n ");
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
                      printf("Le CdataFrame nest pas initialise.\n");
                  }
                  break;
              case 3:
                  printf("Operations usuelles :\n");
                  printf("1. Ajouter une ligne\n");
                  printf("2. Supprimer une ligne\n");
                  printf("3. Ajouter une colonne\n"); // En cours
                  printf("4. Supprimer une colonne\n");
                  printf("5. Renommer une colonne\n");
                  printf("6. Verifier lexistence dune valeur\n");
                  printf("7. Remplacer une valeur\n");
                  printf("8. Afficher les titres des colonnes\n");
                  printf("0. Retour\n");

                  int choix_operations;
                  printf("Entrez votre choix : ");
                  scanf("%d", &choix_operations);

                  switch (choix_operations) {
                      case 1:
                          if (tab != NULL) {
                              ajouter_ligne(tab, nbr_col);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 2:
                          if (tab != NULL) {
                              int index;
                              printf("Entrez lindice de la ligne a supprimer : ");
                              scanf("%d", &index);
                              delete_ligne(tab, nbr_col, index);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 3:
                          if (tab != NULL) {
                              //ajouter_col(tab, nbr_col); à modifier
                              continue;
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 4:
                          if (tab != NULL) {
                              int index;
                              printf("Entrez lindice de la colonne a supprimer : ");
                              scanf("%d", &index);
                              supr_col(tab, &nbr_col, index);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 5:
                          if (tab != NULL) {
                              int index;
                              printf("Entrez lindice de la colonne a renommer : ");
                              scanf("%d", &index);
                              renommer_col(tab, index);
                              printf("Le tire a bien ete renomme : ");

                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 6:
                          if (tab != NULL) {
                              int val;
                              printf("Entrez la valeur a rechercher : ");
                              scanf("%d", &val);
                              if (val_existance(tab,nbr_col,val)){
                                  printf("Valeur existante\n");
                                  }else {
                                  printf("Valeur non existante\n");
                              }
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 7:
                          if (tab != NULL) {
                              int pos_col, pos_lig, new_val;
                              printf("Entrez l'indice de la colonne : ");
                              scanf("%d", &pos_col);
                              printf("Entrez l'indice de la ligne : ");
                              scanf("%d", &pos_lig);
                              printf("Entrez la nouvelle valeur de la colonne indice %d et ligne indice %d : ",pos_col,pos_lig);
                              scanf("%d", &new_val);
                              remplacer_val(tab, pos_col, pos_lig, new_val, nbr_col);
                              printf("La valeur a ete remplace\n");
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 8:
                          if (tab != NULL) {
                              afficher_titres(tab, nbr_col);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
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
                  printf("4. Supprerieur à une valeur\n");
                  printf("5. Inférieures à une valeur\n");
                  printf("0. Retour\n");

                  int choix_analyse;
                  printf("Entrez votre choix : ");
                  scanf("%d", &choix_analyse);

                  switch (choix_analyse) {
                      case 1:
                          if (tab != NULL) {
                              afficher_nb_lignes(tab);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 2:
                          if (tab != NULL) {
                              afficher_nb_col(nbr_col);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 3:
                          if (tab != NULL) {
                              int val,nb_occ;
                              printf("Entrez la valeur à rechercher : ");
                              scanf("%d", &val);
                              nb_occ = occ_val_cdata(tab,nbr_col,val);
                              printf("le nombre doccurences de %d est %d\n",val,nb_occ);
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 4:
                          if (tab != NULL) {
                              int val,nb_sup;
                              printf("Entrez la valeur seuil : ");
                              scanf("%d", &val);
                              nb_sup = sup_val_cdata(tab,nbr_col,val);
                              printf("le nombre de valeur supérieur a %d est %d\n",val,nb_sup); ;
                          } else {
                              printf("Le CdataFrame nest pas initialise.\n");
                          }
                          break;
                      case 5:
                          if (tab != NULL) {
                              int val,nb_inf;
                              printf("Entrez la valeur seuil : ");
                              scanf("%d", &val);
                              nb_inf = inf_val_cdata(tab,nbr_col,val);
                              printf("le nombre de valeur inferieur a %d est %d\n",val,nb_inf); ;
                          } else {
                              printf("Le CdataFrame nest pas initialisé.\n");
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


      if (tab != NULL) {
          for (int i = 0; i < nbr_col; i++) {
              delete_column(&tab[i]);
          }
          free(tab);
      }
      printf("Le tableau a ete libere!");
    return 0;
}

















