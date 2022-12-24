//
// Created by Tommy on 24/12/2022.
//

#include "cmp_sound.h"

void Soundcmp::update(double dt){};


void Soundcmp::load(std::string loadRoute)
{
    aBuffer.loadFromFile(loadRoute);
}

void Soundcmp::play()
{
    sound.setBuffer(aBuffer);
    sound.play();
}

Soundcmp::Soundcmp(Entity *p) : Component(p)
{

}

