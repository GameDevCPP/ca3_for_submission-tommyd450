#include "cmp_enemy_ai.h"
#include "LevelSystem.h"
#include "cmath"

using namespace std;
using namespace sf;

void EnemyAIComponent::update(double dt) {
  auto mov = _direction * (float)(dt * _speed);
  Vector2f b = _player->getPosition();
  Vector2f c = _parent->getPosition();

  Vector2f dif = b-c;
  _direction.x = (dif.x >0)? 1 : -1;
  _direction.y = (dif.y>0)? 1: -1;



  
  move(_direction * (float)(dt * _speed),phase);
  ActorMovementComponent::update(dt);
}


EnemyAIComponent::EnemyAIComponent(Entity* p, std::shared_ptr<Entity> player) : ActorMovementComponent(p) {
  _direction = Vector2f(1.0f, 0);
  _speed = 60.0f;
  _player = player;
  phase = true;
}
