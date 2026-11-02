// Unit-private class declaration: clean public TESObjectMISC inheritance and PC layout.
// Dependencies retain the supplied complete declarations and all layout assertions.
#ifndef FNV_ACTORMOVER_TESOBJECTMISC_H
#define FNV_ACTORMOVER_TESOBJECTMISC_H
#include "actormover_form_components.h"

class TESObjectMISC : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESSound* pLoopingSound;
    void SetLoopingSound(TESSound* sound);
};
FNV_STATIC_ASSERT(sizeof(TESObjectMISC) == 0xAC);
FNV_STATIC_ASSERT(offsetof(TESObjectMISC, pLoopingSound) == 0xA8);
#endif
