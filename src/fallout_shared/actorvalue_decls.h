// fallout_shared/actorvalue_decls.h: declares TESFile, TESFullNameLoader, BaseFormComponent, TESForm, TESFullName and more

#ifndef FNV_ACTORVALUE_DECLS_H

#include <stdarg.h>
#define FNV_ACTORVALUE_DECLS_H
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class Actor;
class EffectSetting;
class TESForm;
class TESFile;
class TESFaction;
class TESObjectREFR;
class MediaSet;
class MediaLocationController;
class NiNode;
class TESSound;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void RemoveAll();
    void RemoveHead();
    void Remove(const T& item);
    void AddTail(const T& item);
    void AddHead(T& item);
    void SetItem(const T& item);
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    bool Set(const T* text, unsigned int length);
    const T* String();
    BSStringT<T>& operator=(const T*);
};
FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NO_FORM = 0,
    ENUM_FORM_ID_TES4_ID = 1,
    ENUM_FORM_ID_GRUP_ID = 2,
    ENUM_FORM_ID_GMST_ID = 3,
    ENUM_FORM_ID_TXST_ID = 4,
    ENUM_FORM_ID_MICN_ID = 5,
    ENUM_FORM_ID_GLOB_ID = 6,
    ENUM_FORM_ID_CLAS_ID = 7,
    ENUM_FORM_ID_FACT_ID = 8,
    ENUM_FORM_ID_HDPT_ID = 9,
    ENUM_FORM_ID_HAIR_ID = 10,
    ENUM_FORM_ID_EYES_ID = 11,
    ENUM_FORM_ID_RACE_ID = 12,
    ENUM_FORM_ID_SOUN_ID = 13,
    ENUM_FORM_ID_ASPC_ID = 14,
    ENUM_FORM_ID_SKIL_ID = 15,
    ENUM_FORM_ID_MGEF_ID = 16,
    ENUM_FORM_ID_SCPT_ID = 17,
    ENUM_FORM_ID_LTEX_ID = 18,
    ENUM_FORM_ID_ENCH_ID = 19,
    ENUM_FORM_ID_SPEL_ID = 20,
    ENUM_FORM_ID_ACTI_ID = 21,
    ENUM_FORM_ID_TACT_ID = 22,
    ENUM_FORM_ID_TERM_ID = 23,
    ENUM_FORM_ID_ARMO_ID = 24,
    ENUM_FORM_ID_BOOK_ID = 25,
    ENUM_FORM_ID_CLOT_ID = 26,
    ENUM_FORM_ID_CONT_ID = 27,
    ENUM_FORM_ID_DOOR_ID = 28,
    ENUM_FORM_ID_INGR_ID = 29,
    ENUM_FORM_ID_LIGH_ID = 30,
    ENUM_FORM_ID_MISC_ID = 31,
    ENUM_FORM_ID_STAT_ID = 32,
    ENUM_FORM_ID_SCOL_ID = 33,
    ENUM_FORM_ID_MSTT_ID = 34,
    ENUM_FORM_ID_PWAT_ID = 35,
    ENUM_FORM_ID_GRAS_ID = 36,
    ENUM_FORM_ID_TREE_ID = 37,
    ENUM_FORM_ID_FLOR_ID = 38,
    ENUM_FORM_ID_FURN_ID = 39,
    ENUM_FORM_ID_WEAP_ID = 40,
    ENUM_FORM_ID_AMMO_ID = 41,
    ENUM_FORM_ID_NPC__ID = 42,
    ENUM_FORM_ID_CREA_ID = 43,
    ENUM_FORM_ID_LVLC_ID = 44,
    ENUM_FORM_ID_LVLN_ID = 45,
    ENUM_FORM_ID_KEYM_ID = 46,
    ENUM_FORM_ID_ALCH_ID = 47,
    ENUM_FORM_ID_IDLM_ID = 48,
    ENUM_FORM_ID_NOTE_ID = 49,
    ENUM_FORM_ID_COBJ_ID = 50,
    ENUM_FORM_ID_PROJ_ID = 51,
    ENUM_FORM_ID_LVLI_ID = 52,
    ENUM_FORM_ID_WTHR_ID = 53,
    ENUM_FORM_ID_CLMT_ID = 54,
    ENUM_FORM_ID_REGN_ID = 55,
    ENUM_FORM_ID_NAVI_ID = 56,
    ENUM_FORM_ID_CELL_ID = 57,
    ENUM_FORM_ID_REFR_ID = 58,
    ENUM_FORM_ID_ACHR_ID = 59,
    ENUM_FORM_ID_ACRE_ID = 60,
    ENUM_FORM_ID_PMIS_ID = 61,
    ENUM_FORM_ID_PGRE_ID = 62,
    ENUM_FORM_ID_PBEA_ID = 63,
    ENUM_FORM_ID_PFLA_ID = 64,
    ENUM_FORM_ID_WRLD_ID = 65,
    ENUM_FORM_ID_LAND_ID = 66,
    ENUM_FORM_ID_NAVM_ID = 67,
    ENUM_FORM_ID_TLOD_ID = 68,
    ENUM_FORM_ID_DIAL_ID = 69,
    ENUM_FORM_ID_INFO_ID = 70,
    ENUM_FORM_ID_QUST_ID = 71,
    ENUM_FORM_ID_IDLE_ID = 72,
    ENUM_FORM_ID_PACK_ID = 73,
    ENUM_FORM_ID_CSTY_ID = 74,
    ENUM_FORM_ID_LSCR_ID = 75,
    ENUM_FORM_ID_LVSP_ID = 76,
    ENUM_FORM_ID_ANIO_ID = 77,
    ENUM_FORM_ID_WATR_ID = 78,
    ENUM_FORM_ID_EFSH_ID = 79,
    ENUM_FORM_ID_TOFT_ID = 80,
    ENUM_FORM_ID_EXPL_ID = 81,
    ENUM_FORM_ID_DEBR_ID = 82,
    ENUM_FORM_ID_IMGS_ID = 83,
    ENUM_FORM_ID_IMAD_ID = 84,
    ENUM_FORM_ID_FLST_ID = 85,
    ENUM_FORM_ID_PERK_ID = 86,
    ENUM_FORM_ID_BPTD_ID = 87,
    ENUM_FORM_ID_ADDN_ID = 88,
    ENUM_FORM_ID_AVIF_ID = 89,
    ENUM_FORM_ID_RADS_ID = 90,
    ENUM_FORM_ID_CAMS_ID = 91,
    ENUM_FORM_ID_CPTH_ID = 92,
    ENUM_FORM_ID_VTYP_ID = 93,
    ENUM_FORM_ID_IPCT_ID = 94,
    ENUM_FORM_ID_IPDS_ID = 95,
    ENUM_FORM_ID_ARMA_ID = 96,
    ENUM_FORM_ID_ECZN_ID = 97,
    ENUM_FORM_ID_MESG_ID = 98,
    ENUM_FORM_ID_RGDL_ID = 99,
    ENUM_FORM_ID_DOBJ_ID = 100,
    ENUM_FORM_ID_LGTM_ID = 101,
    ENUM_FORM_ID_MUSC_ID = 102,
    ENUM_FORM_ID_IMOD_ID = 103,
    ENUM_FORM_ID_REPU_ID = 104,
    ENUM_FORM_ID_PCBE_ID = 105,
    ENUM_FORM_ID_RCPE_ID = 106,
    ENUM_FORM_ID_RCCT_ID = 107,
    ENUM_FORM_ID_CHIP_ID = 108,
    ENUM_FORM_ID_CSNO_ID = 109,
    ENUM_FORM_ID_LSCT_ID = 110,
    ENUM_FORM_ID_MSET_ID = 111,
    ENUM_FORM_ID_ALOC_ID = 112,
    ENUM_FORM_ID_CHAL_ID = 113,
    ENUM_FORM_ID_AMEF_ID = 114,
    ENUM_FORM_ID_CCRD_ID = 115,
    ENUM_FORM_ID_CMNY_ID = 116,
    ENUM_FORM_ID_CDCK_ID = 117,
    ENUM_FORM_ID_DEHY_ID = 118,
    ENUM_FORM_ID_HUNG_ID = 119,
    ENUM_FORM_ID_SLPD_ID = 120,
    ENUM_FORM_ID_FORM_ID_COUNT = 121,
};

class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* apData, unsigned int auiSize);
    bool GetChunkData(unsigned int* apData);
    bool NextChunk();
};
class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
extern "C" void* __cdecl _alloca(size_t auiBytes);
enum CHUNK_ID
{
    CHUNK_ID_EDID_ID = 0x44494445,
    CHUNK_ID_OBND_ID = 0x444e424f,
    CHUNK_ID_FULL_ID = 0x4c4c5546,
    CHUNK_ID_NAM1_ID = 0x314d414e,
    CHUNK_ID_NAM2_ID = 0x324d414e,
    CHUNK_ID_NAM3_ID = 0x334d414e,
    CHUNK_ID_NAM4_ID = 0x344d414e,
    CHUNK_ID_NAM5_ID = 0x354d414e,
    CHUNK_ID_NAM6_ID = 0x364d414e,
    CHUNK_ID_NAM7_ID = 0x374d414e,
    CHUNK_ID_HNAM_ID = 0x4d414e48,
    CHUNK_ID_ZNAM_ID = 0x4d414e5a,
    CHUNK_ID_XNAM_ID = 0x4d414e58,
    CHUNK_ID_YNAM_ID = 0x4d414e59,
    CHUNK_ID_LNAM_ID = 0x4d414e4c,
    CHUNK_ID_GNAM_ID = 0x4d414e47,
    CHUNK_ID_SNAM_ID = 0x4d414e53,
    CHUNK_ID_FNAM_ID = 0x4d414e46
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

// Unit-local declaration extension; copied pack declarations remain otherwise unchanged.
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
    virtual bool Load(TESFile* modInfo);
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
    bool IsFormInitialized() const;
    TESForm();
    static TESForm* GetFormByID(unsigned int auiFormID);
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
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
    TESFullName();
    ~TESFullName();
    const char* GetFullName();
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);

class ActorValueInfo;
class ActorValueOwner;
namespace ActorValue {
enum Section
{
    ATTRIBUTE,
    DERIVED_ATTRIBUTE,
    SKILL,
    AI_ATTRIBUTE,
    SPECIAL,
    INT_VALUE,
    RESISTANCE,
    VARIABLE
};
enum Index
{
    ActorValue__Index_AGGRESSION = 0,
    ActorValue__Index_CONFIDENCE = 1,
    ActorValue__Index_ENERGY = 2,
    ActorValue__Index_RESPONSIBILITY = 3,
    ActorValue__Index_MOOD = 4,
    ActorValue__Index_STRENGTH = 5,
    ActorValue__Index_PERCEPTION = 6,
    ActorValue__Index_ENDURANCE = 7,
    ActorValue__Index_CHARISMA = 8,
    ActorValue__Index_INTELLIGENCE = 9,
    ActorValue__Index_AGILITY = 10,
    ActorValue__Index_LUCK = 11,
    ActorValue__Index_ACTION_POINTS = 12,
    ActorValue__Index_CARRY_WEIGHT = 13,
    ActorValue__Index_CRITICAL_CHANCE = 14,
    ActorValue__Index_HEALING_RATE = 15,
    ActorValue__Index_HEALTH = 16,
    ActorValue__Index_MELEE_DAMAGE = 17,
    ActorValue__Index_DAMAGE_RESISTANCE = 18,
    ActorValue__Index_POISON_RESISTANCE = 19,
    ActorValue__Index_RADIATION_RESISTANCE = 20,
    ActorValue__Index_SPEED_MULT = 21,
    ActorValue__Index_FATIGUE = 22,
    ActorValue__Index_KARMA = 23,
    ActorValue__Index_EXPERIENCE_POINTS = 24,
    ActorValue__Index_PERCEPTION_CONDITION = 25,
    ActorValue__Index_ENDURANCE_CONDITION = 26,
    ActorValue__Index_LEFT_ATTACK_CONDITION = 27,
    ActorValue__Index_RIGHT_ATTACK_CONDITION = 28,
    ActorValue__Index_LEFT_MOBILITY_CONDITION = 29,
    ActorValue__Index_RIGHT_MOBILITY_CONDITION = 30,
    ActorValue__Index_BRAIN_CONDITION = 31,
    ActorValue__Index_BARTER = 32,
    ActorValue__Index_BIG_GUNS = 33,
    ActorValue__Index_ENERGY_WEAPONS = 34,
    ActorValue__Index_EXPLOSIVES = 35,
    ActorValue__Index_LOCKPICK = 36,
    ActorValue__Index_MEDICINE = 37,
    ActorValue__Index_MELEE_WEAPONS = 38,
    ActorValue__Index_REPAIR = 39,
    ActorValue__Index_SCIENCE = 40,
    ActorValue__Index_SMALL_GUNS = 41,
    ActorValue__Index_SNEAK = 42,
    ActorValue__Index_SPEECH = 43,
    ActorValue__Index_SURVIVAL = 44,
    ActorValue__Index_UNARMED = 45,
    ActorValue__Index_INVENTORY_WEIGHT = 46,
    ActorValue__Index_PARALYSIS = 47,
    ActorValue__Index_INVISIBILITY = 48,
    ActorValue__Index_CHAMELEON = 49,
    ActorValue__Index_NIGHT_EYE_BONUS = 50,
    ActorValue__Index_TURBO = 51,
    ActorValue__Index_FIRE_RESISTANCE = 52,
    ActorValue__Index_WATER_BREATHING = 53,
    ActorValue__Index_RADIATION_RADS = 54,
    ActorValue__Index_BLOODY_MESS = 55,
    ActorValue__Index_UNARMED_DAMAGE = 56,
    ActorValue__Index_ASSISTANCE = 57,
    ActorValue__Index_ELECTRICAL_RESISTANCE = 58,
    ActorValue__Index_FROST_RESISTANCE = 59,
    ActorValue__Index_ENERGY_RESISTANCE = 60,
    ActorValue__Index_EMP_RESISTANCE = 61,
    ActorValue__Index_VARIABLE_01 = 62,
    ActorValue__Index_VARIABLE_02 = 63,
    ActorValue__Index_VARIABLE_03 = 64,
    ActorValue__Index_VARIABLE_04 = 65,
    ActorValue__Index_VARIABLE_05 = 66,
    ActorValue__Index_VARIABLE_06 = 67,
    ActorValue__Index_VARIABLE_07 = 68,
    ActorValue__Index_VARIABLE_08 = 69,
    ActorValue__Index_VARIABLE_09 = 70,
    ActorValue__Index_VARIABLE_10 = 71,
    ActorValue__Index_IGNORE_CRIPPLED_LIMBS = 72,
    ActorValue__Index_DEHYDRATION = 73,
    ActorValue__Index_HUNGER = 74,
    ActorValue__Index_SLEEPDEPREVATION = 75,
    ActorValue__Index_DAMAGE_THRESHOLD = 76,
    ActorValue__Index_ACTOR_VALUE_COUNT = 77,
    ActorValue__Index_AI_ATTRIBUTE_START = 0,
    ActorValue__Index_ATTRIBUTE_START = 5,
    ActorValue__Index_ACTOR_VALUE_START = 0,
    ActorValue__Index_DERIVED_ATTRIBUTE_START = 12,
    ActorValue__Index_CONDITION_START = 25,
    ActorValue__Index_SKILL_START = 32,
    ActorValue__Index_INT_START = 46,
    ActorValue__Index_VARIABLE_START = 62,
    ActorValue__Index_AI_ATTRIBUTE_END = 5,
    ActorValue__Index_ATTRIBUTE_END = 12,
    ActorValue__Index_CONDITION_END = 32,
    ActorValue__Index_DERIVED_ATTRIBUTE_END = 32,
    ActorValue__Index_SKILL_END = 46,
    ActorValue__Index_INT_END = 62,
    ActorValue__Index_VARIABLE_END = 76,
    ActorValue__Index_ATTRIBUTE_COUNT = 7,
    ActorValue__Index_DERIVED_ATTRIBUTE_COUNT = 20,
    ActorValue__Index_SKILL_COUNT = 14,
    ActorValue__Index_AI_ATTRIBUTE_COUNT = 5,
    ActorValue__Index_CONDITION_COUNT = 7,
    ActorValue__Index_INT_COUNT = 16,
    ActorValue__Index_VALUE_NONE = -1,
    ActorValue__Index_SKILL_NONE = -1,
    ActorValue__Index_ATTRIBUTE_NONE = -1,
};
}

namespace ActorValue {
ActorValueInfo* GetActorValueInfo(Index index);
void LoadActorValueDefinitions();
}
typedef float (*ActorValueDeriveCallback)(ActorValueOwner*, ActorValue::Index);
typedef void (*ActorValueModifiedCallback)(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
typedef ActorValue::Index (*ActorValueMappingCallback)(ActorValueOwner*, ActorValue::Index);
namespace ActorValue {
void RegisterActorValue(Index, char*, Section, unsigned int, ActorValueDeriveCallback, ActorValueMappingCallback,
                        ActorValueModifiedCallback, int, ...);
}
extern bool DAT_011d6154;
class Actor
{
  public:
    static void UpdateActorConditionValue(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void UpdateMobilityConditionValue(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void HandleActorValueUpdate(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void HandleRadiationValueChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
};
void FUN_008ba140(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void SetProcessFlagIfActive(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void FUN_008b9ea0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_006439d0(ActorValueOwner*, ActorValue::Index);
float FUN_00643a10(ActorValueOwner*, ActorValue::Index);
float FUN_00643b10(ActorValueOwner*, ActorValue::Index);
float FUN_00643a70(ActorValueOwner*, ActorValue::Index);
void FUN_008b9db0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_00643670(ActorValueOwner*, ActorValue::Index);
void UpdateActorValueFlag(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_00643b50(ActorValueOwner*, ActorValue::Index);
float FUN_008a0a90(ActorValueOwner*, ActorValue::Index);
void FUN_008ba270(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_00643e40(ActorValueOwner*, ActorValue::Index);
void FUN_008ba2b0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_00643820(ActorValueOwner*, ActorValue::Index);
float FUN_00643a50(ActorValueOwner*, ActorValue::Index);
void FUN_008d53f0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_00643ed0(ActorValueOwner*, ActorValue::Index);
float FUN_00643bd0(ActorValueOwner*, ActorValue::Index);
void FUN_008b9ab0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void FUN_008b9b10(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_008a0cd0(ActorValueOwner*, ActorValue::Index);
void FUN_008b9cc0(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void UpdateStageChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void UpdateStageTransition(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void OnSleepDeprivationStageChanged(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float FUN_008a0ad0(ActorValueOwner*, ActorValue::Index);

class TESDescription : public BaseFormComponent
{
  public:
    TESDescription();
    unsigned long m_uiDescriptionFileOffset;
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> cTextureName;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class ActorValueInfo : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
  public:
    char* m_pName;                                            // +38
    BSStringT<char> m_cAbbreviation;                          // +3c
    unsigned int uFlags;                                      // +44
    ActorValue::Section m_iSection;                           // +48
    ActorValueDeriveCallback m_pDerivedValueFunction;         // +4c
    ActorValueMappingCallback m_pActorValueMapping;           // +50
    ActorValueModifiedCallback m_pActorValueChangedCallback;  // +54
    int m_iEnumeratedValueCount;                              // +58
    ActorValue::Index m_aiEnumeratedValues[15];               // +5c
    int m_iEnumeratedNameCount;
    const char* m_apEnumeratedNames[10];
    ActorValueInfo(int, const char*);
    static unsigned int GetActorValueFormID(ActorValue::Index);
    void SetFormID(unsigned int, bool);
    void SetScriptName(const char*);
    virtual bool Load(TESFile* file);
    void SetEnumerated(int count, ...);
};
FNV_STATIC_ASSERT(offsetof(ActorValueInfo, m_pName) == 0x38);
FNV_STATIC_ASSERT(offsetof(ActorValueInfo, m_pDerivedValueFunction) == 0x4c);

float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
namespace ActorValue {
bool GetFlag(Index, unsigned int);
float ClampValue(Index, float);
}

namespace ActorValue {

Index GetActorValueForSectionIndex(Section, char);
unsigned int GetCountForSection(Section);
const char* GetActorValueName(Index);
bool TryGetActorValue(ActorValueOwner*, Index, float&);
void NotifyActorValueChanged(ActorValueOwner*, Index, float, float, ActorValueOwner*);
Index* GetDependentActorValueIndices(Index, int&);
bool HasActorValueChangedCallback(Index);
}
template <class T> unsigned int BSStringLength(const T*);
class TESObjectIMOD;
class TESObjectWEAP
{
  public:
    unsigned char unknown[0x350];
    TESObjectIMOD* modItem1;
    TESObjectIMOD* modItem2;
    TESObjectIMOD* modItem3;
    void SetModItem(unsigned int slot, TESObjectIMOD* item);
};
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(ActorValue::Index);
    virtual float GetBaseActorValueFloat(ActorValue::Index);
    virtual int GetActorValue(ActorValue::Index);
    virtual float GetCurrentActorValue(ActorValue::Index);
    float GetActorValueFloatByIndex(ActorValue::Index);
    int GetActorValueAsInteger(ActorValue::Index);
};
float FUN_00406ce0(float);

namespace ActorValue {
bool IsDerivedAttribute(Index);
bool IsAIAttribute(Index);
bool IsSkill(Index);
Section GetSection(Index);
unsigned char ToArrayIndex(int, Index);
}
bool FUN_005d1260(ActorValue::Index);
int MinInt(int, int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
class GlobalObject_0066ef90
{
  public:
    ActorValueInfo* values[77];
    GlobalObject_0066ef90();
};
extern GlobalObject_0066ef90 g_011d61c8;
void* __cdecl operator new(size_t) throw();
void __cdecl operator delete(void*);
enum ActorValue__Index
{
    ActorValue__Index_None = -1
};
bool FUN_0066eba0(ActorValue__Index);
#endif
