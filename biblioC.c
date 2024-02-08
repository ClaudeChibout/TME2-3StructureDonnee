#include "biblioC.h"
#include <stdio.h>
#include <stdlib>

Livre * creer_livre(int num, char * titre, char auter){
    Livre * livre= (Livre*) malloc(sizeof(Livre));
    livre->num=num;
    livre->titre=titre;
    livre->auter;
    livre->suivant=NULL;

}



void liberer_livre(Livre *1){
    free(l);
}

Biblio * creer_biblio(){
    
}
