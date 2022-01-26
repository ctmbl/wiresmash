Interfaces:

```
(1) Events Cond/Ett: void flush(unsigned short [NB_KEYS])
(2) Collisions Cond/PhX : std::vector<collisioner> checkCollision(std::vector<Entity>)
(3) Pos Update Cond/Ett : 
```

RQ sur (2):
le cond envoie TOUT, la phX teste si les hitbox "toucheur" collisionnent les "touchable"
struct collisionner:
    toucheur
    touché
    vector d'intrication



Controllable :

    La classe Controllable hérite de Strategy et permet de créer un objet Controllable qui sera en attribut d'un entity.
    Dans la classe se trouve un attribut composé d'un tableau de clés reliées à plusieurs fcts callback différentes.

    Pour utiliser la classe il faut donc créer l'objet, et utiliser la fct add callback, qui ajoute une fct à appeler si une certaine clef est envoyée.

    Les clefs sont pour l'instant des std::Array de taille NB_KEYS.

    Enfin la fct flush prend en entrée une clef et exécute les fcts correspondantes
