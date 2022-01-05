#ifndef TRANSITION_HPP
#define TRANSITION_HPP

class Animation;

class Transition
{
protected:
    Animation* targetAnimation;
public:
    Transition(Animation* targetAnimation);
    virtual ~Transition() = 0;

    Animation* getTargetAnimation();

    virtual bool isTriggered(int currentFrame) = 0;
};

#endif