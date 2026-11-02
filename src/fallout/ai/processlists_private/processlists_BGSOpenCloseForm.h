// Unit-private PC declarations from public JohnnyGuitar BGSOpenCloseForm.hpp.
#ifndef FNV_PROCESSLISTS_BGSOPENCLOSEFORM_H
#define FNV_PROCESSLISTS_BGSOPENCLOSEFORM_H

#include "processlists_layout_support.h"
class TESObjectREFR;
class BGSOpenCloseForm
{
  public:
    virtual void HandleOpenAnimationFinish(TESObjectREFR* itemActivated, TESObjectREFR* actionRef);
    virtual void HandleCloseFinish(TESObjectREFR* itemActivated, TESObjectREFR* actionRef);
    virtual bool GetBlockActivatesWhileOpening() const;
    BGSOpenCloseForm();
    ~BGSOpenCloseForm();
};
FNV_STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 0x4);
#endif
