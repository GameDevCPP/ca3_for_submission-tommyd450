//
// Created by Tommy on 20/12/2022.
//
#include "cmp_ai_astar.h"
#include "LevelSystem.h"
#include "unordered_map"
#include <queue>
#include "PathFinder.h"





PathFinder<Square> p;
Square **squares;

void astarAi::createGraph() {
    auto tiles = ls::findTiles(ls::EMPTY);

        //PathFinder<Square> p;
        std::vector<Square*> path;
        int width = ls::getWidth();
        int height = ls::getHeight();


        squares = new Square* [width];
        for(unsigned short int x = 0; x < width; ++x)
        {
            squares[x] = new Square[height];
            for(unsigned short int y = 0; y < height; ++y)
            {
                sf::Vector2f b = sf::Vector2f (x,y);
                sf::Vector2f c =  ls::getTilePosition(sf::Vector2ul(b-ls::getOffset() / (ls::getTileSize())));
                squares[x][y].setPosition(c.x, c.y);
                squares[x][y].setType(ls::getTile(sf::Vector2ul(b-ls::getOffset() / (ls::getTileSize()))) == ls::TILES::EMPTY ? true : false);
            }
        }

        int newX, newY;
        Square *aChild;
        for(int x = 0; x < width; ++x){
            for(int y = 0; y < height; ++y) // traverse all squares
            {
                for(int i = -1; i < 2; ++i)
                {
                    newX = squares[x][y].getX() /ls::getWidth()+ i;
                    for(int j = -1; j < 2; ++j) // for all squares in this 3*3 square
                    {
                        newY = squares[x][y].getY() /ls::getWidth()+ j;
                        if( newX > -1 && newX < width && newY > -1 && newY < height ) // be sure not to go outside the limits
                        {
                            sf::Vector2f b = sf::Vector2f (x,y);

                            sf::Vector2f c =  ls::getTilePosition(sf::Vector2ul(b-ls::getOffset() / (ls::getTileSize())));
                            //std::cout<<ls::getTilePosition(sf::Vector2ul(b-ls::getOffset() / (ls::getTileSize())))<<std::endl;
                            aChild = &(squares[newX][newY]);
                            if( aChild->getType() && (newX != x || newY != y) ) // only take free squares and not the one we are examining
                                squares[x][y].addChild(aChild, squares[x][y].localDistanceTo(aChild));
                        }
                    }
                }
            }
        }
    p.setStart(squares[0][0]);
    p.setGoal(squares[10][0]);
    bool r = p.findPath<AStar>(path);
    std::cout<<r<<std::endl;


}

std::vector<Square*> astarAi::createAndReturnRoute(sf::Vector2f start,sf::Vector2f target)
{
    std::vector<Square*> path;

    p.setStart(squares[(int)start.x/40][((int)start.y/40)+1]);
    p.setGoal(squares[(int)target.x/40][((int)target.y/40)+1]);
    bool r = p.findPath<AStar>(path);
    std::cout<<r<<" In yolk"<<std::endl;
    return path;
}



astarAi::astarAi() {}