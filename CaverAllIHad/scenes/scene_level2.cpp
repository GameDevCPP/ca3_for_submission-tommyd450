#include "scene_level2.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_enemy_turret.h"
#include "../components/cmp_hurt_player.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_key.h"
#include "../components/cmp_key_sound.h""

#include "../game.h"

#include <LevelSystem.h>
#include <iostream>
using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
static shared_ptr<KeyTracker> kt;

void Level2Scene::Load() {
  cout << "Scene 2 Load" << endl;
  ls::loadLevelFile("../bin/res/levels/level_2.txt", 40.0f);
  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Create player
  {
    // *********************************
      player = makeEntity();
      player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
      auto s = player->addComponent<ShapeComponent>();
      s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
      s->getShape().setFillColor(Color::Magenta);
      s->getShape().setOrigin(Vector2f(10.f, 15.f));

      player->addComponent<PlayerPhysicsComponent>(Vector2f(20.f, 30.f));
    player->addTag("player");
    kt = player->addComponent<KeyTracker>();
  }

  // Create Enemy
  {

    auto enemy = makeEntity();
    enemy->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[0]) +
                       Vector2f(0, 24));
    // *********************************
    // Add HurtComponent
    enemy->addComponent<HurtComponent>();
    // Add ShapeComponent, Red 16.f Circle
      auto s = enemy->addComponent<ShapeComponent>();
      s->setShape<sf::CircleShape>(16.0f);
      s->getShape().setFillColor(Color::Red);


    // Add EnemyAIComponent
    enemy->addComponent<EnemyAIComponent>(player);
    // *********************************
  }

  // Create Turret
  {
    auto turret = makeEntity();
    turret->setPosition(ls::getTilePosition(ls::findTiles('t')[0]) +
                        Vector2f(20, 0));
    auto s = turret->addComponent<ShapeComponent>();
    s->setShape<sf::CircleShape>(16.f, 3);
    s->getShape().setFillColor(Color::Red);
    s->getShape().setOrigin(Vector2f(16.f, 16.f));
    turret->addComponent<EnemyTurretComponent>();
  }

    auto key = makeEntity();
    key->setPosition(ls::getTilePosition(ls::findTiles('k')[0]));
    auto o = key->addComponent<ShapeComponent>();
    o->setShape<sf::CircleShape>(8.f,3);
    o->getShape().setFillColor(Color::Yellow);
    key->addComponent<KeySound>(player);
    key->addComponent<KeyItemComponent>(player,kt);


  // Add physics colliders to level tiles.
  {
    // *********************************

          auto walls = ls::findTiles(ls::WALL);
          for (auto w : walls) {
              auto pos = ls::getTilePosition(w);
              pos += Vector2f(20.f, 20.f); //offset to center
              auto e = makeEntity();
              e->setPosition(pos);
              e->addComponent<PhysicsComponent>(false, Vector2f(40.f, 40.f));
          }


    // *********************************
  }

  cout << " Scene 2 Load Done" << endl;
  setLoaded(true);
}

void Level2Scene::UnLoad() {
  cout << "Scene 2 UnLoad" << endl;
  player.reset();
  kt.reset();
  ls::unload();
  Scene::UnLoad();
}

void Level2Scene::Update(const double& dt) {

  Scene::Update(dt);
    sf::View view1(sf::FloatRect(600.f, 1200.f, 2000.f, 1000.f));
    view1.setCenter(player->getPosition().x,player->getPosition().y);
    Engine::GetWindow().setView(view1);
  const auto pp = player->getPosition();
  if (ls::getTileAt(pp) == ls::END && kt->keysCollected ==1) {
    Engine::ChangeScene((Scene*)&level3);
  } else if (!player->isAlive()) {
    Engine::ChangeScene((Scene*)&level2);
  }
}

void Level2Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
