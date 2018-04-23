#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <string>
#include <functional>

#include "Item.h"
#include <unordered_map>

class Database
{
    private:
        static std::unordered_map<std::string, uint32_t> flags;
        static std::unordered_map<std::string, Item&> items;

    public:
        static inline std::unordered_map<std::string, uint32_t>& getFlags(){return flags;}
        static inline std::unordered_map<std::string, Item&>& getItems(){return items;}

        template <class K, class V>
        static void addInto(std::unordered_map<K, V>& table, K hashd, V toAdd)
        {table.insert( {hashd, toAdd} );}

        template <class K, class V>
        static V& fetchFrom(std::unordered_map<K,V> table, K hashd)
        {return table.at(hashd);}
};

#endif // DATABASE_H_INCLUDED
