#include <stdio.h>
#include "Fonctions.h"
//#include "Fonctions.c"

int main(){
    printf("hello world\n");
    COLUMN * test ;
    test = create_column("My column");
    printf("%s %d",test ->titre,test->taille_ph);
    return 0;
}
