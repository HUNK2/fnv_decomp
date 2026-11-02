// fallout_shared/tesscriptableform_decls.h: declares Script, TESScriptableForm, BGSCameraPath
#ifndef TESSCRIPTABLEFORM_DECLS_H
#define TESSCRIPTABLEFORM_DECLS_H

#include "TESForm.h"
class Script : public TESForm
{
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char padding[3];
    void InitItem(TESForm* owner);
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
TESForm* GetFormByID(unsigned int id);
int Warning(const char*, ...);
#endif
