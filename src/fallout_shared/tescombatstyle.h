// fallout_shared/tescombatstyle.h: declares TESCombatStyle
#ifndef FNV_TESCOMBATSTYLE_H
#define FNV_TESCOMBATSTYLE_H


#include "layout_support.h"
#include "TESForm.h"

class TESCombatStyle : public TESForm
{
  public:
    float UpdateCombatStyle();
};

// @fnv 0x004a7290
float TESCombatStyle::UpdateCombatStyle()
{
    return ((float*)this)[0] * ((float*)this)[0] + ((float*)this)[1] * ((float*)this)[1] +
           ((float*)this)[2] * ((float*)this)[2];
}

#endif
