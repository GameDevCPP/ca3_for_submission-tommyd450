//
// Created by Tommy on 04/12/2022.
//
#include "system_physics.h"
#include <LevelSystem.h>
#include <SFML/Window/Keyboard.hpp>
#include "cmp_item_jetpack.h"

using namespace std;
using namespace sf;
using namespace Physics;



void ItemJetpackComponent::update(double dt)
{
    const auto pos = _parent->getPosition();

    //Teleport to start if we fall off map.



    // Handle Jump


    //Are we in air?


    // Clamp velocity.
   // auto v = getVelocity();
   // v.x = copysign(min(abs(v.x), _maxVelocity.x), v.x);
   // v.y = copysign(min(abs(v.y), _maxVelocity.y), v.y);
    //s//etVelocity(v);

    //PhysicsComponent::update(dt);
}

ItemJetpackComponent::ItemJetpackComponent(Entity *p,const Vector2f& size) :  PhysicsComponent(p, true, size)
{

}


