#include <stdlib.h>
#include <stdio.h>
#include "biblioH.h"

BiblioH* charger_n_entrees(char* nomfic, int n){
    //permettant de lire n lignes du fichier
    //et de les stocker dans une bibliothèque.
    FILE *f = fopen(nomfic, "r");
    if (f==NULL){
        printf("Impossible d'ouvrir le fichier %s", nomfic);
        return NULL;
    }

    BiblioH * b = creer_biblio(n);
    char * buffer[256];
    for (int i = 0; i<n; i++){
        
    }
}