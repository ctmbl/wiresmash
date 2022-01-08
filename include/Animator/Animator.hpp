#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <vector>
#include <map>

class AnimationGraph;

class Animator
{
private:
    static int idGen;
    static std::map<int, AnimationGraph*> animationGraphs;
public:
    int static addAnimationGraph(AnimationGraph* animationGraph);
    void static removeAnimationGraph(int id);
    void static flush();
};

#endif