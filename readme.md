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

- Rendez exécutable le fichier avec la commande suivante :
> `chmod +x ./bin/linux.sh`

- Lancez le script avec la commande suivante :
> `./bin/linux`

- Renseigner votre nom d'utilisateur UGA quand il est demandé dans la console

- Entrer 'yes' dans la console afin d'ajouter le serveur SSH parmi les hôtes connus

- Entrer votre mot de passe UGA quand il est demandé dans la console

- Vous connecter normalement à la station avec vos identifiants UGA

</br>

### Sous windows :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `bin\win.exe`

- Renseigner votre nom d'utilisateur UGA quand il est demandé dans la console

- Cliquer sur 'Yes' dans la fenêtre PuTTY qui s'ouvre et y rentrer votre mot de passe UGA

- Une fois connecté, cliquer sur 'Yes' dans la fenêtre TigerVNC qui s'ouvre en arrière plan

- Vous connecter normalement à la station avec vos identifiants UGA

</br>



## Utilisation :

### Sous linux :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `./bin/linux`

- Renseigner votre nom d'utilisateur UGA quand il est demandé dans la console

- Entrer votre mot de passe UGA quand il est demandé dans la console

- Vous connecter normalement à la station avec vos identifiants UGA

</br>

### Sous windows :

- Ouvrez un terminal à la racine du projet

- Lancez le script avec la commande suivante :
> `bin\win.exe`

- Renseigner votre nom d'utilisateur UGA quand il est demandé dans la console

- Rentrer votre mot de passe UGA dans la fenêtre PuTTY qui s'ouvre

- Une fois connecté, cliquer sur 'Yes' dans la fenêtre TigerVNC qui s'ouvre en arrière plan

- Vous connecter normalement à la station avec vos identifiants UGA

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