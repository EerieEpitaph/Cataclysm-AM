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
#include "Magazine.h"

class Item
{
	public:
		std::string group;
		std::string ident;
		std::string name;
		std::string descr;

		int32_t volume;
		int32_t weight;
        Magazine& mag;
		Item& containedIn;

		uint8_t bash;
		uint8_t cut;
		uint8_t pierce;
		uint32_t moves;
		uint8_t toHit;

		SDL_Surface* icon; //TODO
		std::vector<uint16_t> flags;

	public:
        inline std::string getName(){return name;}
};


#endif /* ITEM_H_ */
