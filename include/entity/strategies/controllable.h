#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H
#include "strategy.h"
#include <SFML/Window.hpp>
#include <functional>
#include <string>
#include <vector>
#include <map>

#define NB_KEYS 256



class Controllable : public virtual Strategy
{
private:
    std::vector<std::pair<std::array<unsigned short, NB_KEYS>,std::vector<std::function<void()>> > > callBacks; 

    std::vector<std::pair<std::function<bool(std::array<unsigned short, NB_KEYS> )>, std::function<void()>>  > callBacks_func; 

public:
    Controllable(/* args */);
    ~Controllable();

    void flush(std::array<unsigned short, NB_KEYS> &inputs); //receive an array of boolean (flags) representing if some keys are pressed, 
    // WARNIGN needs a convention (between conductor.ControllableHandler and this class) on that boolean array

    void addCallBack(std::array<unsigned short, NB_KEYS> condition, std::function<void()> callback); 
    // add a callback function to the Controllable


    void addCallBack_func(std::function<bool ( std::array<unsigned short, NB_KEYS> )> condition, std::function<void()> callback); 

};







#endif