
#include "cmp_sound.h"
#include <SFML/Window/Keyboard.hpp>
#include "cmp_player_physics.h"

using namespace CR;

class PlayerSound : public Soundcmp {
protected:
    std::shared_ptr<Entity> _player;
public:

    void update(double dt) override;
    explicit PlayerSound(Entity* p, std::shared_ptr<Entity> pl);
    ~PlayerSound() = default;

};