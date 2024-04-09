#include <stdio.h>
#include "fonctions.h"


int main(){
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
        printf("La valeur à la position %d est : %d\n", z, pos);
    } else {
        printf("La position %d est en dehors des limites de la colonne.\n", z);
    }

    return 0;
}

