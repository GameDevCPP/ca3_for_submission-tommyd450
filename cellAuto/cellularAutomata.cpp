#include "cellularAutomata.h"
#include <fstream>
#include <string>
#include <iostream>
// CellAuto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
int width = 50;
int height = 50;

bool wall = true;
bool tunnel = false;
vector<char> row(width, ' ');
vector<vector<char>> vect(height, row);


namespace CA
{
    int width = 50;
    int height = 50;

    bool wall = true;
    bool tunnel = false;
    vector<char> row(width, ' ');
    vector<vector<char>> vect(height, row);

    void CellularAutomataGen::noiseGeneration()
    {
        std::srand(std::time(nullptr));
        for (int i = 0; i < width - 1; i++)
        {

            for (int j = 0; j < height - 1; j++)
            {
                //cout << "here";
                if (rand() < 15000)
                {
                    vect[i][j] = 'w';
                }
                else
                {
                    vect[i][j] = ' ';
                }

            }

        }
    }

    void CellularAutomataGen::unNaturalSelection()
    {
        for (int i = 0; i < width - 1; i++)
        {

            for (int j = 0; j < height - 1; j++)
            {
                int numNeighbours = 0;

                if (vect[i][j] == 'w')
                {
                    // Three Cells above ie . NW, N, NE
                    if (i != 0 && j >0 && vect[i][j-1]==1)
                    {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && vect[i-1][j - 1] == 'w')
                    {
                        numNeighbours++;
                    }
                    if (i >0 && j > 0 && i<height && vect[i+1][j - 1] == 'w')
                    {
                        numNeighbours++;
                    }
                    // Cells to the left and right ie. West and East
                    if (i != 0 && j > 0 && vect[i-1][j] == 'w')
                    {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && vect[i+1][j ] == 'w')
                    {
                        numNeighbours++;
                    }
                    //Cells below ie SW, S , SE
                    if (i != 0 && j > 0 && j < width && vect[i][j + 1] == 'w')
                    {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && j < width &&  vect[i+1][j + 1] == 'w')
                    {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && j < width && vect[i-1][j + 1] == 'w')
                    {
                        numNeighbours++;
                    }
                    //cout << numNeighbours << endl;

                    if (vect[i][j]==1 && numNeighbours < 5 )
                    {
                        vect[i][j] = ' ';
                    }
                    if (vect[i][j] =='w' && numNeighbours == 2 || numNeighbours == 3)
                    {
                        vect[i][j] = 'w';
                    }
                    if (vect[i][j] == 'w' && numNeighbours > 3)
                    {
                        vect[i][j] = ' ';
                    }
                    if (vect[i][j] == ' ' && numNeighbours == 3)
                    {
                        vect[i][j] = 'w';
                    }
                }
            }

        }
        string current = "";
        for (int i = 0; i < width - 1; i++)
        {

            for (int j = 0; j < height - 1; j++)
            {
                if (vect[i][j] == 0)
                {
                    current += " ";
                }
                else
                {
                    current += vect[i][j];
                }

            }
            current+= "\n";
            cout << current << endl;
        }
        std::ofstream out("output.txt");
        out << current;
        out.close();
    }
    }

