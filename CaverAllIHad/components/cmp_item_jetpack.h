
#include "cmp_item.h"
#include "cmp_physics.h"
class ItemJetpackComponent : public PhysicsComponent {
protected:

    float time;
    b2Vec2 _size;
    sf::Vector2f _maxVelocity;
    bool _grounded;
    float _groundspeed;

    bool isGrounded() const;

public:
    void update(double dt) override;

    explicit ItemJetpackComponent(Entity* p,const sf::Vector2f& size);

    ItemJetpackComponent() = delete;
};
