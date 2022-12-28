#include "ecm.h"
#include "SFML/Audio.hpp"
#include <string>

#ifndef cmp_sound_h
#define cmp_sound_h
#include "../lib_csvRead/csvReader.h"

class Soundcmp : public Component {
protected:

public:
    sf::SoundBuffer aBuffer;
    sf::Sound sound;
    void update(double dt) override;
    virtual void load(std::string loadRoute);
    void render() override {};
    void play();
    void stop();
    explicit Soundcmp(Entity* p);
    Soundcmp() = delete;

};
#endif