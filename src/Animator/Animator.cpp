#include "Animator/Animator.hpp"
#include "Animator/AnimationStrategy.hpp"

std::map<int, AnimationStrategy*> Animator::animationStrategies = std::map<int, AnimationStrategy*>();
int Animator::idGen = 0;

int Animator::addAnimationStrategy(AnimationStrategy* animationStrategy) {
    idGen++;
    animationStrategies.insert({idGen, animationStrategy});
    return idGen;
}

void Animator::removeAnimationStrategy(int id) {
    animationStrategies.erase(id);
}

void Animator::flush() {
    for (std::pair<int, AnimationStrategy*> element : animationStrategies) {
        element.second->executeCurrentFrame();
        element.second->goToNextFrame();
    }
}