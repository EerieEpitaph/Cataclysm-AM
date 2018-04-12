#ifndef ITEMDATABASE_H_INCLUDED
#define ITEMDATABASE_H_INCLUDED

#include <unordered_map>
#include "ItemDatabase.h"

class ItemDatabase
{
    private:
        std::unordered_map<uint32_t, Item&> database;

    public:
        ItemDatabase(){};
        ItemDatabase(std::unordered_map<uint32_t, Item&> dat) : database(dat){}
        inline std::unordered_map<uint32_t, Item&> getDatabase(){return database;}

        void addItem(Item& toAdd){database.insert( std::make_pair( FNVHash(toAdd.getName()), toAdd     ));}
        Item& fetch(uint32_t hashd);
};

#endif // ITEMDATABASE_H_INCLUDED
