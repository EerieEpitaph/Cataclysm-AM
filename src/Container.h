#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item.h"
#include <vector>

class Container : public Item
{
	private:
	    uint32_t space; //In milliliters
	    uint32_t maxSpace; //Largest item that fits inside (i'd like to avoid storing spears inside cargo pants..)
		std::vector<std::shared_ptr<Item>> contains;

	public:

};



#endif /* CONTAINER_H_ */
