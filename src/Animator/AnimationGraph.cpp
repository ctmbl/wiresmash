#include "Animator/AnimationStrategy.hpp"
#include "Animator/Animator.hpp"

AnimationStrategy::AnimationStrategy(Animation* const startingPoint) {
    this->currentAnimation = startingPoint;
    this->currentFrame = 0;
    this->associatedId = Animator::addAnimationStrategy(this);
}

AnimationStrategy::~AnimationStrategy() {
    Animator::removeAnimationStrategy(associatedId);
}

int AnimationStrategy::getAssociatedId() {return associatedId;}

void AnimationStrategy::goToNextFrame() {
    // Si une transition est déclenchée, on va au début de l'animation correspondante
    for (Transition* transition : currentAnimation->getTransitions()) {
        if (transition->isTriggered(currentFrame)) {
            currentAnimation = transition->getTargetAnimation();
            currentFrame = 0;
            return;
        }
    }

    // Si on atteint la fin de l'animation actuelle, on va au début de l'animation désignée comme suite
    if (currentFrame == currentAnimation->getNbFrames()-1) {
        currentAnimation = currentAnimation->getEndAnimation();
        currentFrame = 0;
        return;
    }

    // Sinon, on avance d'une frame
    currentFrame++;
}

void AnimationStrategy::executeCurrentFrame() {
    currentAnimation->action(currentFrame);
}