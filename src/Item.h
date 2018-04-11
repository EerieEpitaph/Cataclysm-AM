#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>
#include <unordered_map>

#include "SDL.h"
#include "SDL_image.h"
#include "Util.h"

#define ITEM_ROOT "items/item_root.json"

class Item
{
	private:
		std::string group;
		std::string name;
		std::string descr;

		int32_t volume;
		int32_t weight;
		uint32_t charges;
		Item* containedIn;

		uint8_t bash;
		uint8_t cut;
		uint8_t pierce;
		uint32_t moves;
		uint8_t toHit;

		SDL_Surface* icon; //TODO
		std::vector<uint16_t> flags;

	public:
	    Item(){}
        Item(std::string group, std::string name, std::string descr, int32_t volume, int32_t weight, uint32_t charges, Item* containedIn,
             uint8_t bash, uint8_t cut, uint8_t pierce, uint32_t moves, uint8_t toHit, SDL_Surface* icon, std::vector<uint16_t> flags)
             : group(group), name(name), descr(descr), volume(volume), weight(weight), charges(charges), containedIn(containedIn), bash(bash),
             cut(cut), pierce(pierce), moves(moves), toHit(toHit), icon(icon), flags(flags) {};

        inline std::string getGroup(){return group;}
        inline std::string getName(){return name;}
        inline std::string getDescr(){return descr;}
        inline int32_t getVolume(){return volume;}
        inline int32_t getWeight(){return weight;}
        inline uint32_t getCharges(){return charges;}
        inline Item* getContainer(){return containedIn;}
        inline uint8_t getBash(){return bash;}
        inline uint8_t getCut(){return cut;}
        inline uint8_t getPierce(){return pierce;}
        inline uint32_t getMoves(){return moves;}
        inline uint8_t getToHit(){return toHit;}
        inline SDL_Surface* getSurface(){return icon;}
        inline std::vector<uint16_t> getFlags(){return flags;}
};


#endif /* ITEM_H_ */
