// include/havok/hkpExtendedMeshShapeShapesSubpart.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPEXTENDEDMESHSHAPESHAPESSUBPART_H
#define FNV_HAVOK_HKPEXTENDEDMESHSHAPESHAPESSUBPART_H

#include "hkBase.h"
#include "hkpExtendedMeshShapeSubpart.h"
class hkpConvexShape;
#pragma pack(push, 1)
class hkpExtendedMeshShapeShapesSubpart : public hkpExtendedMeshShapeSubpart
{
  public:
    hkArray<hkpConvexShape*> m_kChildShapes;  // +0x14
    hkQuaternion m_rotation;                  // +0x20
    hkVector4 m_vTranslation;                 // +0x30
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpExtendedMeshShapeShapesSubpart[(sizeof(hkpExtendedMeshShapeShapesSubpart) == 0x40) ? 1 : -1];
#endif
