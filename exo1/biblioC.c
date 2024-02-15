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

void affichage_livre(Livre * l){
    if (l!=NULL){
        printf("num : %d, titre: %s, auteur: %s \n",l->num,l->titre,l->auteur);
           
        }
    }
}

void affichage_bibliotheque(Biblio * b){
    Livre * livre = b->L;
    if(b!=NULL){
        while(b->L){
            affichage_livre(b->L);
            b->L=b->L->suiv;
        }
        b->L=livre;
    }
}

Livre* recherche_ouvrage_num(Biblio * b, int num){
    Livre * l=b->L;
    if(b!=NULL){
        while(l){
            if(l->num=num){
                return l;
            }
            l=l->suiv;
        }
    }
}


Livre* recherche_ouvrage_titre(Biblio * b, char * titre){
    Livre * l=b->L;
    if(b!=NULL){
        while(l){
            if(strcmp(l->titre,titre)){
                return l;
            }
            l=l->suiv;
        }
    }
}

Biblio* recherche_livres_auteur(Biblio * b, char * auteur){
    Livre * l=b->L;
    Biblio * bnew=creer_biblio();
    if(b!=NULL){
        while(l){
            if (strcmp(l->auteur,auteur)){
                inserer_en_tete(bnew, l->num, l->titre, l->auteur);
            }
            l=l->suiv;
        }
    }
    return bnew;
}


