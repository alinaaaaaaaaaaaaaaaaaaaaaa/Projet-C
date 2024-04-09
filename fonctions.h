// /fichier header contenant les types, constantes et prototypes des fonctions


#ifndef CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
#define CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H


typedef struct {
    char *titre;
    int *donnes;
    int taille_log;
    int taille_ph;
}COLUMN ;

COLUMN *create_column(char* titre);





#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
