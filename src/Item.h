#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>
#include <unordered_map>
#include <bitset>

#include "SDL.h"
#include "SDL_image.h"
#include "Util.h"
#include "Magazine.h"

class Item
{
	private:
		std::string categ;
		std::string ident;
		std::string name;
		std::string descr;

		int32_t volume;
		int32_t weight;
        std::unique_ptr<Magazine> mag;
		Item* containedIn;

		uint8_t bash;
		uint8_t cut;
		uint8_t pierce;
		uint32_t moves;
		int8_t toHit;

		SDL_Surface* icon; //TODO
        std::bitset<255> flags;

	public:
        inline std::string getName(){return name;}
};

class Database
{
    private:
        std::unordered_map<uint32_t, Item&> database;

    public:
        Database(){};
        Database(std::unordered_map<uint32_t, Item&> dat) : database(dat){}
        Database(std::string rootPath);
        inline std::unordered_map<uint32_t, Item&> getDatabase(){return database;}

        void addItem(uint32_t hashd, Item& toAdd){database.insert( {hashd, toAdd} );}
        void addItem(Item& toAdd){database.insert( {FNVHash(toAdd.getName()), toAdd} );}
        Item& fetchItem(uint32_t hashd){return database.at(hashd);}
};


#endif /* ITEM_H_ */
