/////////////////////////////////////////////////////////////////////////////
/////   SCRIPT D'AUTOMATISATION DE LA CONNEXION AU RÉSEAU DE L'IUT 2    /////
/////                     CRÉDITS : SÉBASTIEN RUET                      /////
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 1024

int main(void) {
    // Importation des données du site avec curl
    system("curl https://www-info.iut2.univ-grenoble-alpes.fr/intranet/informations/cellule-info/etat-stations.php > ./tmp/tmp.txt");

    // Ouverture du fichier et initialisation du buffer
    FILE *file = fopen("./tmp/tmp.txt", "r+");
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
        char name[13];
        unsigned int nbUsers;
    } Poste;

    // Création d'un tableau de Poste
    Poste postes[100];
    unsigned int nbPostes = 0;

    // Création d'un binaire pour savoir si les postes sont allumés
    int etat_stations = 0;

    Poste poste_temp;
    char nb_usrs_temp[3];

    for (int i = 0; !feof(file); i++) {
        // Ligne de type : pc-dg-025-01  up       1:19,     2 users,  load 0.32, 0.40, 0.51
        fgets(temp, BUFFER_LEN, file);

        // On vérifie que la ligne commence par 'pc-dg-0'
        if (strncmp(temp, "pc-dg-0", 7) == 0) {
            // On vérifie que le pc est up
            if (strstr(temp, "up") != NULL) {
                // On récupère le nom du poste
                strncpy(poste_temp.name, temp, 12);
                poste_temp.name[13] = '\0';

                // On récupère le nombre d'utilisateurs
                strncpy(nb_usrs_temp, temp + 32, 2);
                nb_usrs_temp[3] = '\0';
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
    char usr_name[32];

    // Vérication de l'état des postes
    if (etat_stations == 1) {
        for (unsigned int i = 0; i < nbPostes; i++) {
                for (int j = 0; j < 100; j++) {
                    if (postes[j].nbUsers == i)
                    {
                        // On demande le nom de l'utilisateur
                        printf("Entrez votre nom d'utilisateur : ");
                        scanf("%s", usr_name);

                        // On envoie la commande
                        sprintf(cmd, "ssh -fNL 5900:%s:5900 %s@transit.iut2.univ-grenoble-alpes.fr", postes[j].name, usr_name);
                        system(cmd);
                        printf("Vous êtes connecté au poste %s\n", postes[j].name);

                        // On vérifie l'os et on se connecte en vnc
                        #if defined(_WIN32)
                            system("win\\TigerVNC\\vncviewer.exe localhost");
                        #elif defined(__linux__)
                            system("xtigervncviewer localhost");
                        #elif defined(__APPLE__)
                            // Non pris en charge pour le moment
                            printf("Non pris en charge pour le moment\n");
                            return EXIT_FAILURE;
                        #endif
                        
                    }
                }
            }
    } else {
        printf("Les stations sont eteintes !\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}