// include/havok/hkpPhysicsData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPPHYSICSDATA_H
#define FNV_HAVOK_HKPPHYSICSDATA_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpPhysicsSystem;
class hkpWorldCinfo;
#pragma pack(push, 1)
class hkpPhysicsData : public hkReferencedObject
{
  public:
    hkpWorldCinfo* m_pWorldCinfo;                  // +0x8
    hkArray<hkpPhysicsSystem*> m_kPhysicsSystems;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPhysicsData[(sizeof(hkpPhysicsData) == 0x18) ? 1 : -1];
#endif
