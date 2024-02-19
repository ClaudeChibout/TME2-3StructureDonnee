#include <stdlib.h>
#include <stdio.h>
#include "biblioH.h"

BiblioH* charger_n_entrees_BiblioH(char* nomfic, int n){
    //permettant de lire n lignes du fichier
    //et de les stocker dans une bibliothèque.

    // ouvre le fichier en lecture et vérifie qu'il soit bien ouvert
    FILE *f = fopen(nomfic, "r");
    if (f==NULL){
        printf("Impossible d'ouvrir le fichier %s", nomfic);
        return NULL;
    }


    BiblioH * b = creer_biblio(n); // crée la bibliothèque
    char buffer[256];

    // pour le nombre de ligne demandé
    for (int i = 0; i<n; i++){

        if (fgets(buffer, 256, f)){ // récupère la i+1(car i commence a 0) eme ligne du fichier
            int num;
            char titre[256];
            char auteur[256];
            sscanf(buffer, "%d %s %s", &num, titre, auteur); // traite la chaine de carractère 
            inserer(b, num, titre, auteur); // insère dans notre Bibliothèque le livre 
        }else{
            // S'il n'y a pas assez de ligne dans le fichier on s'arrete de lire dedans
            printf("Le fichier contenait seulement %d lignes qui ont été ajouté à la bibliothèque", i);
            break;
        }
    }
    fclose(f);
    return b;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    //qui permet de stocker une bibliothèque
    //dans un fichier au bon format : numéro titre auteur.

    // vérifie que la bibliothèque soit bien initialisé
    if (b==NULL){
        printf("La bibliothèque n'est pas initialisé, impossible de l'enregistrer dans %s", nomfic);
        return;
    }
    
    // ouvre le fichier en écriture et vérifie qu'il soit bien ouvert
    FILE *f = fopen(nomfic, "w");
    if (f==NULL){
        printf("Erreur lors de l'initialisation du fichier");
        return;
    }

    // parcours toutes les cases du tableau
    for (int i =0; i<b->m; i++){
        
        // parcours la liste chainé contenu dans la case d'indice 'i' 
        LivreH * tmp = b->T[i];
        while (tmp){
            fprintf(f, "%d %s %s\n", tmp->num, tmp->titre, tmp->auteur); // ecrit le livre dans le fichier
            tmp = tmp->suivant;
        }

    }

    fclose(f);
}