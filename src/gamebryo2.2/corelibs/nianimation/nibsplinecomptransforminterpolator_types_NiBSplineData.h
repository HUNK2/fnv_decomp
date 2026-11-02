// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBSPLINEDATA_H
#define FNV_NIBSPLINEDATA_H

#include "layout_support.h"
#include "NiObject.h"
class NiBSplineData;
class NiBSplineBasisData;
#pragma pack(push, 4)
class NiBSplineData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    float* m_pfControlPoints;                   // +0x8, 4 bytes
    short* m_psCompactControlPoints;            // +0xC, 4 bytes
    unsigned int m_uiControlPointCount;         // +0x10, 4 bytes
    unsigned int m_uiCompactControlPointCount;  // +0x14, 4 bytes
    // const NiRTTI* __cdecl NiBSplineData::*()
    // void __cdecl NiBSplineData::*(NiStream&)
    // void __cdecl NiBSplineData::*(NiStream&)
    // bool __cdecl NiBSplineData::*(NiStream&)
    // void __cdecl NiBSplineData::*(NiStream&)
    // bool __cdecl NiBSplineData::*(NiObject*)
    // NiObject* __cdecl NiBSplineData::*()
    // void __cdecl NiBSplineData::*(NiTPrimitiveArray<char *>*)
    // NiBSplineData
    // void __cdecl NiBSplineData::*()
    // unsigned int __cdecl NiBSplineData::*(const float*, unsigned int, unsigned int)
    // unsigned int __cdecl NiBSplineData::*(const float*, unsigned int, unsigned int, float&, float&)
    // const float* __cdecl NiBSplineData::*(unsigned int, unsigned int, unsigned int)
    // const short* __cdecl NiBSplineData::*(unsigned int, unsigned int, unsigned int)
    // void __cdecl NiBSplineData::*(float, float*, unsigned int, NiBSplineBasisData*, unsigned int)
    // void __cdecl NiBSplineData::*(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float)
    // NiBSplineData& __cdecl NiBSplineData::*(const NiBSplineData&)
    // void __cdecl NiBSplineData::*()
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineData) == 24);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_pfControlPoints) == 8);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_psCompactControlPoints) == 12);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiControlPointCount) == 16);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiCompactControlPointCount) == 20);
#endif
