// effectsetting_decls.h: declares BaseFormComponent, TESForm, TESFullName, TESDescription, TESTexture and more
#ifndef EFFECTSETTING_MATCH_H
#define EFFECTSETTING_MATCH_H

#include <stddef.h>
#define FNV_JOIN2(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN2(a, b)
#define FNV_STATIC_ASSERT(e) typedef char FNV_JOIN(fnv_check_, __LINE__)[(e) ? 1 : -1]
class TESFile;
class TESForm;
class TESSound;
class TESObjectLIGH;
class TESEffectShader;
class EffectSetting;
class BSFileEntry;
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    int StrCmp(const T* text, bool notCaseSensitive) const;
};
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    void AddHead(T& item);
    unsigned int ItemsInList();
};
// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);

// Source layout: TESForm. PC corrections are in generate_headers.py.
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
    virtual void LoadGame(void* arg);
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
    unsigned int GetFormID() const;
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, m_ucFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, m_uiFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, m_kSourceFiles) == 0x10);

// Source layout: TESFullName. PC corrections are in generate_headers.py.
class TESFullName : public BaseFormComponent
{
  public:
    void SetFullName(const char* name);
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);

// Source layout: TESDescription. PC corrections are in generate_headers.py.
class TESDescription : public BaseFormComponent
{
  public:
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);

// Source layout: TESTexture. PC corrections are in generate_headers.py.
class TESTexture : public BaseFormComponent
{
  public:
    static void ReadTextureData(TESTexture*, TESFile*);
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);

// Source layout: TESIcon. PC corrections are in generate_headers.py.
class TESIcon : public TESTexture
{
  public:
};
FNV_STATIC_ASSERT(sizeof(TESIcon) == 0xC);

enum EffectArchetypes__ArchetypeID
{
    EffectArchetypes__ArchetypeID_ARCHETYPE_NONE = -1,
    EffectArchetypes__ArchetypeID_ARCHETYPE_START = 0,
    EffectArchetypes__ArchetypeID_VALUE_MODIFIER = 0,
    EffectArchetypes__ArchetypeID_SCRIPT = 1,
    EffectArchetypes__ArchetypeID_DISPEL = 2,
    EffectArchetypes__ArchetypeID_CURE_DISEASE = 3,
    EffectArchetypes__ArchetypeID_ABSORB = 4,
    EffectArchetypes__ArchetypeID_SHIELD = 5,
    EffectArchetypes__ArchetypeID_CALM = 6,
    EffectArchetypes__ArchetypeID_DEMORALIZE = 7,
    EffectArchetypes__ArchetypeID_FRENZY = 8,
    EffectArchetypes__ArchetypeID_COMMAND_CREATURE = 9,
    EffectArchetypes__ArchetypeID_COMMAND_HUMANOID = 10,
    EffectArchetypes__ArchetypeID_INVISIBILITY = 11,
    EffectArchetypes__ArchetypeID_CHAMELEON = 12,
    EffectArchetypes__ArchetypeID_LIGHT = 13,
    EffectArchetypes__ArchetypeID_DARKNESS = 14,
    EffectArchetypes__ArchetypeID_NIGHT_EYE = 15,
    EffectArchetypes__ArchetypeID_LOCK = 16,
    EffectArchetypes__ArchetypeID_OPEN = 17,
    EffectArchetypes__ArchetypeID_BOUND_ITEM = 18,
    EffectArchetypes__ArchetypeID_SUMMON_CREATURE = 19,
    EffectArchetypes__ArchetypeID_DETECT_LIFE = 20,
    EffectArchetypes__ArchetypeID_TELEKINESIS = 21,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_ARMOR = 22,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_WEAPON = 23,
    EffectArchetypes__ArchetypeID_PARALYZE = 24,
    EffectArchetypes__ArchetypeID_REANIMATE = 25,
    EffectArchetypes__ArchetypeID_SOUL_TRAP = 26,
    EffectArchetypes__ArchetypeID_TURN_UNDEAD = 27,
    EffectArchetypes__ArchetypeID_SUN_DAMAGE = 28,
    EffectArchetypes__ArchetypeID_VAMPIRISM = 29,
    EffectArchetypes__ArchetypeID_CURE_PARALYSIS = 30,
    EffectArchetypes__ArchetypeID_CURE_ADDICTION = 31,
    EffectArchetypes__ArchetypeID_CURE_POISON = 32,
    EffectArchetypes__ArchetypeID_CONCUSSION = 33,
    EffectArchetypes__ArchetypeID_VALUE_AND_PARTS = 34,
    EffectArchetypes__ArchetypeID_LIMB_CONDITION = 35,
    EffectArchetypes__ArchetypeID_TURBO = 36,
    EffectArchetypes__ArchetypeID_ARCHETYPE_COUNT = 37
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // BSFileEntry** __cdecl FileEntryList::*()
};
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    static void LoadModelData(TESModel*, TESFile*);
    // FileEntryList* __cdecl TESModel::*()
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
class EffectSetting__EffectSettingData
{
  public:
    unsigned int iFlags;          // +0x0, 4 bytes
    float m_fBaseCost;            // +0x4, 4 bytes
    TESForm* m_pAssociatedForm;   // +0x8, 4 bytes
    int m_iAssociatedSkill;       // +0xC, 4 bytes
    int m_iResistanceActorValue;  // +0x10, 4 bytes
    short m_sCounterEffectCount;  // +0x14, 2 bytes
    unsigned char layoutPadding16[2];
    TESObjectLIGH* apTargetLight;                     // +0x18, 4 bytes
    float fSpeed;                              // +0x1C, 4 bytes
    TESEffectShader* m_pEffectShader;          // +0x20, 4 bytes
    TESEffectShader* m_pEnchantEffectShader;   // +0x24, 4 bytes
    TESSound* m_pCastSound;                    // +0x28, 4 bytes
    TESSound* m_pBoltSound;                    // +0x2C, 4 bytes
    TESSound* m_pContactSound;                 // +0x30, 4 bytes
    TESSound* m_pAreaEffectSound;              // +0x34, 4 bytes
    float m_fEnchantmentFactor;                // +0x38, 4 bytes
    float m_fBarterFactor;                     // +0x3C, 4 bytes
    EffectArchetypes__ArchetypeID m_eEffectTypeItem;  // +0x40, 4 bytes
    int m_iAssociatedActorValue;               // +0x44, 4 bytes
    void Endian();
};
FNV_STATIC_ASSERT(sizeof(EffectSetting__EffectSettingData) == 72);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBaseCost) == 4);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAssociatedForm) == 8);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedSkill) == 12);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iResistanceActorValue) == 16);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_sCounterEffectCount) == 20);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, apTargetLight) == 24);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, fSpeed) == 28);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEffectShader) == 32);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEnchantEffectShader) == 36);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pCastSound) == 40);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pBoltSound) == 44);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pContactSound) == 48);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAreaEffectSound) == 52);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fEnchantmentFactor) == 56);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBarterFactor) == 60);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_eEffectTypeItem) == 64);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedActorValue) == 68);
class EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    // base TESDescription at +0x30, size 8
    // base TESFullName at +0x38, size 12
    // base TESIcon at +0x44, size 12
    bool(__cdecl* m_pEffectSettingCallback)(EffectSetting*, void*);  // +0x50, 4 bytes
    void* m_pPredicateData;                                          // +0x54, 4 bytes
    EffectSetting__EffectSettingData data;                           // +0x58, 72 bytes
    BSSimpleList<EffectSetting*> counterEffects;                     // +0xA0, 8 bytes
    int m_iActorValue;                                               // +0xA8, 4 bytes
    int m_iEffectID;                                                 // +0xAC, 4 bytes
    bool Load(TESFile* file);
    virtual void InitItem();
    void UpdateEffectName(const char* name);
    BSStringT<char> GetEffectName() const;
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    bool HasNoAssociatedActorValue();
    bool IsAssociatedFormUsed();
    bool GetFlag(unsigned int flags) const;
    TESObjectLIGH* GetLight();
    void SetLight(TESObjectLIGH* light);
    TESSound* GetCastSound();
    void SetCastSound(TESSound* sound);
    TESSound* GetBoltSound();
    void SetBoltSound(TESSound* sound);
    TESSound* GetHitSound();
    void SetHitSound(TESSound* sound);
    TESSound* GetAreaSound();
    void SetAreaSound(TESSound* sound);
    TESEffectShader* GetEffectShader();
    void SetEffectShader(TESEffectShader* shader);
    TESEffectShader* GetEnchantEffectShader();
    void SetEnchantEffectShader(TESEffectShader* shader);
    enum EffectFlag
    {
        PLAYER_KNOWS = 0x200000
    };
    void SetFlag(EffectFlag flag, bool value);
    int FUN_004088c0();
    int QueueAssociatedItem();
    int NormalizeEffectLoadedCount();
};
FNV_STATIC_ASSERT(sizeof(EffectSetting) == 176);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pEffectSettingCallback) == 80);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pPredicateData) == 84);
FNV_STATIC_ASSERT(offsetof(EffectSetting, data) == 88);
FNV_STATIC_ASSERT(offsetof(EffectSetting, counterEffects) == 160);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iActorValue) == 168);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iEffectID) == 172);

// These polymorphic types are used only as runtime-cast targets here.
class TESObjectLIGH : public TESForm
{
};
class TESSound : public TESForm
{
};
class TESEffectShader : public TESForm
{
};
class TESFile
{
  public:
    int GetTESForm();
    int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
template <int n> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Warning(const char*, ...);
#endif

double FUN_00408820(float value);
