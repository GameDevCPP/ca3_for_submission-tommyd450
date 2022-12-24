#include "ecm.h"
#include "SFML/Audio.hpp"
#include <string>
class Soundcmp : public Component {
protected:

public:
    sf::SoundBuffer aBuffer;
    sf::Sound sound;
    void update(double dt) override;
    virtual void load(std::string loadRoute);
    void render() override {};
    void play();
    explicit Soundcmp(Entity* p);
    Soundcmp() = delete;

};
