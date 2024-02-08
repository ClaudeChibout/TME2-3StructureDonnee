#include "enrteeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Biblio * charger_n_entrees(char * nomfic,int n){
    Biblio *b=(Biblio*)(malloc(sizeof(Biblio)));
    char titre[256];
    char auteur[256];
    for(int i=0,i<n;i++){
        fscanf(file,"%d %s %s\n", &i,&titre,&auteur);
        b=

    }

    



}
void enregistrer biblio(Biblio *b, char* nomfic);