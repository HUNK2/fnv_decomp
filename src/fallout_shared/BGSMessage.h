// fallout_shared/BGSMessage.h: declares BGSMessage
#ifndef FNV_SRC_BGSMESSAGE_H
#define FNV_SRC_BGSMESSAGE_H


#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "PerkEntryConditionSet.h"

class BGSMenuIcon;
class PerkButtonEntry;

#pragma pack(push, 4)
// BGSMessage: a scripted message form (full name, description, button list).
class BGSMessage : public TESForm, public TESFullName, public TESDescription
{
  public:
    BGSMenuIcon* pIcon;                               // +0x2C
    BSSimpleList<PerkButtonEntry*> m_kButtonEntries;  // +0x30
    unsigned int iFlags;                              // +0x38
    unsigned int m_uiDisplayDuration;                 // +0x3C

    BGSMessage();
    void ResetFormData();
    void ClearData();
    void ClearButtons();
    void SetIcon(BGSMenuIcon* icon);
    void InitItem();
    bool Load(TESFile* file);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(BGSMessage) == 64);
FNV_STATIC_ASSERT(offsetof(BGSMessage, pIcon) == 44);
FNV_STATIC_ASSERT(offsetof(BGSMessage, m_kButtonEntries) == 48);
FNV_STATIC_ASSERT(offsetof(BGSMessage, iFlags) == 56);
FNV_STATIC_ASSERT(offsetof(BGSMessage, m_uiDisplayDuration) == 60);
#endif
