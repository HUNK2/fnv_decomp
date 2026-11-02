// include/havok/hkSweptTransform.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKSWEPTTRANSFORM_H
#define FNV_HAVOK_HKSWEPTTRANSFORM_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkSweptTransform
{
  public:
    hkVector4 m_vCenterOfMass0;      // +0x0
    hkVector4 m_vCenterOfMass1;      // +0x10
    hkQuaternion m_qRotation0;       // +0x20
    hkQuaternion m_qRotation1;       // +0x30
    hkVector4 m_vCenterOfMassLocal;  // +0x40
};
#pragma pack(pop)
typedef char fnv_hk_size_hkSweptTransform[(sizeof(hkSweptTransform) == 0x50) ? 1 : -1];
#endif
