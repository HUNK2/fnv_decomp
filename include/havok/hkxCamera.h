// include/havok/hkxCamera.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKXCAMERA_H
#define FNV_HAVOK_HKXCAMERA_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxCamera : public hkReferencedObject
{
  public:
    char pad8[0x8];
    hkVector4 m_vFrom;         // +0x10
    hkVector4 m_vFocus;        // +0x20
    hkVector4 m_vStart;        // +0x30
    hkReal m_fFieldOfView;     // +0x40
    hkReal m_fNearPlane;       // +0x44
    hkReal m_fFarPlane;        // +0x48
    hkBool m_bStencilEnabled;  // +0x4C
    char pad4D[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxCamera[(sizeof(hkxCamera) == 0x50) ? 1 : -1];
#endif
