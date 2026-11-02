// fallout_shared/bgsopencloseform.h: declares TESForm, BGSOpenCloseForm
#ifndef FNV_SRC_BGSOPENCLOSEFORM_H
#define FNV_SRC_BGSOPENCLOSEFORM_H

#include "layout_support.h"

// Research declarations for fallout_shared/bgsopencloseform.cpp.
// TESForm::GetFormType is absent from the canonical include/TESForm.h;
class TESForm
{
  public:
    ENUM_FORM_ID GetFormType() const;
};

class TESObjectREFR;

class BGSOpenCloseForm
{
  public:
    static bool HasOpenCloseComponent(TESForm* apForm);
};
#endif
