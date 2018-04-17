#include "Database.h"

inline std::unordered_map<uint32_t, Item&> Database::getItems()
{
    return items;
}
void Database::addItem(uint32_t hashd, Item& toAdd)
{
    items.insert( {hashd, toAdd} );
}
void Database::addItem(Item& toAdd)
{
    items.insert( { FNVHash(toAdd.getName()), toAdd } );
}
Item& Database::fetchItem(uint32_t hashd)
{
    return items.at(hashd);
}
