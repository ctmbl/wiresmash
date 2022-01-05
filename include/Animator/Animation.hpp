#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <functional>
#include <memory>
#include "Animator/Transition.hpp"

#define METHOD(class,instance,method) (std::bind((&class::method), (instance), std::placeholders::_1))

class Animation
{
protected:
    /**
     * @brief Le nombre total de frames de l'animation
     */
    int nbFrames;
    /**
     * @brief La liste des transitions possibles partant de cette animation
     */
    std::vector<Transition*> transitions;
    /**
     * @brief Un pointeur vers l'animation qui est automatiquement jouée à la fin de cette animation.
     */
    Animation* endAnimation;

public:
    /*****************************************************************************************************
     *        CONSTRUCTEURS ET DESTRUCTEURS
     *****************************************************************************************************/
    Animation(int const nbFrames);
    Animation(int const nbFrames, Animation* const endAnimation);
    virtual ~Animation() = 0;

    /*****************************************************************************************************
     *        ACCESSEURS
     *****************************************************************************************************/
    int                              getNbFrames();
    std::vector<Transition*>         getTransitions();
    Animation*                       getEndAnimation();

    /*****************************************************************************************************
     *        MUTATEURS
     *****************************************************************************************************/
    void setEndAnimation(Animation* const endAnimation);
    void addTransition(Transition* transition);

    /**
     * @brief Une fonction à exécuter à chaque frame de l'animation.
     * @param currentFrame Le numéro de la frame actuelle de l'animation.
     */
    virtual void action(int currentFrame) = 0;
};

#endif