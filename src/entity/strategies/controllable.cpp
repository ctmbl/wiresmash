#include "entity/strategies/controllable.h"

#include <iostream>


void Controllable::addCallBack(std::array<unsigned short, NB_KEYS> inputs, std::function<void()> callback){
    
    for (int i = 0; i < callBacks.size(); i++)
    {
        if(callBacks[i].first == inputs){ /// adds the callback to the callBacks Vector
            callBacks[i].second.emplace_back(callback);
            return;
        }
    }

    std::vector<std::function<void()>> vec_call;
    vec_call.emplace_back(callback);

    std::pair<std::array<unsigned short, NB_KEYS>, std::vector<std::function<void()>> > a(inputs, vec_call);

    callBacks.emplace_back(a);
    
}


void Controllable::addCallBack_func(std::function<bool ( std::array<unsigned short, NB_KEYS> ) > condition, std::function<void()> callback){


    std::pair<std::function<bool ( std::array<unsigned short, NB_KEYS> ) >, std::function<void()> > a(condition, callback);


    callBacks_func.emplace_back(a);

    }

void Controllable::flush(std::array<unsigned short, NB_KEYS> &inputs){

    // Calls all callback functions ( without MAE)
    for (int i = 0; i < callBacks.size(); i++)
    {   
        if(callBacks[i].first == inputs){
            for (int j = 0; j < callBacks[i].second.size(); j++)
            {
                callBacks[i].second[j](); // flushes Every Callbacks
            }
            break;
        }
    }

    for (int i = 0; i < callBacks_func.size(); i++)
    {
        if(callBacks_func[i].first(inputs)){
            callBacks_func[i].second;
        }
        /* code */
    }
    
    
    

}



Controllable::Controllable(/* args */)
{
}

Controllable::~Controllable()
{
}