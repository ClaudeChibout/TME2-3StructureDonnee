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
        b->L=livre;
    }
}

void affichage_livre(Livre * l){
    if (l!=NULL){
        printf("num : %d, titre: %s, auteur: %s \n",l->num,l->titre,l->auteur);
           
    }else{
        printf("Livre non initialisé\n");
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
            if(l->num==num){
                return l;
            }
            l=l->suiv;
        }
    }
    return NULL;
}


Livre* recherche_ouvrage_titre(Biblio * b, char * titre){
    Livre * l=b->L;
    if(b!=NULL){
        while(l){
            if(strcmp(l->titre,titre)==0){
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
            if (strcmp(l->auteur,auteur)==0){
                inserer_en_tete(bnew, l->num, l->titre, l->auteur);
            }
            l=l->suiv;
        }
    }
    return bnew;
}

void supprimer_un_ouvrage(Biblio * b, int num, char * auteur, char * titre){
    if(b!=NULL){
        Livre * l=b->L;
        Livre * tmp=NULL;
        if(l->num==num && strcmp(l->auteur,auteur)==0 && strcmp(l->auteur,auteur)==0){
            tmp=l;
            l=l->suiv;
            free(tmp);
            b->L=l;
            return;
        }
        Livre * precedent=NULL;
        while(l!=NULL && l->num!=num && strcmp(l->auteur,auteur)!=0 && strcmp(l->auteur,auteur)!=0){
            precedent=l;
            l=l->suiv;

        }
        if(l!=NULL){
            precedent->suiv=l->suiv;
            free(l);
        }

    }       
}


void fusion_deux_bibliotheque(Biblio ** b1, Biblio ** b2){
    if(*b2==NULL){
        return;
    }

    Biblio ** bnew=(Biblio**)malloc(sizeof(Biblio*));
    Livre * l2=(*b2)->L;
    if (*b1==NULL){
        *bnew=creer_biblio();
        *b1=*bnew;
    }else{
        *bnew=*b1;
    }

    while(l2){
        inserer_en_tete(*bnew, l2->num, l2->titre, l2->auteur);
        l2=l2->suiv;
    }

    
    liberer_biblio(*b2);
    free(bnew);
}

 Livre * rechercher_ouvrage_identique(Biblio * b){

    Livre * livre_double=NULL;
    Livre * livre_temp=NULL;
    Livre * livre_tete=b->L;
    while(livre_tete){
        livre_temp=livre_tete;
        int cmp=0;
        while(livre_tete){
            if(strcmp(livre_tete->auteur,livre_temp->auteur) && strcmp(livre_tete->titre,livre_temp->titre) && livre_tete->num!=livre_temp->num){
                Livre * tmp=creer_livre(livre_temp->num, livre_temp->titre, livre_temp->auteur);
                tmp->suiv=livre_double;
                livre_double=tmp;
                cmp++;
            }
            livre_tete=livre_tete->suiv;
        }
        if(cmp>0){
            Livre * tmp=creer_livre(livre_tete->num, livre_tete->titre, livre_tete->auteur);
            tmp->suiv=livre_double;
            livre_double=tmp;
        }
        livre_tete=livre_tete->suiv;
    }
    return livre_double;

}   

