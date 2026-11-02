// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPLANE_H
#define FNV_NIPLANE_H

#include "layout_support.h"
#include "NiPoint3.h"
class NiPlane;
#pragma pack(push, 4)
class NiPlane
{
  public:
    bool operator==(const NiPlane&);
    NiPoint3 m_kPlaneNormal;  // +0x0, 12 bytes
    float m_fPlaneConstant;   // +0xC, 4 bytes
    // NiPlane
    // bool __cdecl NiPlane::*(const NiPlane&)
    // bool __cdecl NiPlane::*(const NiPlane&)
    // NiPlane __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(const NiPoint3&)
    // const NiPoint3& __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(float)
    // float __cdecl NiPlane::*()
    // float __cdecl NiPlane::*(const NiPoint3&)
    // int __cdecl NiPlane::*(const NiPoint3&)
    // void __cdecl NiPlane::*(NiStream&)
    // void __cdecl NiPlane::*(NiStream&)
    // char* __cdecl NiPlane::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPlane) == 16);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_kPlaneNormal) == 0);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_fPlaneConstant) == 12);
#endif
