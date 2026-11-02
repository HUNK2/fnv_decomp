
// src/havok/common/base/types/geometry/aabb/hkaabb.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/aabb/hkaabb.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkAabb.h"

struct FnvFinitePair
{
    float minimum;
    float maximum;
};
struct FnvBounds
{
    float minimum[4];
    float maximum[4];
    char* ValidateBounds(char* valid);
};
// Checks each of the first three axes for non-finite min/max or min greater than max, writing 1 to valid if all pass and 0 otherwise.
// @fnv 0x00da0b30
char* FnvBounds::ValidateBounds(char* pbValid)
{
    FnvFinitePair pair;
    for (int axis = 0; axis < 3; ++axis)
    {
        pair.minimum = minimum[axis];
        if ((*(unsigned int*)&pair.minimum & 0x7f800000) == 0x7f800000)
            goto invalid;
        pair.maximum = maximum[axis];
        if ((*(unsigned int*)&pair.maximum & 0x7f800000) == 0x7f800000 || minimum[axis] > maximum[axis])
            goto invalid;
    }
    *pbValid = 1;
    return pbValid;
invalid:
    *pbValid = 0;
    return pbValid;
}
