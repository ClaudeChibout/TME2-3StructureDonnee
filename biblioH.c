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

LivreH * creer_livreH(int num, char* titre, char* auteur){
    LivreH * L = (LivreH *)malloc(sizeof(LivreH));
    L->auteur = strdup(auteur);
    L->titre = strdup(titre);
    L->num = num;
    L->suivant = NULL;

    return L;
}

void liberer_livreH(LivreH * l){
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

BiblioH * creer_biblioH(int m){
    BiblioH * b = (BiblioH *)malloc(sizeof(BiblioH));
    b->m = m; // taille du tableau
    b->T = (LivreH **) malloc(sizeof(LivreH *)*m); // tableau de pointeur
    // initialise les pointeurs a NULL
    for (int i =0; i<m; i++){
        b->T[i] = NULL;
    }
    return b;
}

void liberer_biblioH(BiblioH * b){
    if (b!=NULL){
        for(int i=0; i<b->m; i++){
            LivreH* tmp = NULL;
            while (b->T[i]){

                tmp=b->T[i]->suivant;
                liberer_livreH(b->T[i]);
                b->T[i] = tmp;
            }
        }
        free(b->T);
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

    LivreH * newLivre = creer_livreH(num, titre, auteur); // on crée notre nouveau livre

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

LivreH * recherche_par_numero_H(BiblioH * b, int num){
    for (int i =0; i<(b->m); i++){
        LivreH * tmp = b->T[i];
        while(tmp){
            if ((tmp->num) == num){
                return tmp;
            }
            tmp=tmp->suivant;
        }
    }
    return NULL;
}

LivreH * recherche_par_titre_H(BiblioH * b, char * titre){
    for (int i =0; i<(b->m); i++){
        LivreH * tmp = b->T[i];
        while(tmp){
            if (strcmp(tmp->titre, titre) == 0){
                return tmp;
            }
            tmp=tmp->suivant;
        }
    }
    return NULL;
}

BiblioH * recherche_livres_auteur_H(BiblioH * b, char * auteur){
    BiblioH * bnew=creer_biblioH(b->m);
    LivreH * tmp = b->T[fonctionHachage(fonctionClef(auteur), b->m)];
    while(tmp){
        if (strcmp(tmp->auteur, auteur)==0){
            inserer(bnew, tmp->num, tmp->titre, tmp->auteur);
        }
        tmp=tmp->suivant;
    }
    return bnew;
}

void supprimer_ouvrage_H(BiblioH * b, int num, char * titre, char * auteur){
    if (b == NULL) return; // vérifie que la bibliotheque soit initialisée

    // permet de trouver dans quelle case du tableau se trouve l'ouvrage 
    int hash = fonctionHachage(fonctionClef(auteur), b->m);
    LivreH * tmp = b->T[hash];
    if (tmp == NULL) return;

    // cas ou le livre est en debut de chaine
    if (tmp->num == num && strcmp(tmp->auteur, auteur)==0 && strcmp(tmp->titre, titre)==0){
            b->T[hash] = b->T[hash]->suivant;
            liberer_livreH(tmp);
            return;
    }

    // cas ou le livre n'est pas en premier dans la liste
    LivreH * prec = tmp;
    tmp=tmp->suivant;
    while(tmp){
        if (tmp->num == num && strcmp(tmp->auteur, auteur)==0 && strcmp(tmp->titre, titre)==0){
            prec->suivant = tmp->suivant;
            liberer_livreH(tmp);
            return;
        }
        prec = tmp;
        tmp=tmp->suivant;
    }
}

void fusion_BiblioH(BiblioH **b1, BiblioH **b2){
    if (b1 == NULL || b2 == NULL){
        printf("Erreur fusion_BiblioH: Il faut donner en argument deux adresses de (BiblioH *)\n");
    }
    if (*b2 == NULL){
        return;
    }

    if (*b1 == NULL ){
        *b1 = creer_biblioH((*b2)->m);
    }

    for( int i = 0; i < (*b2)->m; i++){
        LivreH * tmp = (*b2)->T[i];
        while (tmp)
        {
            inserer(*b1, tmp->num, tmp->titre, tmp->auteur);
        }
    }
    liberer_biblioH(*b2);
    *b2 = NULL;
}

LivreH * recherche_ouvrage_plusieurs_exemplaires(BiblioH * b){
    if (b == NULL) return NULL;
    LivreH * res = NULL; // notre liste chainé contenant les doublons
    // parcours le tableau b->T pour acceder aux listes chainées
    for (int i =0; i<b->m; i++){
        LivreH * tmp = b->T[i]; // liste chainé contenue dans la case d'indice i du tableau b->T
        // on parcourt la liste chainée 
        while (tmp){
            // idem pour un deuxieme parcourt
            LivreH * tmp2 = b->T[i];
            int cond = 0;// booleen pour ajouter le premier livre si plusieurs exemplaire ont été trouvé
            while (tmp2){
                if (strcmp(tmp->auteur,tmp2->auteur)==0 && strcmp(tmp->titre,tmp2->titre)==0 && tmp->num != tmp2->num){
                    LivreH* new = creer_livreH(tmp2->num, tmp2->titre,tmp2->auteur);
                    new->suivant = res;
                    res = new;
                    cond+=1;
                }
                tmp2 = tmp2->suivant;
            }

            if (cond > 0){
                LivreH* new = creer_livreH(tmp->num, tmp->titre,tmp->auteur);
                new->suivant = res;
                res = new;
            }



            tmp = tmp->suivant;
        }
    }
    if(res==NULL){
        printf("Il n'y a pas de doublons dans la bibliothèque.\n");
    }else{
        LivreH * ld= res;
        while(ld){
            LivreH * ld2= ld->suivant;
            LivreH * prec = ld;
            while(ld2){
                if(strcmp(ld->auteur,ld2->auteur)==0 && strcmp(ld->titre,ld2->titre)==0 &&ld->num==ld2->num){
                    prec->suivant = ld2->suivant;
                    liberer_livreH(ld2);
                    ld2 = prec->suivant;
                }else{
                    prec = ld2;
                    ld2 = ld2->suivant;
                }
            }
            ld = ld->suivant;
        }
    }
    return res;
}


