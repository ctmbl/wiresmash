#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include "strategy.h"
#include <SFML/Window.hpp>

#define NB_KEYS 256



class Controllable : public virtual Strategy
{
private:
    
public:
    Controllable(/* args */);
    ~Controllable();

    void flush(unsigned short[NB_KEYS] inputs); //flush ? events ?, receive an array of boolean (flags) representing if some keys are pressed, 
    // WARNIGN needs a convention (between conductor.ControllableHandler and this class) on that boolean array

};

Controllable::Controllable(/* args */)
{
}

Controllable::~Controllable()
{
}







#endif