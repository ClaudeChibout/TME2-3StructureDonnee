#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"
#include "biblioC.h"


void menu() {
    printf("Actions possibles sur la bibliothèque :\n");
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage d'un livre\n");
    printf("2 - Insérer ouvrage\n");
    printf("3- Créer un livre\n");
    printf("4- Liberer un livre\n");
    printf("5- Creer une bibliothèque\n");
    printf("6- Inserer en tete d'une Bibliothèque\n");
    printf("7- Affichage d'un Bibliothèque\n");
    printf("8- Recherche d'un ouvrage avec le numero\n");
    printf("9- Recherche d'un ouvrage avec le nom du titre\n");
    printf("10- Supprimer un ouvrage\n");
    printf("11- Fusion de deux bibliothèque\n");
    printf("12- Recherche d'un ouvrage identique\n");

}

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

    menu();

    return 0;
}
