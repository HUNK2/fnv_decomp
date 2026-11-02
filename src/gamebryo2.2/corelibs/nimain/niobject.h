#ifndef FNV_NIOBJECT_UNIT_H
#define FNV_NIOBJECT_UNIT_H

#include "niobject_declarations.h"
#include "niobject_packet_decls.h"

// @fnv 0x0045a120
unsigned int BSFaceGenMorphData::DynamicCast()
{
    return array_1ec.GetSize();
}

// @fnv 0x00653290
NiObject* NiObject::DynamicCast(const NiRTTI* rtti)
{
    return IsKindOfType(rtti) ? this : 0;
}

#endif
