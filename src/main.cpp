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
    std::vector<json> j = importJSONs(JSON_ROOT);
    std::cout << j[2];

    //std::string miao = "C:\\copromati\\test.cpp";
    //std::cout << extractDir(miao);

    return 0;
}
