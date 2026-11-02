// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIUPDATEDATA_H
#define FNV_NIUPDATEDATA_H

#include "layout_support.h"
class NiUpdateData;
#pragma pack(push, 4)
class NiUpdateData
{
  public:
    float fTime;            // +0x0, 4 bytes
    bool m_bUpdateEnabled;  // +0x4, 1 bytes
    bool m_bRender;         // +0x5, 1 bytes
    bool m_bInterpolate;    // +0x6, 1 bytes
    bool m_bTimeToDie;      // +0x7, 1 bytes
    bool m_bVisible;        // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    // void __cdecl NiUpdateData::*(float, bool, bool)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, fTime) == 0);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, m_bUpdateEnabled) == 4);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, m_bRender) == 5);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, m_bInterpolate) == 6);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, m_bTimeToDie) == 7);
FNV_STATIC_ASSERT(offsetof(NiUpdateData, m_bVisible) == 8);
#endif
