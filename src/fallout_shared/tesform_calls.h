// Private call declarations from supplied identities and audited public declarations.
#ifndef FNV_UNIT_TESFORM_CALLS_H
#define FNV_UNIT_TESFORM_CALLS_H

#include "tesform_TESForm.h"
#include "tesform_TESFile.h"
class FormChangeMask
{
  public:
    int iFlags;
    FormChangeMask(int flags);
    operator bool() const;
};
FNV_STATIC_ASSERT(sizeof(FormChangeMask) == 4);
FNV_STATIC_ASSERT(offsetof(FormChangeMask, iFlags) == 0);
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int flags);
    void ReadTypedData(void* destination, unsigned int size);
};
class BGSSaveLoadGame
{
  public:
    void NotifyFormIDChanged(TESForm* form, FormChangeMask flags, bool force);
    void ClearFormChangeFlags(TESForm* form, FormChangeMask flags);
    void HasFormChanges(TESForm* form);
};
class TESSaveLoadGame
{
  public:
    void HasFormChanges(TESForm* form, bool force);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
class TESValueForm : public BaseFormComponent
{
  public:
    virtual unsigned int GetSaveSizeTES(unsigned int flags) const;
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags, unsigned int currentFlags);
    unsigned int uiValue;
    void SetFormValue(unsigned int value);
};
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, uiValue) == 4);
#endif
