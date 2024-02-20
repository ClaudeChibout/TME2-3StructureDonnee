#include "biblioC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"
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
  
    clock_t debut_num = clock();
    recherche_ouvrage_num(biblio,5844);
    clock_t fin_num = clock();

    clock_t debut_titre = clock();
    recherche_ouvrage_titre(biblio,"HOTSRCDIFDZWFU");
    clock_t fin_titre = clock();

    clock_t debut_auteur = clock();
    recherche_livres_auteur(biblio, "sidvuoays");
    clock_t fin_auteur = clock();

    printf("le cas ou l'element existe dans la bibliothèque\n");
    printf("Temps pour recherche par numéro : %f s\n", ((double)fin_num - debut_num)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par titre : %f s\n", ((double)fin_titre - debut_titre)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par auteur : %f s\n", ((double)fin_auteur - debut_auteur)/ CLOCKS_PER_SEC);

    printf("le cas ou l'element n'existe pas dans la bibliothèque\n");

    debut_num = clock();
    recherche_ouvrage_num(biblio, 121442);
    fin_num = clock();

    debut_titre = clock();
    recherche_ouvrage_titre(biblio,"Deryaa");
    fin_titre = clock(); 


    debut_auteur = clock();
    recherche_livres_auteur(biblio, "Clau(gtgb(h(de");
    fin_auteur = clock();

    printf("Temps pour recherche par numéro : %f s\n", ((double)fin_num - debut_num)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par titre : %f s\n", ((double)fin_titre - debut_titre)/ CLOCKS_PER_SEC);
    printf("Temps pour recherche par auteur : %f s\n", ((double)fin_auteur - debut_auteur)/ CLOCKS_PER_SEC);

    

    //---------------------------------------------------------------------------------------
    BiblioH* ma_biblio =  charger_n_entrees_BiblioH(nom_fichier,nombre_ligne, 500);
    printf("Avec la table de hachage dont le tableau a %d cases\n",ma_biblio->m);
    clock_t debut = clock();
    recherche_par_numero_H(ma_biblio, 5844); // Remplacez par le numéro de livre réel
    clock_t fin = clock();
    double temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps d'exécution de recherche_par_numero_H : %f secondes\n", temps_ecoule);

    // Mesure du temps d'exécution de recherche_par_titre_H
    debut = clock();
    recherche_par_titre_H(ma_biblio, "HOTSRCDIFDZWFU"); // Remplacez par le titre réel
    fin = clock();
    temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps d'exécution de recherche_par_titre_H : %f secondes\n", temps_ecoule);

    // Mesure du temps d'exécution de recherche_livres_auteur_H
    debut = clock();
    recherche_livres_auteur_H(ma_biblio, "sidvuoays"); // Remplacez par l'auteur réel
    fin = clock();
    temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps d'exécution de recherche_livres_auteur_H : %f secondes\n", temps_ecoule);

    liberer_biblio(biblio);

    return 0;

}