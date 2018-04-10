#include "../nlohmann/json.hpp"
#include "Item.h"
#include "Util.h"

Item& ItemDatabase::fetchItem(std::string itemGroup, std::string itemName)
{
    uint32_t hashGroup = FNVHash(itemGroup);
    uint32_t hashName = FNVHash(itemName);
    //std::cout << hashGroup << ";" << hashName << "\n";

    std::unordered_map<uint32_t, Item&> test = database[hashGroup];
    Item& tre = static_cast<Item&>(test.at(hashName));
    return tre;
}
void ItemDatabase::addItem(Item& item)
{
    uint32_t hashGroup = FNVHash(item.getGroup());
    uint32_t hashName = FNVHash(item.getName());
    //std::cout << hashGroup << ";" << hashName << "\n";

    std::unordered_map<uint32_t, Item&> test = database[hashGroup];
    test.insert({hashName, item});
    database[hashGroup] = test;
}
void ItemDatabase::importEntries(std::string path)
{

}
