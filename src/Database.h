#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "Item.h"
#include <unordered_map>

class Database
{
    private:
        std::vector<uint32_t> flags;
        std::unordered_map<uint32_t, Item&> items;

    public:
        Database(){};
        Database(std::unordered_map<uint32_t, Item&> dat) : items(dat){}

        inline std::vector<uint32_t> getFlags();
        inline std::unordered_map<uint32_t, Item&> getItems();

        void addItem(uint32_t hashd, Item& toAdd);
        void addItem(Item& toAdd);
        Item& fetchItem(uint32_t hashd);
};

#endif // DATABASE_H_INCLUDED
