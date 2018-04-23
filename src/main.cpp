#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>

#include "Util.h"
#include "Item.h"
#include "Container.h"
#include "JsonParser.h"

int main( int argc, char * argv[] )
{
    std::vector<json> jsons = importJSONs(JSON_ROOT);
    std::vector<uint32_t> flags = importFlags(jsons[0]);

    for(uint32_t x : flags)
        std::cout << x << ";";


    return 0;
}
