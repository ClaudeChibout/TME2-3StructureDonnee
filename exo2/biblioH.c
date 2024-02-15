#include "biblioH.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fonctionClef(char * auteur){
    if (auteur == NULL){
        return 0;
    }
    int hash = 0;
    int i = 0;
    for ( char c = auteur[i]; c != '\0'; c = auteur[i]){
        hash += (int)c;
        i++;
    }
    return hash;
}

LivreH * creer_livre(int num, char* titre, char* auteur){
    LivreH * L = (LivreH *)malloc(sizeof(LivreH));
    L->auteur = strdup(auteur);
    L->titre = strdup(titre);
    L->num = num;

    return L;
}

void liberer_livre(LivreH * l){
    if (l != NULL){
        if (l->titre != NULL){
            free(l->titre);
        }
        if (l->auteur != NULL){
            free(l->auteur);
        }
        free(l);
    }
    
}

BiblioH * creer_biblio(int m){
    BiblioH * b = (BiblioH *)malloc(sizeof(BiblioH));
    b->m = m;
    b->T = (LivreH **) malloc(sizeof(LivreH *)*m);
    return b;
}

void liberer_biblio(BiblioH * b){
    if (b!=NULL){
        for(int i=0; i<b->m; i++){
            liberer_livre(b->T[i]);
        }
        free(b);
    }
}

int fonctionHachage(int cle, int m){
    float A = (sqrt(5)-1)/2;
    return (int)(m*( cle*A - ((int)cle*A) ));
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    
}