//
// Created by Tommy on 04/12/2022.
//
#include "system_physics.h"
#include <LevelSystem.h>
#include <SFML/Window/Keyboard.hpp>
#include "cmp_item_jetpack.h"
#include "cmp_player_physics.h"

using namespace std;
using namespace sf;
using namespace Physics;



void ItemJetpackComponent::update(double dt)
{
    const auto pos = _parent->getPosition();

    //Teleport to start if we fall off map.



    // Handle Jump


    //Are we in air?


    //Clamp velocity.

}

ItemJetpackComponent::ItemJetpackComponent(Entity *p,const Vector2f& size,std::shared_ptr<Entity> player) :  PhysicsComponent(p, true, size)
{
    _player=player;
}


