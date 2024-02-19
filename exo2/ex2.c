#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdio.h>



int main(){
    BiblioH * b = creer_biblio(10);
    inserer(b, 0, "a", "a");
    inserer(b, 1, "a", "a");
    inserer(b, 2, "b", "b");
    inserer(b, 3, "b", "b");
    inserer(b, 4, "a", "a");
    inserer(b, 5, "c", "c");
    afficher_BiblioH(b);
    LivreH * doublons = recherche_ouvrage_plusieurs_exemplaires(b);
    LivreH * tmp = doublons; 

    liberer_biblio(b);

    

    return 0;
}