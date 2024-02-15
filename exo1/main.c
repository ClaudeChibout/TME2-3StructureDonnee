#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc != 3) {
        printf("");
        return 1;
    }

    char * nom_fichier = argv[1];
    int nombre_ligne = atoi(argv[2]);

    FILE* fichier = fopen(nom_fichier, "a");
    printf("%s\n",nom_fichier);
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
        return 1;
    }

    char buffer[256]; 
    for (int i = 0; i < nombre_ligne; ++i) {
        if (fgets(buffer, sizeof(char), fichier) != NULL) {
            printf("%s", buffer);
        } else {
            printf("Fin du fichier atteinte avant les %d buffers demandées.\n", nombre_ligne);
            break;
        }
    }

    fclose(fichier);
    return 0;
}



