#include "cmp_KeyTracker.h"


void KeyTracker::update(double dt)
{
    //std::cout<<keysCollected<<std::endl;
}



KeyTracker::KeyTracker(Entity *p)  : Component(p)
{
    keysCollected =0;
}