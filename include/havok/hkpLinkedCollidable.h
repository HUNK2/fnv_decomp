// include/havok/hkpLinkedCollidable.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x5C.
#ifndef FNV_HAVOK_HKPLINKEDCOLLIDABLE_H
#define FNV_HAVOK_HKPLINKEDCOLLIDABLE_H

#include "hkBase.h"
#include "hkpCollidable.h"
#pragma pack(push, 1)
class hkpLinkedCollidable : public hkpCollidable
{
  public:
    hkArray<char> m_kCollisionEntries;  // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLinkedCollidable[(sizeof(hkpLinkedCollidable) == 0x5C) ? 1 : -1];
#endif
