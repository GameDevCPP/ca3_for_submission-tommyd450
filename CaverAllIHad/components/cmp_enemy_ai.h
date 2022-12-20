#pragma once

#include "cmp_actor_movement.h"

class EnemyAIComponent : public ActorMovementComponent {
protected:
  sf::Vector2f _direction;
  std::shared_ptr<Entity> _player;
public:
  void update(double dt) override;
  void createRoute();
  void Traverse();

  explicit EnemyAIComponent(Entity* p, std::shared_ptr<Entity> player);

  EnemyAIComponent() = delete;
};
