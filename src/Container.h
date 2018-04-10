#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item.h"
#include <vector>

class Container : public Item
{
	private:
	    uint32_t space;
		std::vector<std::shared_ptr<Item>> contains;

	public:
	    Container(std::string group, std::string name, std::string descr, int32_t volume, int32_t weight,
                uint32_t charges, Item* containedIn, uint8_t bash, uint8_t cut, uint8_t pierce, uint32_t moves,
                uint8_t toHit, SDL_Surface* icon, std::vector<uint16_t> flags, uint32_t space, std::vector<std::shared_ptr<Item>> contains) :
                Item(group, name, descr, volume, weight, charges, containedIn, bash, cut, pierce, moves, toHit, icon, flags),
                space(space), contains(contains){}

		inline std::vector<std::shared_ptr<Item>> getItems() {return contains;};

		void addItem(Item* toAdd, uint32_t qnt);
		void removeItem(Item* toRemove, uint32_t qnt);
};



#endif /* CONTAINER_H_ */
