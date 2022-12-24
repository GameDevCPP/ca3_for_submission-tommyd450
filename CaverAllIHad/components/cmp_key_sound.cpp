//
// Created by Tommy on 24/12/2022.
//

#include "cmp_key_sound.h"


void KeySound::update(double dt)
{
    if (length(_player->getPosition() - _parent->getPosition()) < 25.0) {

        load("../bin/res/sound/Click.wav");
        play();
        //_parent->setForDelete();
    }

}



KeySound::KeySound(Entity *p, std::shared_ptr<Entity> pl) : Soundcmp(p)
{
    _player = pl;
}