




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

int main(){


    return 0;
}