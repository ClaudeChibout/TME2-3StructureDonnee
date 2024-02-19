#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdio.h>



int main(){
    BiblioH * b = creer_biblio(10);
    printf("Voici la bibliotheque:\n");
    inserer(b, 0, "a", "a");
    inserer(b, 1, "a", "a");
    inserer(b, 2, "b", "b");
    inserer(b, 3, "b", "b");
    inserer(b, 4, "a", "a");
    inserer(b, 5, "c", "c");
    afficher_BiblioH(b);
    printf("-------------\n");
    LivreH * doublons = recherche_ouvrage_plusieurs_exemplaires(b);
    printf("-------------\n");
    printf("Liste de doublons :\n");
    LivreH * tmp = doublons;
    while (tmp){
        afficher_LivreH(tmp);
        tmp=tmp->suivant;
    }

    liberer_biblio(b);

    while (doublons){
        tmp = doublons->suivant;
        free(doublons);
        doublons = tmp;
    }

    

    return 0;
}