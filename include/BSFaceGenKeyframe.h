// Source layout: BSFaceGenKeyframe. PC corrections are in generate_headers.py.
#ifndef FNV_BSFACEGENKEYFRAME_H
#define FNV_BSFACEGENKEYFRAME_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSFaceGenKeyframe
{
  public:
    void** m_ppVirtualMethodTable;              // +0x0
    BS_FACEGEN_MORPH_TYPE eType;  // +0x4
    float fTime;                  // +0x8
    float GetTime();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSFaceGenKeyframe) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSFaceGenKeyframe, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSFaceGenKeyframe, eType) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSFaceGenKeyframe, fTime) == 0x8);
#endif
