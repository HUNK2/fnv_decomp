// include/havok/hkpShapeInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPSHAPEINFO_H
#define FNV_HAVOK_HKPSHAPEINFO_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpShape;
#pragma pack(push, 1)
class hkpShapeInfo : public hkReferencedObject
{
  public:
    hkpShape* m_pCollisionShape;  // +0x8
    hkBool m_bIsConvex;           // +0xC
    hkBool m_bIsConvexPiece;      // +0xD
    char padE[0x2];
    hkArray<hkStringPtr> m_kShapeNames;       // +0x10
    hkArray<hkTransform> m_kShapeTransforms;  // +0x1C
    char pad28[0x8];
    hkTransform m_kMotionTransform;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpShapeInfo[(sizeof(hkpShapeInfo) == 0x70) ? 1 : -1];
#endif
