// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBLENDTRANSFORMINTERPOLATOR_PRIVATE_FNV_NIQUATTRANSFORM_H
#define FNV_NIBLENDTRANSFORMINTERPOLATOR_PRIVATE_FNV_NIQUATTRANSFORM_H

#include "niblendtransforminterpolator_layout_support.h"
#include "niblendtransforminterpolator_NiPoint3.h"
class NiQuatTransform;
class NiQuaternion;
class NiQuaternion
{
  public:
    void Normalize();
    float m_fVectorX;     // +0x0, 4 bytes
    float m_fVectorY;     // +0x4, 4 bytes
    float m_fVectorZ;     // +0x8, 4 bytes
    float m_fScalarPart;  // +0xC, 4 bytes
    // NiQuaternion
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*(float, float, float, float)
    // void __cdecl NiQuaternion::*(float&, float&, float&, float&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // operator-
    // operator*
    // operator*=
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // float __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float&, NiPoint3&)
    // void __cdecl NiQuaternion::*(float, const NiPoint3&)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float, float, float)
    // void __cdecl NiQuaternion::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiQuaternion::*(const char*)
    // void __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*(float, float, float)
    // float __cdecl NiQuaternion::*(float, float)
};
FNV_STATIC_ASSERT(sizeof(NiQuaternion) == 16);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorX) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorY) == 4);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorZ) == 8);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fScalarPart) == 12);
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;   // +0x0, 12 bytes
    NiQuaternion m_kRotate;  // +0xC, 16 bytes
    float m_fScale;          // +0x1C, 4 bytes
    // NiQuatTransform
    // const NiPoint3& __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(const NiPoint3&)
    // const NiQuaternion& __cdecl NiQuatTransform::*()
    // float __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(float)
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
};
FNV_STATIC_ASSERT(sizeof(NiQuatTransform) == 32);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kTranslate) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kRotate) == 12);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_fScale) == 28);
#endif
