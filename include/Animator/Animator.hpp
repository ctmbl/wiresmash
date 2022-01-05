#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <vector>
#include <memory>

class AnimationGraph;

class Animator
{
private:
    static std::vector<AnimationGraph*> animationGraphs;
public:
    int static addAnimationGraph(AnimationGraph* animationGraph);
    void static removeAnimationGraph(int id);
    void static flush();
};

#endif