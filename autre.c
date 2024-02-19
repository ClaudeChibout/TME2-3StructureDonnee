#include "biblioC.h"
#include "entreeSortieLC.h"
//#include "biblioH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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
/*
LivreH * recherche_par_numero_H(BiblioH * b, int num){
    for (int i =0; i<b->m; i++){
        LivreH * tmp = b->T[i];
        while(tmp){
            if (tmp->num == num){
                return tmp;
            }
            tmp=tmp->suivant;
        }
    }
    return NULL;
}

LivreH * recherche_par_titre_H(BiblioH * b, char * titre){
    for (int i =0; i<b->m; i++){
        LivreH * tmp = b->T[i];
        while(tmp){
            if (strcmp(tmp->titre, titre)){
                return tmp;
            }
            tmp=tmp->suivant;
        }
    }
    return NULL;
}

BiblioH * recherche_livres_auteur_H(BiblioH * b, char * auteur){
    BiblioH * bnew=creer_biblio(b->m);
    for (int i =0; i<b->m; i++){
        LivreH * tmp = b->T[i];
        while(tmp){
            if (strcmp(tmp->auteur, auteur)){
                inserer(bnew, tmp->num, tmp->titre, tmp->auteur);
            }
            tmp=tmp->suivant;
        }
    }
    return bnew;
}
*/
int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Veuillez entrer le nom du fichier et le nombre de ligne a lire\n");
        return 1;
    }

    char * nom_fichier = argv[1];

    int nombre_ligne = atoi(argv[2]);


    Biblio *biblio = charger_n_entrees(nom_fichier,nombre_ligne);
    inserer_en_tete(biblio, 1, "Livre 1", "Auteur 1");

  
    clock_t debut_num = clock();
    recherche_ouvrage_num(biblio, 1);
    clock_t fin_num = clock();

    clock_t debut_titre = clock();
    recherche_ouvrage_titre(biblio, "Livre 1");
    clock_t fin_titre = clock();

    clock_t debut_auteur = clock();
    recherche_livres_auteur(biblio, "Auteur 1");
    clock_t fin_auteur = clock();

    printf("Temps pour recherche par numéro : %ld ticks\n", fin_num - debut_num);
    printf("Temps pour recherche par titre : %ld ticks\n", fin_titre - debut_titre);
    printf("Temps pour recherche par auteur : %ld ticks\n", fin_auteur - debut_auteur);


    liberer_biblio(biblio);

    return 0;

}