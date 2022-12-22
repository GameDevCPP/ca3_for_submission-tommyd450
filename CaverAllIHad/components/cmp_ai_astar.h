//
// Created by Tommy on 20/12/2022.
//

#include <vector>
#include <functional>
#include <queue>
#include <string>
#include "SFML/System/Vector2.hpp"
#include "AStar.h"
#include <chrono>
#include "cmath"


class Square : public AStarNode {
public:

    Square() {}

    ~Square() {}

    void setType(const bool type) {
        m_type = type;
    }

    bool getType() const {
        return m_type;
    }

    // A diagonal move has a sqrt(2) cost, 1 otherwise
    float localDistanceTo(AStarNode *node) const {
        if (node->getX() != m_x && node->getY() != m_y)
            return 1.41421356237f;
        else
            return 1.0f;
    }

    float distanceTo(AStarNode *node) const {
        int newX = m_x - node->getX(), newY = m_y - node->getY();
        return sqrtf(static_cast<float>(newX * newX + newY * newY));
    }

private:
    // To tell wether a pixel is "walkable" or not
    bool m_type;
};



class astarAi{
public:

    void createGraph();



    explicit astarAi();


    std::vector<Square *> createAndReturnRoute(sf::Vector2f start, sf::Vector2f target);
};

