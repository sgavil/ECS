#pragma once
#include <stdint.h>
#include "sparse_set.hpp"

namespace ecg {

class registry
{
    using EntityContainer = sparse_set<entity_t>;
    static EntityID _NEXT_ENTITY;

public:
    registry() {}
    EntityID create_entity();

private:
    EntityContainer entities{};
};


}
