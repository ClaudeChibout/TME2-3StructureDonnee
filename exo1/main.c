#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"
#include "biblioC.h"

void choix_biblio(int * select_biblio, char *buffer){
    printf("Veuillez écrire le numéro de la bibliotheque a utiliser (1, 2):");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d\n", select_biblio);
}
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
    Biblio * b2=creer_biblio();
    Livre * livre=NULL;
    int num;
    char titre[256];
    char auteur[256];
    int select_biblio=0;
    do {
        menu ();
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%d\n", &rep);
        switch (rep){
        case 1:
            choix_biblio(&select_biblio, buffer);
            printf ( "Affichage : \n");
            affichage_bibliotheque(select_biblio==1?b:b2);
            break ;
        case 2:
            //fflush(stdin);
            choix_biblio(&select_biblio, buffer);
            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage : ");
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3) {

                inserer_en_tete(select_biblio==1?b:b2, num, titre, auteur);
                printf("Ajout fait\n");
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 3:
            choix_biblio(&select_biblio, buffer);
            if(b2!=NULL){
                liberer_biblio(select_biblio==1?b:b2);
            }
            if (select_biblio==1){
                b=creer_biblio();
            }else if(select_biblio==2){
                b2=creer_biblio();
            }
            printf("la bibliothèque est crée\n");
            break ;
        case 4:
            choix_biblio(&select_biblio, buffer);
            printf("Veuillez écrire le numéro : ");
            //fflush(stdin);
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d\n", &num) == 1) {
                
                affichage_livre(recherche_ouvrage_num(select_biblio==1?b:b2,num));
            
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 5:
            choix_biblio(&select_biblio, buffer);
            printf("Veuillez écrire le numéro et le titre de l'ouvrage : ");
            //fflush(stdin);
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%s", titre) == 1) {
                affichage_livre(recherche_ouvrage_titre(select_biblio==1?b:b2, titre));

            } else {
                printf("Erreur de format\n");
            }
            break;
        case 6:
            choix_biblio(&select_biblio, buffer);
            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage : ");
            fgets(buffer, 256, stdin);
            if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3) {
                supprimer_un_ouvrage(select_biblio==1?b:b2,num,auteur, titre);
                printf("l'ouvrage num : %d titre : %s d'auteur : %s a été supprimer\n", num, titre, auteur);
            }
            break;
        case 7:
            fusion_deux_bibliotheque(&b,&b2);
            affichage_bibliotheque(b);
            printf("les bibliothèque ont été fusionner ");
            break;
        case 8:
            choix_biblio(&select_biblio, buffer);
            Livre * livre=rechercher_ouvrage_identique(select_biblio==1?b:b2);
            while (livre){
                affichage_livre(livre);
                livre = livre->suiv;
            }
            break;

        default:
            printf("Option non valide.\n");
            break;
    
        }
} while ( rep !=0) ;
liberer_biblio(b);
printf ( "Merci et au revoir\n" );
return 0;

        
}