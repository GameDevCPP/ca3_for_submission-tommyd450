#include "cellularAutomata.h"
#include <fstream>
#include <string>
#include <iostream>
#include<tuple>
// CellAuto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;




namespace CA {
    int width = 100;
    int height = 100;


    vector<char> row(width, ' ');
    vector <vector<char>> vect(height, row);

    void CellularAutomataGen::noiseGeneration() {
        std::srand(std::time(nullptr));
        for (int i = 0; i < width - 1; i++) {

            for (int j = 0; j < height - 1; j++) {
                //cout << "here";
                if ((float) rand()/RAND_MAX < 0.4) {
                    vect[i][j] = 'w';
                } else {
                    vect[i][j] = ' ';
                }

            }

        }
    }

    void CellularAutomataGen::fill() {
        for (int i = 0; i < width - 1; i++) {

            for (int j = 0; j < height - 1; j++) {
                int numNeighbours = 0;


                    // Three Cells above ie . NW, N, NE
                    if (i != 0 && j > 0 && vect[i][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && vect[i - 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && i < height && vect[i + 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    // Cells to the left and right ie. West and East
                    if (i != 0 && j > 0 && vect[i - 1][j] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && vect[i + 1][j] == 'w') {
                        numNeighbours++;
                    }
                    //Cells below ie SW, S , SE
                    if (i != 0 && j > 0 && j < width && vect[i][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && j < width && vect[i + 1][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && j < width && vect[i - 1][j + 1] == 'w') {
                        numNeighbours++;
                    }


                if (vect[i][j] == 'w' && numNeighbours < 3) {
                    vect[i][j] = ' ';
                }
                else if (vect[i][j] == ' ' && numNeighbours >4) {
                    vect[i][j] = 'w';
                }

            }
        }
    }

        void CellularAutomataGen::unNaturalSelection() {
            for (int i = 0; i < width - 1; i++) {

                for (int j = 0; j < height - 1; j++) {
                    int numNeighbours = 0;

                        // Three Cells above ie . NW, N, NE
                        if (i != 0 && j > 0 && vect[i][j - 1] == 'w') {
                            numNeighbours++;
                        }
                        if (i > 0 && j > 0 && vect[i - 1][j - 1] == 'w') {
                            numNeighbours++;
                        }
                        if (i > 0 && j > 0 && i < height && vect[i + 1][j - 1] == 'w') {
                            numNeighbours++;
                        }
                        // Cells to the left and right ie. West and East
                        if (i != 0 && j > 0 && vect[i - 1][j] == 'w') {
                            numNeighbours++;
                        }
                        if (i != 0 && j > 0 && i < height && vect[i + 1][j] == 'w') {
                            numNeighbours++;
                        }
                        //Cells below ie SW, S , SE
                        if (i != 0 && j > 0 && j < width && vect[i][j + 1] == 'w') {
                            numNeighbours++;
                        }
                        if (i != 0 && j > 0 && i < height && j < width && vect[i + 1][j + 1] == 'w') {
                            numNeighbours++;
                        }
                        if (i != 0 && j > 0 && j < width && vect[i - 1][j + 1] == 'w') {
                            numNeighbours++;
                        }
                        //cout << numNeighbours << endl;

                    if (vect[i][j] == 'w' && numNeighbours < 3) {
                        vect[i][j] = ' ';
                    }
                    else if (vect[i][j] == ' ' && numNeighbours >4) {
                        vect[i][j] = 'w';
                    }

                }

            }
            for(int i = 0; i < 2; i++){
                fill();
            }


            determineSpawns();

            string current = "";
            for (int i = 0; i < width - 1; i++) {

                for (int j = 0; j < height - 1; j++) {
                    if (vect[i][j] == 0) {
                        current += " ";
                    } else {
                        current += vect[i][j];
                    }

                }
                current += "\n";
                cout << current << endl;
            }
            std::ofstream out("../bin/res/levels/output.txt");
            out << current;
            out.close();
        }



    void CellularAutomataGen::determineSpawns() {
        bool spawnFound = false;
        bool exitPlaced = false;

        for (int i = 0; i < width - 1; i++) {

            for (int j = 0; j < height - 1; j++) {
                int numNeighbours = 0;
                if (vect[i][j] == ' ') {

                    // Three Cells above ie . NW, N, NE
                    if (i != 0 && j > 0 && vect[i][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && vect[i - 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && i < height && vect[i + 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    // Cells to the left and right ie. West and East
                    if (i != 0 && j > 0 && vect[i - 1][j] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && vect[i + 1][j] == 'w') {
                        numNeighbours++;
                    }
                    //Cells below ie SW, S , SE
                    if (i != 0 && j > 0 && j < width && vect[i][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && j < width && vect[i + 1][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && j < width && vect[i - 1][j + 1] == 'w') {
                        numNeighbours++;
                    }
                }

                if (numNeighbours >=4)
                {

                    vect[i][j] = 'k';
                }
                if (numNeighbours ==5 && exitPlaced == false)
                {
                    exitPlaced = true;
                    vect[i][j] = 'e';
                }
            }
        }
        for (int i = 0; i < width - 1; i++) {

            for (int j = 0; j < height - 1; j++) {
                int numNeighbours = 0;
                if (vect[i][j] == ' '&&spawnFound== false) {

                    // Three Cells above ie . NW, N, NE
                    if (i != 0 && j > 0 && vect[i][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && vect[i - 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i > 0 && j > 0 && i < height && vect[i + 1][j - 1] == 'w') {
                        numNeighbours++;
                    }
                    // Cells to the left and right ie. West and East
                    if (i != 0 && j > 0 && vect[i - 1][j] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && vect[i + 1][j] == 'w') {
                        numNeighbours++;
                    }
                    //Cells below ie SW, S , SE
                    if (i != 0 && j > 0 && j < width && vect[i][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && i < height && j < width && vect[i + 1][j + 1] == 'w') {
                        numNeighbours++;
                    }
                    if (i != 0 && j > 0 && j < width && vect[i - 1][j + 1] == 'w') {
                        numNeighbours++;
                    }
                }

                if (numNeighbours ==3)
                {
                    spawnFound = true;
                    vect[i][j] = 's';
                    break;
                }
            }
        }
    }

}