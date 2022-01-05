#include "Animator/AnimationGraph.hpp"
#include "Animator/Animator.hpp"

AnimationGraph::AnimationGraph(Animation* const startingPoint) {
    this->currentAnimation = startingPoint;
    this->currentFrame = 0;
    this->associatedId = Animator::addAnimationGraph(this);
}

AnimationGraph::~AnimationGraph() {
    //TODO : La suppression du tableau de Animator
}

int AnimationGraph::getAssociatedId() {return associatedId;}

void AnimationGraph::goToNextFrame() {
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

void AnimationGraph::executeCurrentFrame() {
    currentAnimation->action(currentFrame);
}