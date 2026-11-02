// fallout_shared/PerkButtonEntry.h: declares PerkButtonEntry
#ifndef FNV_SRC_MESSAGEBOX_BUTTON_H
#define FNV_SRC_MESSAGEBOX_BUTTON_H


#include "layout_support.h"
#include "PerkEntryConditionSet.h"

#pragma pack(push, 4)
// One button of a MESG record: its caption plus the conditions that show it.
class PerkButtonEntry
{
  public:
    BSStringT<char> cButtonText;  // +0x00
    PerkEntryConditionSet Conditions;      // +0x08

    PerkButtonEntry();
    ~PerkButtonEntry();
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(PerkButtonEntry) == 0x10);
#endif
