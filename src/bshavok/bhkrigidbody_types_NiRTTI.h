// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIRTTI_H
#define FNV_NIRTTI_H

#include "layout_support.h"
class NiRTTI;
#pragma pack(push, 4)
class NiRTTI
{
  public:
    const char* m_pcName;       // +0x0, 4 bytes
    const NiRTTI* m_pBaseRTTI;  // +0x4, 4 bytes
    // void __cdecl NiRTTI::*(const char*, const NiRTTI*)
    // const char* __cdecl NiRTTI::*()
    // const NiRTTI* __cdecl NiRTTI::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiRTTI) == 8);
FNV_STATIC_ASSERT(offsetof(NiRTTI, m_pcName) == 0);
FNV_STATIC_ASSERT(offsetof(NiRTTI, m_pBaseRTTI) == 4);
#endif
