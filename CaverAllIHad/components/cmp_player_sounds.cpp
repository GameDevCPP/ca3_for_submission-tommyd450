
#include "cmp_player_sounds.h"
#include "cmp_player_physics.h"



void PlayerSound::update(double dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& _player->get_components<PlayerPhysicsComponent>()[0]->isGrounded()) {
        std::vector<std::string> p = CsvReader::readFile("../bin/res/soundpath.csv","1");
        load(p[2]);
        play();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& _player->get_components<PlayerPhysicsComponent>()[0]->isGrounded()==false) {
        std::vector<std::string> p = CsvReader::readFile("../bin/res/soundpath.csv","2");
        load(p[2]);
        play();

    }

}





PlayerSound::PlayerSound(Entity *p, std::shared_ptr<Entity> pl) : Soundcmp(p)
{
    _player = pl;

}