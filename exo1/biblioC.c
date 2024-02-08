#include "biblioC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre * creer_livre(int num, char * titre, char *auteur){
    Livre * livre= (Livre*) malloc(sizeof(Livre));
    livre->num=num;
    livre->titre=strdup(titre);
    livre->auteur=strdup(auteur);
    livre->suiv=NULL;
    return livre;

}

void liberer_livre(Livre * l){
    if (l!=NULL){
        free(l->titre);
        free(l->auteur);
        free(l);
        l=NULL;
    }
}

Biblio * creer_biblio(){
  
    Biblio * b= (Biblio*) malloc(sizeof(Biblio));
    b->L=NULL;
    return b;
}

void liberer_biblio(Biblio * b){
    if (b!=NULL){
        Livre * livre= b->L;
        Livre * tmp=NULL;
        while(livre){
            tmp=livre;
            liberer_livre(tmp);
            livre=livre->suiv;
            }
        free(b);
        b=NULL;
    }
}

void inserer_en_tete(Biblio* b, int num, char * titre, char * auteur){
    if(b!=NULL){
        Livre * livre= creer_livre(num,titre,auteur);
        livre->suiv=b->L;
        b->L->suiv=livre;
    }
}

int main(){
    return 0;
}