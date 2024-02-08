#include "biblioC.h"
#include <stdio.h>
#include <stdlib.h>

Livre * creer_livre(int num, char * titre, char auteur){
    Livre * livre= (Livre*) malloc(sizeof(Livre));
    livre->num=num;
    livre->titre=titre;
    livre->auteur=auteur;
    livre->suiv=NULL;

}



void liberer_livre(Livre * l){
    free(l);
}

Biblio * creer_biblio(){
    
}
