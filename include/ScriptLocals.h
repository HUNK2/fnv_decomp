// Source layout: ScriptLocals. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPTLOCALS_H
#define FNV_SCRIPTLOCALS_H

#include "layout_support.h"
#pragma pack(push, 4)
class ScriptLocals
{
  public:
    Script* m_pOwnerScript;  // +0x0
    char m_cActionFlags;     // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;  // +0x8
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;        // +0xC
    ScriptDefinition* m_pExtendedLocals;               // +0x10
    void SetVariable(unsigned int index, double value);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptLocals) == 0x14);
FNV_STATIC_ASSERT(offsetof(ScriptLocals, m_pOwnerScript) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptLocals, m_cActionFlags) == 0x4);
FNV_STATIC_ASSERT(offsetof(ScriptLocals, m_pLocalVariableList) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptLocals, m_pVariableList) == 0xC);
FNV_STATIC_ASSERT(offsetof(ScriptLocals, m_pExtendedLocals) == 0x10);
#endif
