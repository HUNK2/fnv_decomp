// fallout_shared/packagedatadialogue_decls_rtti_variant_decl_packagedatadialogue_rtti_variant.h: declares TESDialoguePackageData
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
struct TargetLocation;
class TESDialoguePackageData
{
  public:
    virtual ~TESDialoguePackageData();  // the original class is polymorphic (rtti_variants.py)
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    TargetLocation* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;
    void InitItem(TESForm*);
};
#endif
