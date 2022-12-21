#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components//cmp_item_jetpack.h"
#include "../components/cmp_sprite.h"
#include "../game.h"
#include "../components/cmp_key.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <../cellAuto/cellularAutomata.h>

using namespace std;
using namespace sf;
using namespace CA;

static shared_ptr<Entity> player;
static shared_ptr<KeyTracker> kt;

void Level1Scene::Load() {
    CellularAutomataGen::noiseGeneration();
    CellularAutomataGen::unNaturalSelection();

  cout << " Scene 1 Load" << endl;
  ls::loadLevelFile("../bin/res/levels/level_2.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));


  // Create player
  {
    player = makeEntity();

    player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
    cout<<player->getPosition()<<endl;

    auto s = player->addComponent<ShapeComponent>();
    s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
    s->getShape().setFillColor(Color::Magenta);
    s->getShape().setOrigin(Vector2f(10.f, 15.f));

    player->addComponent<PlayerPhysicsComponent>(Vector2f(20.f, 30.f));
    kt = player->addComponent<KeyTracker>();
  }

    auto keys = ls::findTiles(ls::KEY);
    for(auto k : keys)
    {
        auto pos = ls::getTilePosition(k);
        pos += Vector2f(20.f, 20.f); //offset to center
        auto key = makeEntity();
        key->setPosition(pos);
        auto o = key->addComponent<ShapeComponent>();
        o->setShape<sf::CircleShape>(8.f,3);
        o->getShape().setFillColor(Color::Yellow);
        key->addComponent<KeyItemComponent>(player,kt);
    }


  // Add physics colliders to level tiles.
  {
    auto walls = ls::findTiles(ls::WALL);
    for (auto w : walls) {
      auto pos = ls::getTilePosition(w);
      pos += Vector2f(20.f, 20.f); //offset to center
      auto e = makeEntity();
      e->setPosition(pos);
      e->addComponent<PhysicsComponent>(false, Vector2f(40.f, 40.f));
    }
  }

  //Simulate long loading times
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  cout << " Scene 1 Load Done" << endl;

  setLoaded(true);
}

void Level1Scene::UnLoad() {
  cout << "Scene 1 Unload" << endl;
    kt.reset();
  player.reset();

  ls::unload();
  Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {

    sf::View view1(sf::FloatRect(600.f, 1200.f, 2000.f, 1000.f));
    view1.setCenter(player->getPosition().x,player->getPosition().y);
    Engine::GetWindow().setView(view1);
  if (ls::getTileAt(player->getPosition()) == ls::END && kt->keysCollected) {
    Engine::ChangeScene((Scene*)&level2);
  }



  Scene::Update(dt);
}

void Level1Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
