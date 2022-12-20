
#include "cmp_item.h"
#include "cmp_physics.h"
class ItemJetpackComponent : public PhysicsComponent {
protected:

    float time;
    b2Vec2 _size;
    sf::Vector2f _maxVelocity;
    bool _grounded;
    float _groundspeed;
    std::shared_ptr<Entity> _player;

    bool isGrounded() const;

public:
    void update(double dt) override;

    explicit ItemJetpackComponent(Entity* p,const sf::Vector2f& size,std::shared_ptr<Entity> player);

    ItemJetpackComponent() = delete;
};
