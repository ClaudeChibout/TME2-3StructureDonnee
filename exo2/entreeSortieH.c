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
        if (fgets(buffer, 256, f)){
            int num;
            char titre[256];
            char auteur[256];
            sscanf(buffer, "%d %s %s", &num, titre, auteur);
            inserer(b, num, titre, auteur);
        }else{
            printf("Le fichier contenait seulement %d lignes qui ont été ajouté à la bibliothèque", i);
        }
    }
    return b;
}