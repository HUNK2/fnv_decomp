// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);
#endif
