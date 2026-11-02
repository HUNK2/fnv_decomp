// include/havok/hkpMouseSpringAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPMOUSESPRINGACTION_H
#define FNV_HAVOK_HKPMOUSESPRINGACTION_H

#include "hkBase.h"
#include "hkpUnaryAction.h"
#pragma pack(push, 1)
class hkpMouseSpringAction : public hkpUnaryAction
{
  public:
    char pad1C[0x4];
    hkVector4 m_kMousePositionInWorld;  // +0x20
    hkVector4 m_kGrabPointInBodySpace;  // +0x30
    hkReal m_fSpringDamping;            // +0x40
    hkReal m_fSpringElasticity;         // +0x44
    hkReal m_fMaxRelativeForce;         // +0x48
    hkReal m_fTau;                      // +0x4C
    hkUint32 m_uiCollisionShapeKey;                // +0x50
    hkArray<char> m_kAppliedCallbacks;  // +0x54
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMouseSpringAction[(sizeof(hkpMouseSpringAction) == 0x60) ? 1 : -1];
#endif
