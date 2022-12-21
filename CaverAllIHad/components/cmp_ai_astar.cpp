//
// Created by Tommy on 20/12/2022.
//
#include "cmp_ai_astar.h"
#include "LevelSystem.h"
#include "unordered_map"
#include <queue>



double astarAi::heuristic(sf::Vector2f a, sf::Vector2f b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

    std::vector<graph> spots;


void astarAi::createGraph() {
    auto tiles = ls::findTiles(ls::EMPTY);
    for (auto i :tiles)
    {

        //cout<<ls::getTilePosition(Vector2ul((pos-ls::getOffset()) / (ls::getTileSize())))<<endl;
        graph gr = graph();
        //gr.coords =  sf::Vector2f(i.x,i.y);
        sf::Vector2ul pos = sf::Vector2ul (i.x,i.y);
        gr.coords=ls::getTilePosition(pos);
        std::cout<<gr.coords<<"new coords"<<std::endl;
        std::string xKey = std::to_string(gr.coords.x);
        std::string yKey = std::to_string(gr.coords.y);
        std::string key = xKey+":"+yKey;


        for (auto j : tiles)
        {
            sf::Vector2ul pos = sf::Vector2ul (j.x,j.y);
            sf::Vector2f neighb = ls::getTilePosition(pos);
            if (i.x +1 == j.x && i.y==j.y)
            {
                gr.neighbours.push_back(neighb);
            }
            if (i.x -1 == j.x && i.y==j.y)
            {
                gr.neighbours.push_back(neighb);
            }
            if (i.x  == j.x && i.y+1==j.y)
            {
                gr.neighbours.push_back(neighb);
            }
            if (i.x  == j.x && i.y-1==j.y)
            {
                gr.neighbours.push_back(neighb);
            }
            if(gr.neighbours.size()==4)
            {
                std::cout <<"1st Neighb"<<gr.neighbours[1]<<std::endl;
                break;
            }
        }
        std::cout <<gr.neighbours.size()<<std::endl;
        map[key] = gr;
        std::cout<<map[key].coords<<"Key" <<key <<std::endl;
    }
    //std::cout <<spots.size()<<std::endl;
    //std::cout<<astarAi::heuristic(sf::Vector2f(0,0),sf::Vector2f(0,1))<<std::endl;
    //std::cout<<astarAi::heuristic(sf::Vector2f(0,0),sf::Vector2f(1,1))<<std::endl;
    //std::cout<<astarAi::heuristic(sf::Vector2f(0,0),sf::Vector2f(2,1))<<std::endl;

}

void astarAi::createRoute(sf::Vector2f start,sf::Vector2f target) {
    if(start != target)
    {
        std::vector<sf::Vector2f> frontierG;
        std::vector<double> frontierC;
        frontierG.push_back(start);
        sf::Vector2f current = start;
        sf::Vector2f low;
        double lowest = 300000;
        std::cout<<findGraphNode(current).coords<<"CURRENR"<<std::endl;
        {
        for (auto n: findGraphNode(current).neighbours) {
            std::cout<<"neigh"<<n<<std::endl;
            double currentVal = heuristic(n,target);
            if(currentVal<lowest)
            {
                std::cout<<"low";
                lowest = currentVal;
                low = n;
            }

        }
        createRoute(low,target);
    }

}

}

graph astarAi::findGraphNode(sf::Vector2f node)
{
    graph gr;
    sf::Vector2ul pos = sf::Vector2ul (node.x-40,node.y);
    sf::Vector2f b =ls::getTilePosition(pos);
    std::string xKey = std::to_string(b.x);
    std::string yKey = std::to_string(b.y);
    std::string key = xKey+":"+yKey;
   // std::string key2 = "1120.000000:680.000000";
    gr = map[key];
    //std::cout<<map[key2].coords<<"Found"<<std::endl;
    return gr;
}

astarAi::astarAi() {}