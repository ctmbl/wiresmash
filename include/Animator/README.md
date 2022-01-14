# Principe

Le système d'animation se fonde sur la notion de graphe d'animation. 
Les sommets de ce graphe sont les animations, et les arètes sont les 
transitions.

# Quickstart

## 1. Créer les animations

Pour créer une animation, ***écrivez une classe qui hérite de la classe absrarite `Animation`***.

Cette classe doit override :

- le constructeur `Animation(int const nbFrames)`, où `nbFrames` est le 
    nombre de frames de l'animation.

- le destructeur `~Animation()`.

- la méthode abstraite `void action(int currentFrame)`.

    A chaque frame, la méthode `action` d'une animation est exécutée avec 
    pour argument le numéro de la frame actuelle.
    Ainsi, si l'animation `anim` est jouée, on exécute `anim.action(0)`, 
    puis à la frame suivante `anim.action(1)`, puis à la frame suivante 
    `anim.action(2)`...

*Exemple :*

    class AnimationTest : public Animation
    {
    public:
        AnimationTest(int const nbFrames);
        virtual ~JumpAnimation() override;
        virtual void action(int currentFrame) override;
    };

    // Override du constructeur.
    AnimationTest::AnimationTest(int const nbFrames):
    Animation(nbFrames) {}

    // Override du destructeur.
    AnimationTest::~AnimationTest() {}

    // Override de l'action
    void AnimationTest::action(int currentFrame) {
        std::cout << "L'animation est à la frame " << currentFrame << std::endl;
    }



## 2. Reliez les animations entre elles

Maintenant, les animations doivent savoir quoi faire une fois qu'elles sont 
terminées.

Par défaut, une animation recommence quand elle se termine.

Pour qu'une animation `anim1` fasse une transition vers `anim2` une fois 
terminée, utilisez la méthode :

> `anim1.setEndTransition(&anim2);`

> **/!\ Attention** : ***La méthode `setEndAnimation` prend en argument un pointeur. Assurez-vous donc qu'il pointe bien vers quelque chose de correct !***

*Exemple :*

    AnimationTest anim1 = AnimationTest(10);
    AnimationTest anim2 = AnimationTest(5);

    // Pour l'instant, anim1 et anim2 bouclent sur elles-mêmes

    anim1.setEndTransition(&anim2);
    anim2.setEndTransition(&anim1);

    // Maintenant, les deux animations transitionnent vers l'autre 
    // une fois terminées.
    // On verra donc : anim1 -> anim2 -> anim1 -> anim2 -> ...

    //! Assurez-vous bien que anim1 et anim2 ne sont pas effacées,
    //! ou alors modifiez les transitions de fin avant !


## 3. Rajoutez des transitions

On veut être capable de forcer la transition d'une animation vers une 
autre, par exemple en appuyant sur un bouton, ou si certaines conditions 
sont réunies.

Pour créer une transition, ***écrivez une classe qui hérite de la classe absrarite `Transition`***.
Cette classe doit override :

- le constructeur `Transition(Animation* targetAnimation)`, où 
`targetAnimation` est un pointeur vers l'animation
cible de la transition.

- le destructeur `~Transition()`.

- le déclencheur `bool isTriggered(int currentFrame)`.
A chaque frame, l'animation en train d'être joué teste la méthode 
`isTriggered` de toutes ses transitions. Si l'une d'entre elle renvoie 
`true`, la transition est déclenchée et on va au début de l'animation cible.

Pour rajouter une transition `tran` à une animation `anim`, on utilise :

> `anim.addTransition(&tran);`

> **/!\ Attention** : ***La méthode `addTransition` prend en argument un pointeur. Assurez-vous donc qu'il pointe bien vers quelque chose de correct !***

*Exemple d'héritage de `Transition`:*

    class TransitionTest : public Transition
    {
    public:
        TransitionTest(Animation* targetAnimation);
        virtual ~TransitionTest() override;

        virtual bool isTriggered(int currentFrame) override;
    };

    // Override du constructeur
    TransitionTest::TransitionTest(Animation* targetAnimation):
    Transition(targetAnimation) {}

    // Override du destructeur
    TransitionTest::~TransitionTest() {}

    // Override du déclencheur
    bool TransitionTest::isTriggered(int currentFrame) {
        return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    }

    // Cette transition est déclenchée dès que la touche A du clavier est pressée.

*Exemple d'utilisation :*

    TransitionTest tran1 = TransitionTest(&anim1);

    // La transition ainsi créée dirigera donc vers l'animation anim1

    anim2.addTransition(&tran1);

    // A partir de maintenant, appuyer sur A à n'importe quel moment de 
    // l'animation anim2 fera sauter vers l'anim1


> **Précision :** Les transitions sont testées dans l'ordre de leur ajout.
Si deux transitions sont déclenchées, seule la première à avoir été ajouté 
sera prise en compte.

> **Remarque :** Une transition peut être ajoutée à plusieurs animations.
On peut par exemple rajouter une transition à toutes les animations d'un 
graphe pour aller à son animation-cible quelque soit l'animation en cours 
si elle est déclenchée.


## 4. Créer une stratégie

La stratégie `AnimationStrategy` est une "tête de lecture" qui parcourt le 
graphe d'animations.

Les `AnimationStrategy` sont gérées automatiquement par le handler 
`Animator` si vous exécutez à chaque frame la méthode :

> `Animator::flush();`

*Exemple :*

    AnimationStrategy strat = AnimationStrategy(&anim1);

    // On initialise la stratégie sur l'animation anim1
    // En supposant que la méthode Animator::flush() est bien exécutée à 
    // chaque frame, le graphe est maintenant parcouru par la stratégie
    // et les animations et transitions fonctionnent.

# TODO

* Coder une factory pour les graphes d'animations.
* Rendre la stratégie `AnimationStrategy` consistante avec les autres stratégies, en lui ajoutant un pointeur vers son entité associée