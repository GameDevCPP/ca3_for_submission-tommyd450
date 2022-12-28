
#include "ecm.h"
#include "SFML/Window/Keyboard.hpp"
#include "cmp_sound.h"


using namespace CR;

class KeySound : public Soundcmp {
protected:
    std::shared_ptr<Entity> _player;
public:
    bool forDeletion;
    double deletionDT;
    void update(double dt) override;
    explicit KeySound(Entity* p, std::shared_ptr<Entity> pl);
    ~KeySound() = default;

};