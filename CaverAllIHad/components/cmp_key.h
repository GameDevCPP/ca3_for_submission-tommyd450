#include "ecm.h"
#include "Box2D/Common/b2Math.h"
#include "../components/cmp_KeyTracker.h"

class KeyItemComponent : public Component{
protected:
    std::shared_ptr<Entity> _player;
    std::shared_ptr<KeyTracker> _kt;
public:
    void update(double dt) override;
    void render() override {}
    explicit KeyItemComponent(Entity* p,std::shared_ptr<Entity> player,std::shared_ptr<KeyTracker> kt);

    KeyItemComponent() = delete;
};