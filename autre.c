#include "biblioC.h"
#include "entreeSortieLC.h"
//#include "biblioH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Veuillez entrer le nom du fichier et le nombre de ligne a lire\n");
        return 1;
    }

    char * nom_fichier = argv[1];

    int nombre_ligne = atoi(argv[2]);


    Biblio *biblio = charger_n_entrees(nom_fichier,nombre_ligne);
    inserer_en_tete(biblio, 1, "Livre 1", "Auteur 1");

  
    clock_t debut_num = clock();
    recherche_ouvrage_num(biblio, 1);
    clock_t fin_num = clock();

    clock_t debut_titre = clock();
    recherche_ouvrage_titre(biblio, "Livre 1");
    clock_t fin_titre = clock();

    clock_t debut_auteur = clock();
    recherche_livres_auteur(biblio, "Auteur 1");
    clock_t fin_auteur = clock();

    printf("Temps pour recherche par numéro : %f s\n", ((double)fin_num - debut_num)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par titre : %f s\n", ((double)fin_titre - debut_titre)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par auteur : %f s\n", ((double)fin_auteur - debut_auteur)/ CLOCKS_PER_SEC);


    liberer_biblio(biblio);

    return 0;

}