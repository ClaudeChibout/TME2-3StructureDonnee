#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"
#include "biblioC.h"

int main(int argc, char** argv){
    if (argc != 3) {
        printf("");
        return 1;
    }

    char * nom_fichier = argv[1];
    int nombre_ligne = atoi(argv[2]);

    Biblio *b = charger_n_entrees(nom_fichier,nombre_ligne);
    affichage_bibliotheque(b);
    enregistrer_biblio(b,"derya.txt");

    return 0;
}



