#ifndef BIBLIO
#define BIBLIO

typedef struct livre {
    int num ;
    char * titre ;
    char * auteur ;
    struct livre * suiv ;
} Livre ;

typedef struct { /* Tete fictive */
    Livre * L ; /* Premier element */
} Biblio ;

Livre * creer_livre(int num, char * titre, char *auteur);
void liberer_livre(Livre * l);
Biblio * creer_biblio();
Biblio * creer_biblio();
void liberer_biblio(Biblio * b);
void inserer_en_tete(Biblio* b, int num, char * titre, char * auteur);
void affichage_bibliotheque(Biblio * b);
Livre* recherche_ouvrage_num(Biblio * b, int num);
Livre* recherche_ouvrage_titre(Biblio * b, char * titre);
Biblio* recherche_livres_auteur(Biblio * b, char * auteur);
void supprimer_un_ouvrage(Biblio * b, int num, char * auteur, char * titre);
#endif