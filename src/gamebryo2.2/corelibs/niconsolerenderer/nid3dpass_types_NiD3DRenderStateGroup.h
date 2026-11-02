// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NID3DRENDERSTATEGROUP_H
#define FNV_NID3DRENDERSTATEGROUP_H

#include "layout_support.h"
class D3DRenderStateGroup;
class NiD3DRenderStateGroup__NiD3DRSEntry;
#pragma pack(push, 4)
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    bool m_bHasBeenApplied;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    unsigned int m_uiRenderStateEntryCount;                       // +0x4, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkRenderStateEntries;  // +0x8, 4 bytes
    unsigned int m_uiFreeEntryCount;                              // +0xC, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkFreeEntries;         // +0x10, 4 bytes
    // void __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*(unsigned int, unsigned int, bool)
    // void __cdecl D3DRenderStateGroup::*(unsigned int)
    // bool __cdecl D3DRenderStateGroup::*(unsigned int, unsigned int&, bool&)
    // unsigned int __cdecl D3DRenderStateGroup::*()
    // unsigned int __cdecl D3DRenderStateGroup::*()
    // D3DRenderStateGroup* __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*(D3DRenderStateGroup*)
    // unsigned int __cdecl D3DRenderStateGroup::*()
    // unsigned int __cdecl D3DRenderStateGroup::*()
    // unsigned int __cdecl D3DRenderStateGroup::*()
    // void __cdecl D3DRenderStateGroup::*()
    // unsigned int __cdecl D3DRenderStateGroup::*(unsigned int)
    // unsigned int __cdecl D3DRenderStateGroup::*(unsigned int)
    // void* __cdecl D3DRenderStateGroup::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(D3DRenderStateGroup) == 20);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_bHasBeenApplied) == 0);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiRenderStateEntryCount) == 4);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkRenderStateEntries) == 8);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiFreeEntryCount) == 12);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkFreeEntries) == 16);
#endif
