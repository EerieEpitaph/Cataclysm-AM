#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>
#include <bitset>

#include "SDL.h"
#include "SDL_image.h"
#include "Util.h"

#define MAX_BITSET 255

class Item
{
	private:
		std::string categ;
		std::string ident;
		std::string name;
		std::string plural;
		std::string descr;

		uint8_t condition;
		int32_t volume;
		int32_t weight;
        std::unique_ptr<Item> mag;
		Item* containedIn;

		uint8_t bash;
		uint8_t cut;
		uint8_t pierce;
		uint32_t moves;
		int8_t toHit;

		SDL_Surface* icon; //TODO
        std::bitset<MAX_BITSET> flags;

	public:
	    Item(){}
	    Item(std::string categ, std::string ident, std::string name, std::string plural, std::string descr, uint8_t condition,
             int32_t volume, int32_t weight, std::unique_ptr<Item> mag, Item* containedIn, uint8_t bash, uint8_t cut, uint8_t pierce,
             uint32_t moves, int8_t toHit, SDL_Surface* icon, std::bitset<MAX_BITSET> flags);
        inline std::string getName(){return name;}
};




#endif /* ITEM_H_ */
