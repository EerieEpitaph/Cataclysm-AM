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
    importFlags(jsons[3]);

    //std::string miao = "C:\\copromati\\test.cpp";
    //std::cout << extractDir(miao);

    return 0;
}
