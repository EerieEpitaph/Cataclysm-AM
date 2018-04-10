#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>

#include "Util.h"
#include "Item.h"
#include "Container.h"

int main( int argc, char * argv[] )
{
    std::vector<uint16_t> top = std::vector<uint16_t>();
    std::vector<std::shared_ptr<Item>> kek = std::vector<std::shared_ptr<Item>>();

    Container pippo = Container("gn", "mioa", "top", 2, 2, 2, nullptr, 2, 2, 2, 2, 2, nullptr, top, 10, kek);
    ItemDatabase data;
    data.addItem(pippo);
    Container& tropp = static_cast<Container&>(data.fetchItem("gn", "mioa"));

    std::unordered_map<int, Item&> mappi;

    return 0;
}
