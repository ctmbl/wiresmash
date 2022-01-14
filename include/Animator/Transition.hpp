#ifndef TRANSITION_HPP
#define TRANSITION_HPP

class Animation;

class Transition
{
protected:
    /**
     * @brief Un pointeur vers l'Animation vers laquelle transitionner si la transition est activée
     * 
     */
    Animation* targetAnimation;
public:
    Transition(Animation* targetAnimation);
    virtual ~Transition() = 0;

    Animation* getTargetAnimation();

    virtual bool isTriggered(int currentFrame) = 0;
};

#endif