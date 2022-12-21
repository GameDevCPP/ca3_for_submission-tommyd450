//
// Created by Tommy on 20/12/2022.
//

#include <vector>
#include <functional>
#include <queue>
#include <string>
#include "SFML/System/Vector2.hpp"

struct graph
{
    sf::Vector2f coords;
    std::vector<sf::Vector2f> neighbours;
};



class astarAi{
public:

    void createGraph();
    void createRoute(sf::Vector2f start,sf::Vector2f target);
    graph findGraphNode(sf::Vector2f node);
    std::unordered_map<std::string ,graph> map;
    void createRoute(sf::Vector2f start, sf::Vector2f target, std::unordered_map<sf::Vector2f, sf::Vector2f> came_from,
                     std::unordered_map<sf::Vector2f, double> cost_so_far);

    void createRoute(sf::Vector2f start, sf::Vector2f target, std::vector<sf::Vector2f> visited);

    double heuristic(sf::Vector2f a, sf::Vector2f b);

    void
    createRoute(sf::Vector2f start, sf::Vector2f target, std::vector<sf::Vector2f> path,
                std::vector<sf::Vector2f> visited);
    explicit astarAi();

};

