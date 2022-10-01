# IUTConnect

## Fonctionnement et objectif de l'application
Cette application a pour objectif de vous faciliter la connexion aux stations linux de l'IUT2 de Grenoble.  
Pour cela, elle sélectionne la station la moins occupée via cette [page](https://www-info.iut2.univ-grenoble-alpes.fr/intranet/informations/cellule-info/etat-stations.php) et vous connecte dessus.  
Elle ne vous connectera JAMAIS au serveur transit, qui est reservé pour les sessions SSH uniquement.

</br>



## Première utilisation :

### Sous linux :

- Ouvrez un terminal à la racine du projet

- Installez tiger-vncviewer avec la commande suivante :  
> `sudo apt install tigervnc-viewer`

- Lancez le script avec la commande suivante :
> `./bin/linux`

</br>

### Sous windows :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `bin\win.exe`

</br>



## Utilisation :

### Sous linux :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `./bin/linux`

</br>

### Sous windows :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `bin\win.exe`

</br>



## Problèmes :

### Sous linux :

- Ouvrez un terminal à la racine du projet

- Compilez le script en lançant la commande suivante à la racine du projet :
> `gcc -std=c99 -Wall -Wextra -g -o ./bin/linux ./src/main.c`

- Rendez exécutable le fichier avec la commande suivante :
> `chmod +x ./bin/linux.sh`

- Lancez le script avec la commande suivante :
> `./bin/linux`

</br>

### Sous windows :

- Ouvrez un terminal à la racine du projet

- Suivez ce [tutoriel](https://fr.wikihow.com/compiler-un-programme-en-C-avec-le-compilateur-GNU-GCC#Utiliser-MinGW-sous-Windows) pour installer le compilateur gcc :

- Compilez le script avec la commande suivante :
> `gcc -std=c99 -Wall -Wextra -g -o ./bin/win ./src/main.c`

- Lancez le script avec la commande suivante :
> `bin\win.exe`

</br>

- Si vos problèmes ne sont toujours pas résolus, vous pouvez me contacter sur Discord : `STR#8828`