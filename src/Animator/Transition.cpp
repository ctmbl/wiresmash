#include "Animator/Transition.hpp"

Transition::Transition(Animation* targetAnimation) {
    this->targetAnimation = targetAnimation;
}

Transition::~Transition() {};

Animation* Transition::getTargetAnimation() {return targetAnimation;}