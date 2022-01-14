# Principe

Le handler `Controller` met à disposition des méthodes statiques de test
de pression de boutons, de position de sticks... pour une ***manette GameCube***
similaires à celles de la classe `sf::Keyboard` de la SFML.

# Quickstart

Pour faire fonctionner ce handler, il suffit d'exécuter à chaque frame la 
méthode :

> `Controller::update();`

Pour avoir une vision rapide des méthodes disponibles, allez voir les 
commentaires du *.hpp* !

# Connecter une manette GameCube à un ordinateur

Pour pouvoir utiliser une manette GameCube, vous aurez besoin d'une manette 
GameCube (Incroyable je sais.) et d'un adaptateur USB-GameCube, officiel de 
préférence (Je sais c'est chiant).

Voici un tutoriel d'installation pour pouvoir utiliser votre adaptateur sur 
votre ordinateur :

1. Télécharger [Zadig](https://zadig.akeo.ie/).
   
2. Ouvrez le menu `Options`, et cochez `List all devices`.

3. Sélectionnez dans la liste `WUP-028` et assurez vous que l'USB ID est bien 
   `057E 0337`.
   (Si `WUP-028` n'apparait pas, essayez de rebrancher votre adaptateur sur un 
   autre port USB. Branchez bien le cordon USB noir.)

4. Selectionnez `WinUSB` dans la colonne de droite, et ensuite cliquez sur `Replace Driver`.

5. Ignorez les cris désespérés de votre ordinateur et redémarez votre 
   ordinateur.

6. Téléchargez la dernière release de [Delfinovin](https://github.com/Struggleton/Delfinovin/releases).

7.  Ouvrez Delfinovin, et vérifiez que vos manettes sont connectées. Vérifiez 
    bien que les boutons sont bien mappés, et modifiez le mapping (`Edit`) si 
    nécessaire.

Maintenant, à chaque fois que vous voudrez utiliser vos manettes GameCube, 
Delfinovin devra être ouvert.

# TODO

* Diversifier les manettes détectables. Priorité à la manette XBox qui devrait être plus facile.
* Vérifier que le handler marche bien indépendemment du systme. Notamment la consistance de Delphinofin et du système d'ID de la SFML.
* Reverse engine Delfinovin pour l'intégrer à l'exécutable.