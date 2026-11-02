// fallout_shared/teschallenge_decls.h: declares TESForm, TESScriptableForm, TESDescription, TESFullName, BGSMessageIcon and more

#include "teschallenge_support.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CHALLENGE_TYPE_H
#define FNV_CHALLENGE_TYPE_H
#include "layout_support.h"
enum CHALLENGE_TYPE
{
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST = 0,
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC = 1,
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_CATEGORY = 2,
    CHALLENGE_TYPE_CHALLENGE_TYPE_HIT = 3,
    CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER = 4,
    CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM = 5,
    CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE = 6,
    CHALLENGE_TYPE_CHALLENGE_TYPE_SKILL = 7,
    CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE = 8,
    CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM_LIST = 9,
    CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE_LIST = 10,
    CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT = 11,
    CHALLENGE_TYPE_CHALLENGE_TYPE_CRAFT_WITH_ITEM = 12,
    CHALLENGE_TYPE_CHALLENGE_TYPE_SCRIPTED = 13,
    CHALLENGE_TYPE_CHALLENGE_TYPE_COUNT = 14
};
#endif

// Private PC declarations for this translation unit.
// Source layout: TESForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESFORM_H
#define FNV_TESFORM_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
class BGSLoadFormBuffer;
#pragma pack(push, 4)
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    bool GetInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
    TESForm();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, m_ucFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, m_uiFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, m_kSourceFiles) == 0x10);
#endif

// Source layout: TESScriptableForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESSCRIPTABLEFORM_H
#define FNV_TESSCRIPTABLEFORM_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESScriptableForm : public BaseFormComponent
{
  public:
    void InitItem(TESForm* form);
    Script* GetScript();
    void SetScript(Script* script);
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESScriptableForm) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_pFormScript) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_bHasScript) == 0x8);
#endif

#ifndef FNV_TESCHALLENGE_H
#define FNV_TESCHALLENGE_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H
#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESDescription : public BaseFormComponent
{
  public:
    virtual const char* GetDescription(TESForm*, CHUNK_ID);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);
#endif

#include "TESForm.h"
// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H
#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESFullName : public BaseFormComponent
{
  public:
    const char* GetFullName();
    BSStringT<char> m_kName;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif

#include "TESIcon.h"
#include "TESScriptableForm.h"
class BGSMessageIcon;
class ChallengeData;
class ChallengeProgress;
class TESChallenge;
#pragma pack(push, 4)
class BGSMessageIcon : public BaseFormComponent
{
  public:
    static void LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
    TESIcon Icon;  // +0x4, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
#pragma pack(push, 4)
class ChallengeData
{
  public:
    void SwapEndianFields();
    int m_iPrimaryValue;    // +0x0, 4 bytes
    int m_iAuxiliaryValue;  // +0x4, 4 bytes
    unsigned short nFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    int m_iRecordIndex;                       // +0xC, 4 bytes
    unsigned short FlaggedRecordValueEntry;   // +0x10, 2 bytes
    unsigned short RecordIndexValueData;      // +0x12, 2 bytes
    unsigned short IndexedRecordValueTriple;  // +0x14, 2 bytes
    unsigned char layoutPadding16[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ChallengeData) == 24);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iPrimaryValue) == 0);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iAuxiliaryValue) == 4);
FNV_STATIC_ASSERT(offsetof(ChallengeData, nFlags) == 8);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iRecordIndex) == 12);
FNV_STATIC_ASSERT(offsetof(ChallengeData, FlaggedRecordValueEntry) == 16);
FNV_STATIC_ASSERT(offsetof(ChallengeData, RecordIndexValueData) == 18);
FNV_STATIC_ASSERT(offsetof(ChallengeData, IndexedRecordValueTriple) == 20);
#pragma pack(push, 4)
class ChallengeProgress
{
  public:
    int iProgress;           // +0x0, 4 bytes
    int m_iCompletionCount;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ChallengeProgress) == 8);
FNV_STATIC_ASSERT(offsetof(ChallengeProgress, iProgress) == 0);
FNV_STATIC_ASSERT(offsetof(ChallengeProgress, m_iCompletionCount) == 4);
#pragma pack(push, 4)
class TESChallenge : public TESForm,
                     public TESFullName,
                     public TESDescription,
                     public TESScriptableForm,
                     public TESIcon,
                     public BGSMessageIcon
{
  public:
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    void SetFormOne(TESForm* form);
    void SetFormTwo(TESForm* form);
    TESForm* GetFormOne();
    TESForm* GetFormTwo();
    CHALLENGE_TYPE GetChallengeType();
    int GetStartsLocked();
    int GetRecurring();
    int GetThreshold();
    int GetInterval();
    int GetSpecialOne();
    int GetSpecialTwo();
    int GetSpecialThree();
    int GetUnlocked();
    int GetCompleted();
    int GetRemovedRecurring();
    void ClearProgress();
    void MarkCompleted(bool);
    void SetCompletedRecurring(bool);
    void IncrementProgress(int);
    int GetProgressValue();
    void SetShowZero(bool);
    void MarkForSave();
    virtual void InitItem();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    ChallengeData data;          // +0x54, 24 bytes
    ChallengeProgress progress;  // +0x6C, 8 bytes
    TESForm* m_pPrimaryForm;     // +0x74, 4 bytes
    TESForm* m_pSecondaryForm;   // +0x78, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESChallenge) == 124);
FNV_STATIC_ASSERT(offsetof(TESChallenge, data) == 84);
FNV_STATIC_ASSERT(offsetof(TESChallenge, progress) == 108);
FNV_STATIC_ASSERT(offsetof(TESChallenge, m_pPrimaryForm) == 116);
FNV_STATIC_ASSERT(offsetof(TESChallenge, m_pSecondaryForm) == 120);
#endif
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
int Warning(const char*, ...);

class ChallengeManager
{
  public:
    static BSSimpleList<TESChallenge*> pChallengeList[14];
    static BSSimpleList<TESChallenge*> ms_kInactiveChallengesByType[14];
    static void Clear();
    static void CheckCompletedChallenges();
    static bool UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                        unsigned short specialOne, unsigned short specialTwo,
                                        unsigned short specialThree);
};
class BGSListForm : public TESForm
{
  public:
    BSSimpleList<TESForm*>* GetList();
};
class Script
{
  public:
    void ExecuteScript(TESObjectREFR*, ScriptLocals*);
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    const char* s;
};
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> DAT_011cb4d4;
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
class Interface
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static void PlayUISound(int);
};
class TopicMenuController
{
  public:
    static void IncrementMiscStat(int);
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture*, TESFile*);
    static const char* GetTextureResourceName(TESForm*, TESObjectREFR*);
};
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
extern const float DAT_010162c0;

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)

extern TESDataHandler* g_dataHandler;
extern "C" void* memset(void*, int, unsigned int);
