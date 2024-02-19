#ifndef BIBLIOH
#define BIBLIOH

typedef struct livreh {
    int clef ;
    int num;
    char * titre;
    char * auteur;
    struct livreh * suivant ;
} LivreH ;

typedef struct table {
    int nE ; /*nombre d’elements contenus dans la table de hachage */
    int m ; /*taille de la table de hachage */
    LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

LivreH * creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH * l);

BiblioH * creer_biblio(int m);
void liberer_biblio(BiblioH * b);

void afficher_BiblioH(BiblioH * b);
void afficher_LivreH(LivreH * livre);

int fonctionClef(char * auteur);
int fonctionHachage(int cle, int m);

void inserer(BiblioH* b,int num,char* titre,char* auteur);
LivreH * recherche_par_numero_H(BiblioH * b, int num);
LivreH * recherche_par_titre_H(BiblioH * b, char * titre);
BiblioH * recherche_livres_auteur_H(BiblioH * b, char * auteur);
void supprimer_ouvrage_H(BiblioH * b, int num, char * titre, char * auteur);
void fusion_BiblioH(BiblioH **b1, BiblioH **b2);
LivreH * recherche_ouvrage_plusieurs_exemplaires(BiblioH * b);


#endif