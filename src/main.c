#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 1024

int main(void) {
    // Ouverture du fichier et initialisation du buffer
    FILE *file = fopen("../tmp/temp.txt", "r+");
    char temp[BUFFER_LEN];

    // Vérification des erreurs d'ouverture
    if (file == NULL) {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    } else {
        printf("File opened successfully\n");
    }

    // Création du type Poste
    typedef struct Poste {
        char name[12];
        unsigned int nbUsers;
    } Poste;

    // Création d'un tableau de Poste
    Poste postes[100];
    unsigned int nbPostes = 0;

    // Création d'un binaire pour savoir si les postes sont allumés
    int etat_stations = 0;

    Poste poste_temp;
    char nb_usrs_temp[2];

    for (int i = 0; !feof(file); i++) {
        // Ligne de type : pc-dg-025-01  up       1:19,     2 users,  load 0.32, 0.40, 0.51
        fgets(temp, BUFFER_LEN, file);

        // On vérifie que la ligne commence par 'pc-dg-0'
        if (strncmp(temp, "pc-dg-0", 7) == 0) {
            // On vérifie que le pc est up
            if (strstr(temp, "up") != NULL) {
                // On récupère le nom du poste
                strncpy(poste_temp.name, temp, 12);
                poste_temp.name[12] = '\0';

                // On récupère le nombre d'utilisateurs
                strncpy(nb_usrs_temp, temp + 32, 2);
                nb_usrs_temp[2] = '\0';
                poste_temp.nbUsers = atoi(nb_usrs_temp);

                // On ajoute le poste à la liste
                postes[nbPostes] = poste_temp;
                nbPostes++;

                // On met à jour l'état des postes
                if (etat_stations == 0) {
                    etat_stations = 1;
                }                
            }
        }        
    }

    fclose(file);

    char cmd[128];
    // Vérication de l'état des postes
    if (etat_stations == 1) {
        for (unsigned int i = 0; i < nbPostes; i++) {
                for (int j = 0; j < 100; j++) {
                    if (postes[j].nbUsers == i)
                    {
                        // On envoie la commande et on quitte le programme
                        sprintf(cmd, "ssh -f -N -L 5900:%s:5900 NOM_DE_LOGIN@transit.iut2.univ-grenoble-alpes.fr", postes[j].name);
                        system(cmd);
                        return EXIT_SUCCESS;
                    }
                }
            }
    } else {
        printf("Les stations sont éteintes !\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}