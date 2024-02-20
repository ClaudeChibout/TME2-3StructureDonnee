#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
    BiblioH * b = creer_biblioH(10);
    
    printf("Voici la bibliotheque:\n");
    inserer(b, 0, "livre1", "auteur1");
    inserer(b, 1, "livre2", "auteur2");
    inserer(b, 2, "livre3", "auteur3");
    inserer(b, 3, "livre1", "auteur1");
    inserer(b, 4, "livre2", "auteur2");
    inserer(b, 5, "livre10", "auteur10");
    afficher_BiblioH(b);

    BiblioH * b2 = creer_biblioH(10);
    
    printf("Voici la bibliotheque:\n");
    inserer(b2, 01, "livre11", "auteur11");
    inserer(b2, 11, "livre22", "auteur22");
    afficher_BiblioH(b2);

    printf("affiche le livre ayant le numero2\n");
    afficher_LivreH(recherche_par_numero_H(b, 2));
    printf("\n");
    printf("affiche le livre ayant le titre : livre3\n");
    afficher_LivreH(recherche_par_titre_H(b, "livre3"));
    printf("\n");
    printf("affiche le livre ayant l'auteur: auteur3\n");
    afficher_BiblioH(recherche_livres_auteur_H(b,"auteur3" ));
    printf("\n");
    printf("nous allons supprimer l'ouvrage n5 \n");
    supprimer_ouvrage_H(b, 5, "livre10", "auteur10");
    afficher_BiblioH(b);
    printf("l'ouvrage a été supprimer\n");
    printf("\n");
    printf("l'affichage des ouvrage en plusieurs exemplaire:\n");
    LivreH * doublons = recherche_ouvrage_plusieurs_exemplaires(b);
    printf("-------------\n");
    printf("Liste de doublons :\n");
    LivreH * tmp = doublons;
    while (tmp){
        afficher_LivreH(tmp);
        tmp=tmp->suivant;
    }
    
    printf("\n");
    printf("nous allons fusionner b et b2");
    fusion_BiblioH(&b,&b2);
    afficher_BiblioH(b);
    printf("la fusion a bien étais faite");


    liberer_biblioH(b);
    liberer_biblioH(b2);

    while (doublons){
        tmp = doublons->suivant;
        liberer_livreH(doublons);
        doublons = tmp;
    }
  
    return 0;
}