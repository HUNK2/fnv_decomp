// fallout/ai/mobileobject_topicinfo.h: declares TESTopicInfo
#ifndef FNV_MOBILEOBJECT_TESCONDITION_H
#define FNV_MOBILEOBJECT_TESCONDITION_H
#include "layout_support.h"
#pragma pack(push, 4)
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;  // +0x0
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitializeConditionItems();
    void Load(TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PerkEntryConditionSet) == 0x8);
FNV_STATIC_ASSERT(offsetof(PerkEntryConditionSet, m_kConditionItems) == 0x0);
#endif

#ifndef FNV_MOBILEOBJECT_TOPIC_INFO_DATA_H
#define FNV_MOBILEOBJECT_TOPIC_INFO_DATA_H
#include "layout_support.h"
#pragma pack(push, 4)
class TopicInfoData
{
  public:
    char type;              // +0x0
    char nextSpeaker;       // +0x1
    char flags;             // +0x2
    char DialogueMetadata;  // +0x3
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TopicInfoData) == 0x4);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, type) == 0x0);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, nextSpeaker) == 0x1);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, flags) == 0x2);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, DialogueMetadata) == 0x3);
#endif

// Source layout: TESTopicInfo. PC corrections are in generate_headers.py.
#ifndef FNV_MOBILEOBJECT_TESTOPICINFO_H
#define FNV_MOBILEOBJECT_TESTOPICINFO_H
#include "layout_support.h"
#include "TESForm.h"
#pragma pack(push, 4)
class TESTopicInfo : public TESForm
{
  public:
    PerkEntryConditionSet m_kInfoConditions;  // +0x18
    unsigned short m_uiInfoIndex;    // +0x20
    bool m_bGoodbye;                 // +0x22
    TopicInfoData m_Data;          // +0x23
    unsigned char layoutPadding27[1];
    BSStringT<char> m_kPrompt;                  // +0x28
    BSSimpleList<TESTopic*> m_kAddTopicList;    // +0x30
    TESTopicInfoData* m_pResponseData;       // +0x38
    TESActorBase* m_pDialogueSpeaker;           // +0x3C
    TESForm* m_pPerkSkillStat;                  // +0x40
    SPEECH_CHALLENGE_LEVEL m_eDifficultyLevel;  // +0x44
    TESQuest* m_pOwnerQuest;                    // +0x48
    unsigned long m_ulTopicFlags;               // +0x4C
    bool IsSayOnceADay();
    bool IsRandomEnd();
    bool IsRandom();
    bool IsInfoValidForDialogue(bool& deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    TESTopicInfoData* GetConversationData();
    Script* GetResultScript(unsigned int onEnd);
    bool HasResultScript();
    TESTopicInfo(DIALOGUE_TYPE type);
    void SetRandom(bool random);
    void SetTopicInfoData(TESTopicInfoData* data);
    virtual void InitializeComponent();
    virtual void ClearData();
    unsigned short GetInfoIndex();
    PerkEntryConditionSet* GetInfoConditions();
    void SetOwnerTopic(TESTopic* owner);
    void ResetResponseList();
    void ClearResponses();
    BSSimpleList<TESTopic*>* GetAddTopicList();
    void SetPrompt(const char* prompt);
    void SetSpeaker(TESActorBase* speaker);
    void SetActorValue(ActorValueInfo* value);
    void SetPerk(BGSPerk* perk);
    void SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL difficulty);
    virtual bool LoadForm(TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESTopicInfo) == 0x50);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kInfoConditions) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_uiInfoIndex) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_bGoodbye) == 0x22);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_Data) == 0x23);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kPrompt) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kAddTopicList) == 0x30);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pResponseData) == 0x38);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pDialogueSpeaker) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pPerkSkillStat) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_eDifficultyLevel) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pOwnerQuest) == 0x48);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_ulTopicFlags) == 0x4C);
#endif
