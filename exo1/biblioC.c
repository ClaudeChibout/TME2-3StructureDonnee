#include "biblioC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre * creer_livre(int num, char * titre, char auteur){
    Livre * livre= (Livre*) malloc(sizeof(Livre));
    livre->num=num;
    livre->titre=strdup(titre);
    livre->auteur=strdup(auter);
    livre->suiv=NULL;

}

void liberer_livre(Livre * l){
    if (l!=NULL){
        free(l->titre);
        free(l->auter);
        free(l);
        l=NULL;
    }
}

Biblio * creer_biblio(){
  
    Biblio * b= (Biblio*) malloc(sizeof(Biblio));
    b->L=NULL;
}

void liberer_biblio(Biblio * b){
    if (b!=NULL){
        Livre * livre= b->L;
        Livre * tmp=NULL;
        while(livre){
            tmp=livre;
            liberer_livre(tmp);
            livre=livre->suivant;
            }
    free(b);
    b->L=NULL;
    }
}

void inserer_en_tete(Biblio* b, int num, char * titre, char * auter){
    if(b!=NULL){
        Livre * livre= creer_livre(num,titre,auteur);
        livre->suivant=b->L;
        b->L->suivant=livre;
    }
}

