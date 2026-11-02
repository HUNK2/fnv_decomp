// fallout_shared/bgsdebris_magic.h: declares BGSDebrisMagicComponent, BGSDebrisEffectListStorage, EffectItemList, MagicItemForm
#ifndef BGSDEBRIS_MAGIC_H
#define BGSDEBRIS_MAGIC_H
#include "TESForm.h"
class BGSDebrisMagicComponent
{
  public:
    virtual void vfn_00();
};
class BGSDebrisEffectListStorage
{
  public:
    virtual void vfn_00();
    unsigned int list[2];
};
class EffectItemList : public BGSDebrisEffectListStorage, public BGSDebrisMagicComponent
{
  public:
    EffectItemList();
};
class MagicItemForm : public TESForm, public EffectItemList
{
  public:
    MagicItemForm();
};
#endif
