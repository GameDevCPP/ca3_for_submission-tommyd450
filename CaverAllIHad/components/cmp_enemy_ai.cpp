#include "cmp_enemy_ai.h"
#include "LevelSystem.h"
#include "cmath"

using namespace std;
using namespace sf;

void EnemyAIComponent::update(double dt) {
  auto mov = _direction * (float)(dt * _speed);
  mov.x += _direction.x * 16.f;
  if (!validMove(_parent->getPosition() + mov)) {
    _direction *= -1.f;
  }

  move(_direction * (float)(dt * _speed));
    createRoute();
  ActorMovementComponent::update(dt);
}

void EnemyAIComponent::createRoute()
{
    Vector2ul start (_parent->getPosition().x,_parent->getPosition().y);
    auto tiles = ls::findTiles(ls::EMPTY);
    vector<Vector2<size_t>> current = ls::findTiles(ls::getTileAt(_parent->getPosition()));

    //cout << ls::getTilePosition(start.loc).x;
    vector<Vector2ul> cList;
    vector<Vector2ul> oList;
    oList.push_back(start);


}

EnemyAIComponent::EnemyAIComponent(Entity* p, std::shared_ptr<Entity> player) : ActorMovementComponent(p) {
  _direction = Vector2f(1.0f, 0);
  _speed = 100.0f;
  _player = player;
}
