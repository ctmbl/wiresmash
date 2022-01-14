ReadMe du système de dessin et de caméra

# Principe

Le handler `Drawer` gère l'affichage et le positionnement 
de la caméra, en permettant de précisier des options de 
paralaxe et de priorité.

# Utiliser le handler `Drawer`

Pour que `Drawer` fonctionne, on doit exécuter à chaque frame la méthode :

> `Drawer::flush(window);`

où `window` est la `sf::RenderWindow` utilisée.


# Contrôler la caméra

La position de la caméra est caractérisée par les 
coordonnées-monde du centre de l'image, et par son zoom.

Par défaut, le centre est aux coordonnées (0,0) du monde, et le zoom est à 1 (1 pixel sur un sprite est affiché par 1 pixel à l'écran).

Pour contrôler ces paramètres, vous pouvez utiliser les méthodes :

> `Drawer::setCenter(coordVector);`

> `Drawer::setZoom(zoom);`

> `Drawer::moveCenter(translationVector);`

*Exemple :*

    // Sans modification, la caméra est aux coordonnées
    // (0,0) et avec un zoom de 1.

    Drawer::setCenter(sf::Vector2f(1.0f, 1.0f));

    // Le centre est maintenant en (1,1).

    Drawer::moveCenter(sf::Vector2f(2.0f, 3.0f));

    // Le centre est maintenant en (3,4).

    Drawer::setZoom(3);

    // Le zoom est maintenant de 3.
    // 1 pixel sur un sprite est donc représenté par un 
    // carré de pixels 3x3 sur l'écran.

# Principe d'utilisation de `DrawStrategy`

* Les `DrawStrategy` sont des stratégies attachées à une entitée, qui contiennent les attributs et méthodes relatives à son affichage.

* L'afichage de ces stratégies est automatiquement géré par le handler `Drawer`.

* Pour créer une `DrawStrategy` vous passez au constructeur le chemin d'accès du fichier `fileStr` contenant l'image à afficher :

    > `DrawStrategy strat = DrawStrategy(fileStr);`

* La position de l'image correspond à celle de son coin supérieur gauche. Elle est par défaut fixée à (0,0).

  Pour la modifier, vous pouvez soit la préciser dans le constructeur au moment de la création :

  > `DrawStrategy strat = DrawStrategy(fileStr, posVector);`

  Soit la modifier ensuite en utilisant les méthodes :

  > `strat.setImagePosition(posVector);`

  > `strat.translateImagePosition(translationVector);`


# Principe d'utilisation de `AnimatedDrawStrategy`

* `AnimatedDrawStrategy` est une stratégie héritée de `DrawStrategy`. Elle a pour but non pas de gérer une image statique, mais un spritesheet, et a pour vocation d'être couplé avec le sytème d'animation pour créer des affichages animés.

* Pour créer une `AnimatedDrawStrategy`, en plus de préciser le fichier de la spritesheet, vous devez préciser :
    - La hauteur `height` et la largeur `width` du sprite.
    - Le nombre de lignes sur le spritesheet.

  > `AnimatedDrawStrategy strat = DrawStrategy(fileStr, height, width, nbLines);`

* Puisque `AnimetedDrawStrategy` hérite de `DrawStrategy`, la gestion de la position de l'affichage est la même.
  
* Seul une portion de dimensions `height` x `width` du spritesheet est affichée. Pour modifier cette portion, vous pouvez utiliser la méthode :

  > `strat.goToImage(line, frame);`

  pour sélectionner l'image à la ligne `line` et à la colonne `frame`.

  > **Remarque :** Cette méthode est principalement faite pour être intégrée à l'`action` d'une animation, et itérée sur le paramètre `frame`.


# Précisions sur le système de priorité et de paralaxe

* Vous pouvez préciser pour chaque `DrawStrategy` un facteur de paralaxe entier. Par défaut, celui-ci est fixé à `FOREGROUND_PARALAX_PLANE = 10`.

  Vous pouvez le modifier en utilisant la méthode :

  > `strat.setParalaxFactor(paralaxFactor);`

  En particulier, pour placer la `DrawStrategy` sur un arrière-plan fixe, vous pouvez fixer le facteur de paralaxe à 0.

  > **Remarque :** Les différents plans de paralaxe ne se déplacent pas à la même vitesse. Ainsi, l'attribut `center` de la caméra `Drawer` est exprimé dans les *coordonnées-monde du plan de paralaxe par défaut* `FOREGROUND_PARALAX_PLANE`.

* Vous pouvez aussi préciser un score de priorité d'affichage entre 0 (par défaut) et 3. Les stratégies avec un score de priorité plus élevé sont affichées en avant.
  
  Vous pouvez modifier de score avec la méthode :

  > `strat.setPriorityScore(score);`

* Pour résumer, les stratégies sont placées au premier plan :
    - Par ordre croissant de facteur de paralaxe
    - A facteur de paralaxe égal, par ordre croissant de score de priorité
    - A facteur de paralaxe et score de priorité égaux, la stratégie ajoutée le plus tard est affichée en avant.

# TODO

* Ajouter un facteur de zoom aux `DrawStrategy`
* Ajouter une `PaternDrawStrategy` qui se répète.
  * On peut ensuite imaginer des options pour répéter le patern indéfiniment, un certain nombre de fois, dans certaines directions uniquement, avec différent pavages...
* Ajouter une `ParticuleDrawStrategy` qui dessine plusieurs de ses copies pour les particules.
* Dessine (bruh)