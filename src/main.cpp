#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <SDL.h>
#include <bitset>
#include <functional>

#include "Util.h"
#include "Item.h"
#include "Container.h"
#include "JsonParser.h"

int main( int argc, char * argv[] )
{

    std::vector<json> jsons = importJSONs(JSON_ROOT);
    std::unordered_map<std::string, uint32_t> flags = importFlags(jsons[0]);

    int i = 0;
    for(std::unordered_map<std::string, uint32_t>::iterator it = flags.begin() ; it != flags.end(); ++it)
    {
        std::cout << std::get<1>(*it) << ";";
        //std::cout << ++i;
    }



    return 0;
}
