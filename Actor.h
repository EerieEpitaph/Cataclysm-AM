#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "libs/Tree.h"
#include "Entity.h"

class Actor : public Entity
{
    private:
        Tree<Part>
};

#endif // ACTOR_H_INCLUDED
