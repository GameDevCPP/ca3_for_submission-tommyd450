//
// Created by Tommy on 20/12/2022.
//
#include "cmp_key.h"


void KeyItemComponent::update(double dt)
{
    if (auto pl = _player) {
        if (length(pl->getPosition() - _parent->getPosition()) < 25.0) {
            _kt->keysCollected++;
            _parent->setForDelete();
        }
    }
}



KeyItemComponent::KeyItemComponent(Entity *p, std::shared_ptr<Entity> player,std::shared_ptr<KeyTracker> kt) : Component(p)
{
    _player=player;
    _kt=kt;
}