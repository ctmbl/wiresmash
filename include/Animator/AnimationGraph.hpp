#ifndef ANIMATION_GRAPH_HPP
#define ANIMATION_GRAPH_HPP

#include <vector>
#include <iostream>
#include "Animator/Animation.hpp"

class Animator;

class AnimationGraph
{
private:
    /**
     * @brief Un pointeur vers l'animation qui est jouée actuellement
     */
    Animation* currentAnimation;
    /**
     * @brief Le numéro de la frame jouée actuellement dans l'aniation
     */
    int currentFrame;
    /**
     * @brief L'Id associé à ce graphe dans la liste de graphes de l'Animator
     */
    int associatedId;
public:

    /*****************************************************************************************************
     *        CONSTRUCTEURS ET DESTRUCTEURS
     *****************************************************************************************************/
    AnimationGraph(Animation* const startingPoint);
    ~AnimationGraph();

    /*****************************************************************************************************
     *        ACCESSEURS
     *****************************************************************************************************/
    int getAssociatedId();

    /*****************************************************************************************************
     *        METHODES
     *****************************************************************************************************/

    /**
     * @brief Calcule et modifie les attributs currentAnimation et currentFrame selon les transitions déclenchées,
     * si l'animationest terminée ou non.
     */
    void goToNextFrame();
    /**
     * @brief Exécute l'action de l'animation pointée à la bonne frame 
     */
    void executeCurrentFrame();
};

#endif