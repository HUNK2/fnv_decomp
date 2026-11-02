// include/havok/hkpCdBody.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPCDBODY_H
#define FNV_HAVOK_HKPCDBODY_H

#include "hkBase.h"
class hkpShape;
#pragma pack(push, 1)
class hkpCdBody
{
  public:
    hkpShape* m_pCollisionShape;  // +0x0
    hkUint32 m_uiCollisionShapeKey;          // +0x4
    void* m_pMotionState;         // +0x8
    hkpCdBody* m_parent;          // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCdBody[(sizeof(hkpCdBody) == 0x10) ? 1 : -1];
#endif
