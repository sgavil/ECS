#include "registry.hpp"

namespace ecg {

EntityID registry::_NEXT_ENTITY = 0;

EntityID registry::create_entity()
{
    auto id = _NEXT_ENTITY;
    entity_t entt;
    entt.id = id;
    entities.insert(entt);
    ++_NEXT_ENTITY;
    return id;
}

}
