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

    for (json::iterator it = j.begin(); it != j.end(); ++it)
    {
      std::cout << *it << "\n";
    }
    return 0;
}
