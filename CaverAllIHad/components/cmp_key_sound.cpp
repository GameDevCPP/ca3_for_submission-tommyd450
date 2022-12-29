//
// Created by Tommy on 24/12/2022.
//

#include <chrono>
#include "cmp_key_sound.h"



void KeySound::update(double dt)
{

    if (length(_player->getPosition() - _parent->getPosition()) < 25.0 && !forDeletion) {

        load(CsvReader::readFile("../bin/res/soundpath.csv","3")[2]);
        play();
        forDeletion = true;

    }
    if(forDeletion)
    {
        //std::cout<<"Test"<<std::endl;
        deletionDT += dt;
    }
    if(deletionDT>0.1)
    {
        _parent->setForDelete();
    }

}



KeySound::KeySound(Entity *p, std::shared_ptr<Entity> pl) : Soundcmp(p)
{
    _player = pl;
    forDeletion = false;
    deletionDT = 0;
}