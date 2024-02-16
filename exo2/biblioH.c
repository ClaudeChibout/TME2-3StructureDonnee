#include "biblioH.h"
#include <stdio.h>
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
    L->suivant = NULL;

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
    b->m = m; // taille du tableau
    b->T = (LivreH **) malloc(sizeof(LivreH *)*m); // tableau de pointeur
    // initialise les pointeurs a NULL
    for (int i =0; i<m; i++){
        b->T[i] = NULL;
    }
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
    // hash est l'indice dans notre tableau
    int hash = fonctionHachage(fonctionClef(auteur), b->m);

    LivreH * newLivre = creer_livre(num, titre, auteur); // on crée notre nouveau livre

    // on l'ajoute en tete de la liste chainée contenue à l'indice 'hash' du tableau b->T
    newLivre->suivant=b->T[hash];
    b->T[hash] = newLivre;
}

void afficher_LivreH(LivreH * livre){
    if (livre != NULL){
        printf("%d %s %s\n", livre->num, livre->titre, livre->auteur);
    }
}

void afficher_BiblioH(BiblioH * b){
    if (b != NULL){
        for (int i =0; i<b->m; i++){
            LivreH * tmp= b->T[i];
            while (tmp){
                afficher_LivreH(tmp);
                tmp=tmp->suivant;
            }
        }
    }
}