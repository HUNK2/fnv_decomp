// include/havok/hkpAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPACTION_H
#define FNV_HAVOK_HKPACTION_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpAction : public hkReferencedObject
{
  public:
    void* m_pOwningWorld;              // +0x8
    void* m_pCurrentSimulationIsland;  // +0xC
    hkUlong m_ulUserData;              // +0x10
    hkStringPtr m_name;                // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAction[(sizeof(hkpAction) == 0x18) ? 1 : -1];
#endif
