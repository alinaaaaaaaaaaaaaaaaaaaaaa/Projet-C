
#ifndef CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
#define CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H

typedef struct {
    char* titre;
    int * donnees;
    int taille_log;
    int taille_ph;
}COLUMN;

COLUMN * create_column(char * titre);











#endif //CDATAFRAME_ABDEL_ALINA_PP_FONCTIONS_H
