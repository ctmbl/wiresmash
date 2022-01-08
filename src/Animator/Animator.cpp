#include "Animator/Animator.hpp"
#include "Animator/AnimationGraph.hpp"

std::map<int, AnimationGraph*> Animator::animationGraphs = std::map<int, AnimationGraph*>();
int Animator::idGen = 0;

int Animator::addAnimationGraph(AnimationGraph* animationGraph) {
    idGen++;
    animationGraphs.insert({idGen, animationGraph});
    return idGen;
}

void Animator::removeAnimationGraph(int id) {
    animationGraphs.erase(id);
}

void Animator::flush() {
    for (std::pair<int, AnimationGraph*> element : animationGraphs) {
        element.second->executeCurrentFrame();
        element.second->goToNextFrame();
    }
}