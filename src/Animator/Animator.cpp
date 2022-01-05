#include "Animator/Animator.hpp"
#include "Animator/AnimationGraph.hpp"

std::vector<AnimationGraph*> Animator::animationGraphs = std::vector<AnimationGraph*>();

int Animator::addAnimationGraph(AnimationGraph* animationGraph) {
    animationGraphs.push_back(animationGraph);
    return animationGraphs.size()-1;
}

void Animator::removeAnimationGraph(int id) {
    animationGraphs.erase(animationGraphs.begin() + id);
}

void Animator::flush() {
    for (AnimationGraph* animationGraph : animationGraphs) {
        animationGraph->executeCurrentFrame();
        animationGraph->goToNextFrame();
    }
}