// fallout_shared/packageeventaction_decls.h: declares TESObjectANIO, TESTopic, BGSCameraPath, PackageEventActionData
#ifndef PACKAGEEVENTACTION_DECLS_H
#define PACKAGEEVENTACTION_DECLS_H

class TESQuest;
class ScriptVariableInfo;
class ScriptReferencedObject;
class ScriptLocals;
class PerkEntryConditionSet;
#include "layout_support.h"
#include "TESForm.h"
#include "Script.h"
#include "ScriptVariableInfo.h"
#include "ScriptReferencedObject.h"
class TESObjectANIO : public TESForm
{
};
class TESTopic : public TESForm
{
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
    PerkEntryConditionSet* GetConditions();
};
int Warning();
int Warning(const char*, ...);
unsigned int SetWarningState(bool);
void BGSMessageWarningAuxiliary(int);
TESForm* GetFormByID(unsigned int);
extern ScriptVariableInfo* DAT_011d66ac;
class PackageEventActionData : public BSSimpleList<TESForm*>
{
  public:
    TESForm* pTopic;
    int eType;
    PackageEventActionData();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
};
#endif
