#include "ecm.h"

class KeyTracker : public Component {
public:
    void update(double dt) override;
    void render() override {}
    int keysCollected;
    explicit KeyTracker(Entity* p);
    ~KeyTracker() override = default;

};
