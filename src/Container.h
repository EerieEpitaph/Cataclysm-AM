#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item.h"
#include <vector>

class Container : public Item
{
	public:
	    uint32_t space; //In milliliters
		std::vector<std::shared_ptr<Item>> contains;

	public:

};



#endif /* CONTAINER_H_ */
