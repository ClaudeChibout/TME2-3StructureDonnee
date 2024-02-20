#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioC.h"
#include "entreeSortieLC.h"


int main(){

    Biblio * ma_biblio=creer_biblio();
    Biblio * ma_biblio2=creer_biblio();

    // Ajout de 4 livres a ma_biblio
    inserer_en_tete(ma_biblio, 1, "Harry Potter", "J.K. Rowling");
    inserer_en_tete(ma_biblio, 2, "Le Seigneur des Anneaux", "J.R.R. Tolkien");
    inserer_en_tete(ma_biblio, 3, "livre", "auteur");
    inserer_en_tete(ma_biblio, 4, "Le Seigneur des Anneaux", "J.R.R. Tolkien");

    // Ajout de 2 livre a ma_biblio2
    inserer_en_tete(ma_biblio2, 11, "Harry Potter", "J.K. Rowling");
    inserer_en_tete(ma_biblio2, 22, "Le Seigneur des Anneaux", "J.R.R. Tolkien");

    printf("j'affiche ma_biblio\n");
    affichage_bibliotheque(ma_biblio);

    printf("recherche dans ma biblio d'un ouvrage au numero 1\n");
    affichage_livre(recherche_ouvrage_num(ma_biblio,1));
    printf("\n");
    printf("recherche dans ma biblio d'un ouvrage au titre livre\n");
    affichage_livre(recherche_ouvrage_titre(ma_biblio, "livre"));
    printf("\n");
    printf("recherche dans ma biblio d'un ouvrage a l'auteur J.R.R. Tolkien\n");
    affichage_bibliotheque(recherche_livres_auteur(ma_biblio, "J.R.R. Tolkien"));
    printf("\n");
    printf("on supprime dans ma bilbio l'ouvrage 3\n");
    supprimer_un_ouvrage(ma_biblio, 3, "livre", "auteur");
    printf("\n");
    printf("l'ouvrage livre n3 a étais supprimer\n");
    printf("\n");
    affichage_bibliotheque(ma_biblio);
    printf("\n");

    printf("la liste des ouvrages identique dans ma_biblio\n");
    Livre * livre=rechercher_ouvrage_identique(ma_biblio);
    Livre * livretmp=livre;
    while(livretmp){
        affichage_livre(livretmp);
        livretmp=livretmp->suiv;
    }
    printf("\n");

    fusion_deux_bibliotheque(&ma_biblio,&ma_biblio2);
    printf("affichage des bibliothèque fusionner\n");
    affichage_bibliotheque(ma_biblio);

    liberer_biblio(ma_biblio);
    liberer_biblio(ma_biblio2);
    livretmp=livre;
    while(livretmp){
        livre=livretmp->suiv;
        liberer_livre(livretmp);
        livretmp=livre;
    }

}