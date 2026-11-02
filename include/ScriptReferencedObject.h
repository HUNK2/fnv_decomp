#ifndef FNV_SCRIPT_REFERENCED_OBJECT_H
#define FNV_SCRIPT_REFERENCED_OBJECT_H

#include "layout_support.h"
#pragma pack(push, 4)
class ScriptReferencedObject
{
  public:
    BSStringT<char> m_kFormName;  // +0x0
    TESForm* pForm;               // +0x8
    unsigned int m_uiFormID;      // +0xC
    ScriptReferencedObject();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptReferencedObject) == 0x10);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, m_kFormName) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, pForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, m_uiFormID) == 0xC);
#endif
