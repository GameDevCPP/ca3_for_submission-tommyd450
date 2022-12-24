
#include "cmp_player_sounds.h"
#include "cmp_player_physics.h"


void PlayerSound::update(double dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& _player->get_components<PlayerPhysicsComponent>()[0]->isGrounded()) {
        load("../bin/res/sound/slime_jump.wav");
        play();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& _player->get_components<PlayerPhysicsComponent>()[0]->isGrounded()) {
        load("../bin/res/sound/jetNoise.wav");
        play();

    }else{};

}



PlayerSound::PlayerSound(Entity *p, std::shared_ptr<Entity> pl) : Soundcmp(p)
{
    _player = pl;
}