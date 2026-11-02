// fallout_shared/packagedatadialogue_decls.h: declares TESDialoguePackageData
#ifndef PACKAGEDATADIALOGUE_DECLS_H
#define PACKAGEDATADIALOGUE_DECLS_H

class TESQuest;
enum DIALOGUE_TYPE;
class QuestDialogueInfo;
class TESTopicInfo;
class DialogueItem;
#include "TESForm.h"
#include "TESTopic.h"
TESForm* GetFormByID(unsigned int);
int Warning(const char*, ...);
class TESDialoguePackageData
{
  public:
    void* vtable;
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    void InitItem(TESForm*);
};
#endif
