#include "Animator/Animation.hpp"

#define UNUSED(expr) do { (void)(expr); } while (0)

Animation::Animation(int const nbFrames) {
    this->nbFrames = nbFrames;
    this->transitions = std::vector<Transition*>();
    this->endAnimation = this;
}

Animation::Animation(int const nbFrames, Animation* const endAnimation) {
    this->nbFrames = nbFrames;
    this->transitions = std::vector<Transition*>();
    this->endAnimation = endAnimation;
}

Animation::~Animation() {}

int                      Animation::getNbFrames() {return nbFrames;}
std::vector<Transition*> Animation::getTransitions() {return transitions;}
Animation*               Animation::getEndAnimation() {return endAnimation;}

void Animation::setEndAnimation(Animation* const endAnimation) {this->endAnimation = endAnimation;}

void Animation::addTransition(Transition* transition) {
    transitions.push_back(transition);
}