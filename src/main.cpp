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
    json j = deserializeFile("test.json");

    std::cout << j;
    return 0;
}
