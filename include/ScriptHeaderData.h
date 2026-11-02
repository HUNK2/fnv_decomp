#ifndef FNV_SCRIPT_HEADER_H
#define FNV_SCRIPT_HEADER_H
#include "layout_support.h"
#pragma pack(push, 4)
class ScriptHeaderData
{
  public:
    unsigned int variableCount;    // +0x0
    unsigned int m_uiReferenceID;  // +0x4
    unsigned int dataSize;         // +0x8
    unsigned int m_uiDataOffset;   // +0xC
    bool m_bQuest;                 // +0x10
    bool m_bEffect;                // +0x11
    bool m_bCompiled;              // +0x12
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptHeaderData) == 0x14);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, variableCount) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, m_uiReferenceID) == 0x4);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, dataSize) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, m_uiDataOffset) == 0xC);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, m_bQuest) == 0x10);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, m_bEffect) == 0x11);
FNV_STATIC_ASSERT(offsetof(ScriptHeaderData, m_bCompiled) == 0x12);
#endif
