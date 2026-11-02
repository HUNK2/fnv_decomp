// Source layout: TESGlobal. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTSTAT_PRIVATE_GLOBAL_H
#define FNV_TESOBJECTSTAT_PRIVATE_GLOBAL_H
#include "layout_support.h"
#include "TESForm.h"
#pragma pack(push, 4)
class TESGlobal : public TESForm
{
  public:
    TESGlobal();
    BSStringT<char> cGlobalEditorID;  // +0x18
    char cType;                       // +0x20
    unsigned char layoutPadding21[3];
    float fValue;  // +0x24
    void SetValue(float value);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESGlobal) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESGlobal, cGlobalEditorID) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESGlobal, cType) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESGlobal, fValue) == 0x24);
#endif
