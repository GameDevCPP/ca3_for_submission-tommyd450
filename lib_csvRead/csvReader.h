#include <vector>
#include <string>
#include "fstream"
namespace CR
{

    class CsvReader
    {
    public:
        static std::vector<std::string> readFile (std::string file, std::string search);
    };

}