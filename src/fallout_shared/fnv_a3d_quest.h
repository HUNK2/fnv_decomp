// fallout_shared/fnv_a3d_quest.h: declares ScriptLocals, TESScriptableForm, TESTexture, TESIcon, TESFullName and more
#ifndef FNV_A3D_QUEST_H
#define FNV_A3D_QUEST_H

#include "fnv_a3d_form_types.h"
class TESQuest;
class PlayerQuestData;
class RegionObjectEntry;
class ScriptLocalVariable;
class FormFlagRecord;
class ScriptDefinition;
class ScriptLocals
{
  public:
    Script* m_pOwnerScript;
    char m_cActionFlags;
    unsigned char layoutPadding5[3];
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
    ScriptLocals();
    ~ScriptLocals();
    void LoadGame(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding9[3];
    void InitItem(TESForm* owner);
    Script* GetScript();
    void SetScript(Script* script);
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> cTextureName;
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class TESIcon : public TESTexture
{
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
};
class PerkEntryConditionSet
{
  public:
    BSSimpleList<void*> m_kConditionItems;
    void InitializeConditionItems();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
};
class QuestData
{
  public:
    unsigned char m_ucEntryType, ucPriority;
    unsigned char layoutPadding2[2];
    float fQuestDelayTime;
    void Endian();
};
class AnimationClipStatus
{
  public:
    unsigned char m_ucClipIdentifier;
    bool m_bCompleted;
};
class QuestStage
{
  public:
    AnimationClipStatus m_Data;
    unsigned char layoutPadding2[2];
    BSSimpleList<PlayerQuestData*> m_kStageItems;
    QuestStage();
    ~QuestStage();
    bool GetDone();
    unsigned char GetIndex();
    void SetIndex(unsigned char index);
    void MarkDone(TESQuest* quest, bool allItems);
    void MarkDone(bool done);
    PlayerQuestData* GetStageItemByIndex(unsigned char index);
    BSSimpleList<PlayerQuestData*>* GetStageItemList();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
    void AddStageItem(PlayerQuestData* item);
};
enum QUEST_OBJECTIVE_STATE
{
    QOS_DORMANT = 0,
    QOS_DISPLAYED = 1,
    QOS_COMPLETED = 2,
    QOS_COMPLETED_DISPLAYED = 3
};
class BGSQuestObjective
{
  public:
    virtual ~BGSQuestObjective();
    unsigned int iIndex;
    BSStringT<char> m_kDisplayText;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> m_kTargetList;
    bool bInitialized;
    unsigned char layoutPadding1D[3];
    QUEST_OBJECTIVE_STATE eState;
    BGSQuestObjective();
    unsigned int GetIndex();
    void SetIndex(unsigned int index);
    void InitItem(TESQuest* owner);
    void Load(TESFile* file);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets);
    BSSimpleList<RegionObjectEntry*>* GetTargetList();
    QUEST_OBJECTIVE_STATE GetState();
    void SetState(QUEST_OBJECTIVE_STATE state);
    void SetOwnerQuest(TESQuest* owner);
};
class RegionObjectEntry
{
  public:
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    TESObjectREFR* m_pReference;
    unsigned int m_auiData[14];
    RegionObjectEntry();
    void Load(TESFile* file);
    TESObjectREFR* GetReference(bool resolve);
    PerkEntryConditionSet* GetConditions();
};
class Script : public TESForm
{
  public:
    // The canonical Script prefix is 0x54 bytes; these routines only call members.
    unsigned char scriptFields[0x3c];
    ScriptLocals* GetOrCreateScriptLocals();
    void SetOwnerQuest(TESQuest* quest);
};
class Date
{
  public:
    unsigned short usDate, usYear;
    Date();
    Date(const Date& date);
    ~Date();
};
class PlayerQuestData
{
  public:
    unsigned char m_ucEntryType;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    Script ScriptData;
    unsigned int uiFileOffset;
    unsigned char m_ucClipIdentifier;
    bool bHasLogEntry;
    unsigned char layoutPadding66[2];
    Date* pLogDate;
    TESQuest* pOwner;
    TESQuest* pNextQuest;
    PlayerQuestData();
    bool Load(TESFile* file);
    void SetIndex(unsigned char index);
    void SetHasLogEntry(bool value);
    PerkEntryConditionSet* GetConditions();
    Date* GetLogDate();
    void SetLogDate(Date* date);
};
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool NextChunk();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* value);
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* name, TESFile* file);
};
class FormChangeMask
{
  public:
    unsigned int uiFlags;
    FormChangeMask(unsigned int value);
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int mask);
    FormChangeMask GetOldChangeFlags(unsigned int mask);
    void ReadTypedData(void* data, unsigned int size);
    int ReadElementCount();
};
void __cdecl LogWarning(const char* message, ...);
extern "C" void* __cdecl _alloca(unsigned int size);
union SETTING_VALUE
{
    bool b;
    float f;
    int i;
    const char* s;
};
class INISettingCollection;
template <class C> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> bActivateAllQuestScripts;
class TESQuest : public TESForm
{
  public:
    TESScriptableForm tESScriptableFormComponent;
    TESIcon tESIconComponent;
    TESFullName tESFullNameComponent;
    QuestData data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_kObjectives;
    PerkEntryConditionSet m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> strEditorID;
    virtual const char* GetEditorName() const;  // 0x138: public PC header confirms this slot
    void ResetFormData();
    virtual void ClearData();
    void RemoveAllStages();
    void ClearObjectives();
    unsigned int GetStageMask();
    void UpdateStageMask();
    bool HasStage(unsigned char index);
    bool IsStageComplete(unsigned char index);
    BGSQuestObjective* GetObjective(unsigned int index);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets, BSSimpleList<BGSQuestObjective*>* objectives);
    bool HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets, BSSimpleList<BGSQuestObjective*>* objectives);
    virtual void InitItem();
    bool Load(TESFile* file);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    bool GetEnabled();
    void SetEnabled(bool enabled);
    bool GetCompleted();
    bool GetAllowRepeatStages();
    void SetStartsEnabled(bool enabled);
    PerkEntryConditionSet* GetConditions();
    BSSimpleList<QuestStage*>* GetStageList();
    BSSimpleList<BGSQuestObjective*>* GetObjectiveList();
    QuestStage* GetStage(unsigned char index);
    void AddStageDataAtIndex(QuestStage* stage);
    void AddObjective(BGSQuestObjective* objective);
};
FNV_ASSERT(QuestSize, sizeof(TESQuest) == 0x6c);
FNV_ASSERT(QuestStageListOffset, offsetof(TESQuest, m_kStageList) == 0x44);
FNV_ASSERT(QuestLocalsOffset, offsetof(TESQuest, m_pScriptLocals) == 0x5c);
FNV_ASSERT(QuestCurrentStageOffset, offsetof(TESQuest, m_ucEnabled) == 0x60);
FNV_ASSERT(QuestStageSize, sizeof(QuestStage) == 0x0c);
FNV_ASSERT(QuestObjectiveSize, sizeof(BGSQuestObjective) == 0x24);
FNV_ASSERT(QuestStageItemSize, sizeof(PlayerQuestData) == 0x74);
FNV_ASSERT(QuestTargetSize, sizeof(RegionObjectEntry) == 0x48);
FNV_ASSERT(DateSize, sizeof(Date) == 4);
FNV_ASSERT(ScriptLocalsSize, sizeof(ScriptLocals) == 0x14);
#endif
