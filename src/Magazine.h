#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "Item.h"

class Magazine : public Item
{
    private:
        uint32_t charges;

    public:
        Magazine();
        inline uint32_t getCharges(){return charges;}
};


#endif // MAGAZINE_H_INCLUDED
