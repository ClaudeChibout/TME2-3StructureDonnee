#include "entreeSortieLC.h"
#include "biblioC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Biblio * charger_n_entrees(char * nomfic,int n){
    Biblio *b=(Biblio*)(malloc(sizeof(Biblio)));
    char titre[256];
    char auteur[256];
    FILE * file= fopen(nomfic, "r");
    if(file==NULL){
        printf("erreur d'ouverture de mon_fichier\n");
        return NULL;
    }
    for(int i=0;i<n;){
        fscanf(file,"%d %s %s\n", &i,&titre,&auteur);
        inserer_en_tete(b, i,titre,auteur);

    }
    fclose(file);
    return b;
}


void enregistrer_biblio(Biblio *b, char* nomfic){
    Livre *livre=NULL;
    Livre *tete_de_liste=b->L;
    char titre[256];
    char auteur[256];
    FILE * file= fopen(nomfic, "w");
    if(file==NULL){
        printf("erreur d'ouverture de mon_fichier\n");
        return ;
    }
    while(b->L){
        fprintf(file,"%d %s %s\n", b->L->num,b->L->titre,b->L->auteur);
        b->L=b->L->suiv;
    }
    b->L=tete_de_liste;
    fclose(file);
}


