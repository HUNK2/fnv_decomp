// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIQUATTRANSFORM_H
#define FNV_NIQUATTRANSFORM_H

#include "layout_support.h"
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3& operator=(const NiPoint3& src)
    {
        *(unsigned int*)&x = *(const unsigned int*)&src.x;
        *(unsigned int*)&y = *(const unsigned int*)&src.y;
        *(unsigned int*)&z = *(const unsigned int*)&src.z;
        return *this;
    }
};
class NiQuatTransform;
class NiQuaternion;
#pragma pack(push, 4)
class NiQuaternion
{
  public:
    float m_fVectorX;     // +0x0, 4 bytes
    float m_fVectorY;     // +0x4, 4 bytes
    float m_fVectorZ;     // +0x8, 4 bytes
    float m_fScalarPart;  // +0xC, 4 bytes
    NiQuaternion& operator=(const NiQuaternion& src)
    {
        *(unsigned int*)&m_fVectorX = *(const unsigned int*)&src.m_fVectorX;
        *(unsigned int*)&m_fVectorY = *(const unsigned int*)&src.m_fVectorY;
        *(unsigned int*)&m_fVectorZ = *(const unsigned int*)&src.m_fVectorZ;
        *(unsigned int*)&m_fScalarPart = *(const unsigned int*)&src.m_fScalarPart;
        return *this;
    }
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
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuaternion) == 16);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorX) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorY) == 4);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorZ) == 8);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fScalarPart) == 12);
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
#pragma pack(push, 4)
struct TransformWords
{
    unsigned int words[8];
};
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;   // +0x0, 12 bytes
    NiQuaternion m_kRotate;  // +0xC, 16 bytes
    float m_fScale;          // +0x1C, 4 bytes
    NiQuatTransform& operator=(const NiQuatTransform& rhs)
    {
        *(TransformWords*)this = *(const TransformWords*)&rhs;
        return *this;
    }
    NiQuatTransform()
    {
        m_kTranslate = DAT_011a8400;
        m_kRotate = DAT_011f3704;
        m_fScale = DAT_01096b8c;
    }
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
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuatTransform) == 32);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kTranslate) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kRotate) == 12);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_fScale) == 28);
#endif
