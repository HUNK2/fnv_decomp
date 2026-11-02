// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPARTICLEINFO_H
#define FNV_NIPARTICLEINFO_H

#include "layout_support.h"
#include "NiPoint3.h"
class Point3ParameterData;
class NiStream;
#pragma pack(push, 4)
class Point3ParameterData
{
  public:
    NiPoint3 m_kValue;               // +0x0, 12 bytes
    float m_fXValue;                 // +0xC, 4 bytes
    float m_fYValue;                 // +0x10, 4 bytes
    float m_fZValue;                 // +0x14, 4 bytes
    unsigned short m_usFirstValue;   // +0x18, 2 bytes
    unsigned short m_usSecondValue;  // +0x1A, 2 bytes
    // void __cdecl Point3ParameterData::*()
    // void __cdecl Point3ParameterData::*(NiStream&)
    // void __cdecl Point3ParameterData::*(NiStream&)
    // bool __cdecl Point3ParameterData::*(const Point3ParameterData&)
    Point3ParameterData();
    void LoadBinary(NiStream&);
    void Initialize();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Point3ParameterData) == 28);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_kValue) == 0);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_fXValue) == 12);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_fYValue) == 16);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_fZValue) == 20);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_usFirstValue) == 24);
FNV_STATIC_ASSERT(offsetof(Point3ParameterData, m_usSecondValue) == 26);
#endif
