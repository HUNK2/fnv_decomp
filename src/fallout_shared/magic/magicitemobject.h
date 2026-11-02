// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout shared/magic/magicitemobject.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00402990  MagicItemForm::SetAltered        (26 bytes)
#ifndef FNV_MAGICITEMOBJECT_H
#define FNV_MAGICITEMOBJECT_H

#include "layout_support.h"

class TESForm
{
  public:
    void SetAltered(bool bAltered);
};

class MagicItemForm : public TESForm
{
  public:
    void SetAltered(bool bAltered);
};

// @fnv 0x00402990
void MagicItemForm::SetAltered(bool bAltered)
{
    TESForm::SetAltered(bAltered);
}

#endif
