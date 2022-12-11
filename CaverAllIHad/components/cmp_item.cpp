#include "cmp_item.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void ItemComponent::update(double dt) {}

ItemComponent::ItemComponent(Entity *p) : Component(p){

}


ItemComponent::~ItemComponent() {

}