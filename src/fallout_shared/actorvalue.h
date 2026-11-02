#include "actorvalue_vector.h"

// @fnv 0x0050ec30
ActorValueShortVector* ActorValueShortVector::Subtract(ActorValueShortVector* result,
                                                       const ActorValueShortVector& other)
{
    result->FUN_0050e960(x - other.x, y - other.y, z - other.z);
    return result;
}
