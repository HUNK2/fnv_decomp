// include/havok/hkpWorldObject.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8C.
#ifndef FNV_HAVOK_HKPWORLDOBJECT_H
#define FNV_HAVOK_HKPWORLDOBJECT_H

#include "hkBase.h"
#include "hkMultiThreadCheck.h"
#include "hkReferencedObject.h"
#include "hkpLinkedCollidable.h"
class hkpProperty;
#pragma pack(push, 1)
class hkpWorldObject : public hkReferencedObject
{
  public:
    enum MtChecks
    {
        MULTI_THREADING_CHECKS_ENABLE = 0,
        MULTI_THREADING_CHECKS_IGNORE = 1
    };
    enum BroadPhaseType
    {
        BROAD_PHASE_INVALID = 0,
        BROAD_PHASE_ENTITY = 1,
        BROAD_PHASE_PHANTOM = 2,
        BROAD_PHASE_BORDER = 3,
        BROAD_PHASE_MAX_ID = 4
    };
    void* m_pOwningWorld;                    // +0x8
    hkUlong m_ulUserData;                    // +0xC
    hkpLinkedCollidable m_kCollidable;       // +0x10
    hkMultiThreadCheck m_kMultiThreadCheck;  // +0x6C
    hkStringPtr m_name;                      // +0x74
    hkArray<hkpProperty> m_kProperties;      // +0x78
    void* m_kNextStreamField;                // +0x84
    void* m_pWorldObjectOwner;               // +0x88
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWorldObject[(sizeof(hkpWorldObject) == 0x8C) ? 1 : -1];
#endif
