#pragma once


#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>


namespace CA
{

    class CellularAutomataGen
        {
        public:


            static void noiseGeneration();
            static void unNaturalSelection();
            static void fill();
            static void determineSpawns();
        };

}