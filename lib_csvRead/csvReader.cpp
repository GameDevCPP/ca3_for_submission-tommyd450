#include "csvReader.h"
namespace CR {
    std::vector <std::string> CsvReader::readFile(std::string file, std::string search) {
        std::fstream read;
        read.open("../bin/res/soundpath.csv");
        std::vector <std::string> result;
        bool found = false;
        std::string f1;
        std::string f2;
        std::string f3;
        while (std::getline(read, f1, ',') && !found) {
            std::getline(read, f2, ',');
            std::getline(read, f3, '\n');
            if (f1 == search) {
                found = true;
                result.push_back(f1);
                result.push_back(f2);
                result.push_back(f3);
            }
        }
        read.close();
        return result;
    }
}