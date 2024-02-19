#include "biblioC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre * creer_livre(int num, char * titre, char *auteur){
    //creer un livre et l'initialise
    Livre * livre= (Livre*) malloc(sizeof(Livre));
    livre->num=num;
    livre->titre=strdup(titre);
    livre->auteur=strdup(auteur);
    livre->suiv=NULL;
    return livre;

}

void liberer_livre(Livre *l) {
    // Libère un livre
    if (l != NULL) {
        free(l->titre);
        free(l->auteur);
        free(l); // Libère la mémoire de la structure du livre
    }
}

Biblio * creer_biblio(){
    //creer une bibliothèque
    Biblio * b= (Biblio*) malloc(sizeof(Biblio));
    b->L=NULL;
    return b;
}

void liberer_biblio(Biblio *b) {
    // Libère une bibliothèque
    if (b != NULL) {
        Livre *livre = b->L;
        Livre *tmp = NULL;
        while (livre) {
            tmp = livre;
            livre = livre->suiv;
            liberer_livre(tmp);
        }
        free(b); // Libère la mémoire de la structure de la bibliothèque
    }
}


void inserer_en_tete(Biblio* b, int num, char * titre, char * auteur){
    //insère en tete un livre
    if(b!=NULL){
        Livre * livre= creer_livre(num,titre,auteur);
        livre->suiv=b->L;
        b->L=livre;
    }
}

void affichage_livre(Livre * l){
    //affiche un livre
    if (l!=NULL){
        printf("num : %d, titre: %s, auteur: %s \n",l->num,l->titre,l->auteur);
           
    }else{
        printf("Livre non initialisé\n");
    }
    
}

void affichage_bibliotheque(Biblio * b){
    //affichage d'une bibliothèque
    if(b!=NULL){
        Livre * livre = b->L;
        if(livre==NULL){
            printf("La Bibliothèque est vide.\n");
            return;
        }
        while(livre){
            affichage_livre(livre);
            livre=livre->suiv;
        }
    }else{
        printf("La Bibliothèque n'existe pas.\n");
        return;
    }
    
}

Livre* recherche_ouvrage_num(Biblio * b, int num){
    //recherche un ouvrage avec un numéro
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
    //recherche un ouvrage avec le titre
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
    //recherche un livre avec le nom de l'auteur
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
        if(l->num==num && strcmp(l->auteur,auteur)==0 && strcmp(l->auteur,auteur)==0){ //le cas ou l'ouvrage a supprimer est en tete de liste
            tmp=l;
            l=l->suiv;
            free(tmp);
            b->L=l;
            return;
        }
        Livre * precedent=NULL;
        while(l!=NULL && l->num!=num && strcmp(l->auteur,auteur)!=0 && strcmp(l->auteur,auteur)!=0){ //on parcours la liste ne gardant le précédents
            precedent=l;
            l=l->suiv;

        }
        if(l!=NULL){ //on supprime l'élements si il n'est pas vide
            precedent->suiv=l->suiv;
            free(l);
        }

    }       
}


void fusion_deux_bibliotheque(Biblio ** b1, Biblio ** b2){
    if(*b2==NULL){ //le cas où b2 est null
        return;
    }
    Livre * l2=(*b2)->L;
    if (*b1==NULL){ //le cas où b1 est null
        *b1=creer_biblio();

    }

    while(l2){ //on ajoute b2 a b1
        inserer_en_tete(*b1, l2->num, l2->titre, l2->auteur);
        l2=l2->suiv;
    }

    
    liberer_biblio(*b2); //on libère b2
    *b2 = NULL;
    
}

 Livre * rechercher_ouvrage_identique(Biblio * b){

    Livre * livre_double=NULL;
    Livre * livre_temp=NULL;
    Livre * livre_tete1=b->L;
    Livre * livre_tete=b->L;

    while(livre_tete1){
        // parcours livre double pour vérifier que le livre courant ne soit pas dedans 
        Livre * prc_double=livre_double;
        livre_temp=b->L;
        int cmp=0;
        while(livre_temp){
            if(strcmp(livre_tete1->auteur,livre_temp->auteur)==0 && strcmp(livre_tete1->titre,livre_temp->titre)==0 && livre_temp->num != livre_tete1->num){
                Livre * tmp=creer_livre(livre_temp->num, livre_temp->titre, livre_temp->auteur);
                tmp->suiv=livre_double;
                livre_double=tmp;
                cmp++;
            }
            livre_temp=livre_temp->suiv;
        }
        
        if(cmp>0){
            Livre * tmp=creer_livre(livre_tete1->num, livre_tete1->titre, livre_tete1->auteur);
            tmp->suiv=livre_double;
            livre_double=tmp;
        }
        livre_tete1=livre_tete1->suiv;
        
    }
    if(livre_double==NULL){
        printf("Il n'y a pas de doublons dans la bibliothèque.\n");
    }else{
        Livre * ld= livre_double;
        while(ld){
            Livre * ld2= ld->suiv;
            Livre * prec = ld;
            while(ld2){
                if(strcmp(ld->auteur,ld2->auteur)==0 && strcmp(ld->titre,ld2->titre)==0 &&ld->num==ld2->num){
                    prec->suiv = ld2->suiv;
                    liberer_livre(ld2);
                    ld2 = prec->suiv;
                }else{
                    prec = ld2;
                    ld2 = ld2->suiv;
                }
            }
            ld = ld->suiv;
        }
    }
    return livre_double;

}   

