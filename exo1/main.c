#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"
#include "biblioC.h"


void menu() {
    printf("Actions possibles sur la bibliothèque :\n");
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage d'une Bibliothèque\n");
    printf("2 - Insérer ouvrage\n");
    printf("3- Creer une bibliothèque\n");
    printf("4- Recherche d'un ouvrage avec le numero\n");
    printf("5- Recherche d'un ouvrage avec le nom du titre\n");
    printf("6- Supprimer un ouvrage\n");
    printf("7- Fusion de deux bibliothèque\n");
    printf("8- Recherche d'un ouvrage identique\n");

}

int main(int argc, char** argv){
    if (argc != 3) {
        printf("");
        return 1;
    }

    char * nom_fichier = argv[1];
    int nombre_ligne = atoi(argv[2]);

    Biblio *b = charger_n_entrees(nom_fichier,nombre_ligne);
    //affichage_bibliotheque(b);
    enregistrer_biblio(b,"derya.txt");
    char buffer[256];
    int rep ;
    Biblio * b2=NULL;
    Livre * livre=NULL;
    int num;
    char titre[256];
    char auteur[256];
    do {
        menu ();
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d\n", &rep);
        switch (rep){
        case 1:
            printf ( "Affichage : \n");
            affichage_bibliotheque(b);
            break ;
        case 2:
            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage : ");
            //fflush(stdin);
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3) {

                inserer_en_tete(b, num, titre, auteur);
                printf("Ajout fait\n");
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 3:
            if(b2!=NULL){
                liberer_biblio(b2);
            }
            b2=creer_biblio();
            printf("la bibliothèque est crée\n");
            break ;
        case 4:

            printf("Veuillez écrire le numéro : ");
            //fflush(stdin);
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d\n", &num) == 1) {
                
                affichage_livre(recherche_ouvrage_num(b,num));
            
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 5:

            printf("Veuillez écrire le numéro et le titre de l'ouvrage : ");
            //fflush(stdin);
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%s", titre) == 1) {
                affichage_livre(recherche_ouvrage_titre(b, titre));

            } else {
                printf("Erreur de format\n");
            }
            break;
        case 6:
            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage : ");
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3) {
                supprimer_un_ouvrage(b,num,auteur, titre);
            }
            break;
        default:
            printf("Option non valide.\n");
            break;
    
        }
        }
} while ( rep !=0) ;
liberer_biblio(b);
printf ( "Merci et au revoir\n" );
return 0;

        
}