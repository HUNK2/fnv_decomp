// Source layout: MiddleLowProcess. PC corrections are in generate_headers.py.
#ifndef FNV_MIDDLELOWPROCESS_H
#define FNV_MIDDLELOWPROCESS_H

#include "layout_support.h"
#include "LowProcess_decl_middlelowprocess.h"
#include "ActorValueModifierList.h"
#pragma pack(push, 4)
class MiddleLowProcess : public LowProcess
{
  public:
    int m_iValueB4;                       // +0xB4
    ActorValueModifierList m_kProcessModifierList;  // +0xB8
    int GetProcessInteger();
    void SetProcessInteger(int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MiddleLowProcess) == 0xC8);
FNV_STATIC_ASSERT(offsetof(MiddleLowProcess, m_iValueB4) == 0xB4);
FNV_STATIC_ASSERT(offsetof(MiddleLowProcess, m_kProcessModifierList) == 0xB8);
#endif
