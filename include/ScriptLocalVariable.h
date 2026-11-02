#ifndef FNV_SCRIPT_LOCAL_H
#define FNV_SCRIPT_LOCAL_H

#include "layout_support.h"
#pragma pack(push, 4)
class ScriptLocalVariable
{
  public:
    unsigned int uiID;  // +0x0
    unsigned int layoutPadding4;
    double fValue;     // +0x8
    bool m_bIsString;  // +0x10
    unsigned char layoutPadding11;
    unsigned short layoutPadding12;
    unsigned int layoutPadding14;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptLocalVariable) == 0x18);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, uiID) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, fValue) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, m_bIsString) == 0x10);
#endif
