#ifndef FNV_SCRIPTVARIABLE_H
#define FNV_SCRIPTVARIABLE_H

#include "layout_support.h"
#include "ScriptLocalVariable.h"
#pragma pack(push, 4)
class ScriptVariableInfo
{
  public:
    ScriptLocalVariable data;        // +0x0
    BSStringT<char> m_kName;  // +0x18
    ScriptVariableInfo();
    void Load(TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptVariableInfo) == 0x20);
FNV_STATIC_ASSERT(offsetof(ScriptVariableInfo, data) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptVariableInfo, m_kName) == 0x18);
#endif
