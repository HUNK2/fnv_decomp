// REVIEW PROPOSAL ONLY. Include within the existing modelloader.cpp TU if approved.
// New declaration-only PC types; no existing packet declaration is changed.
// Every data field is sourced in EVIDENCE.md; no community implementation is copied.
#ifndef FNV_MODELLOADER_SELECTOR_SAME_TU_DECLARATIONS_H
#define FNV_MODELLOADER_SELECTOR_SAME_TU_DECLARATIONS_H
#include <stddef.h>

struct ModInfo;
class BoundObjectListHead;
class Script;
class EnchantmentItem;
class TESSound;
class BGSListForm;
struct DestructibleData;
// Existing NiNode and TESObjectREFR declarations come from modelloader_packet.h.

// xNVSE GameTypes.h:9-18,48-51,101-107; data-only declarations.
class String
{
  public:
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
};
template <class T_Data> struct ListNode
{
    T_Data* data;
    ListNode<T_Data>* next;
};
template <class Item> class tList
{
  public:
    typedef ListNode<Item> _Node;
    _Node m_listHead;
};

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

class BaseFormComponent
{
  public:
    virtual void Init(void);
    virtual void Free(void);
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* src);
};

class TESForm : public BaseFormComponent
{
  public:
    virtual void* Destroy(bool doFree);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual bool Unk_07(void);
    virtual bool LoadForm(ModInfo* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(ModInfo* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(ModInfo* modInfo);
    virtual void WriteFormInfo(ModInfo* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned long changedFlags);
    virtual void MarkAsUnmodified(unsigned long changedFlags);
    virtual unsigned long GetSaveSize(unsigned long changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned long changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned long changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned long changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned long GetTypeID(void);
    virtual void GetDebugName(String* dst);
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
    virtual void readOBNDSubRecord(ModInfo* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool Unk_3F(void) const;
    virtual bool IsActor_Runtime(void);
    virtual unsigned long Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned long formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned long refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    unsigned char typeID;
    unsigned char typeIDPad[3];
    unsigned long flags;
    unsigned long refID;
    tList<ModInfo> mods;
    ENUM_FORM_ID GetFormType() const;
};

class TESObject : public TESForm
{
  public:
    virtual unsigned long Unk_4E(void);
    virtual bool Unk_4F(void);
    virtual unsigned long Unk_50(void);
    virtual bool Unk_51(void);
    virtual void Unk_52(void* arg);
    virtual NiNode* Unk_53(TESObjectREFR* refr, void* arg1);
    virtual void Unk_54(void* arg);
    virtual bool IsInternal(void);
    virtual bool IsInternalMarker(void);
    virtual void Unk_57(void);
    virtual bool Unk_58(void);
    virtual bool Unk_59(void* arg);
    virtual void Unk_5A(void* arg0, void* arg1);
    virtual unsigned long Unk_5B(void);
    virtual unsigned long Unk_5C(void);
    virtual bool Unk_5D(TESObjectREFR* refr);
};

class TESBoundObject : public TESObject
{
  public:
    virtual NiNode* CreateNiNode(TESObjectREFR* refr);
    virtual bool Unk_5F(void);
    BoundObjectListHead* head;
    TESBoundObject* prev;
    TESBoundObject* next;
    short bounds[6];
};

class TESFullName : public BaseFormComponent
{
  public:
    String name;
};

class TESTexture : public BaseFormComponent
{
  public:
    virtual unsigned long Unk_04(void);
    virtual void GetNormalMap(String* str);
    virtual char* GetPathRoot(void);
    String ddsPath;
};

class TESIcon : public TESTexture
{
  public:
};

class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* script;
    bool resolved;
    unsigned char pad[3];
};

class BGSMessageIcon : public BaseFormComponent
{
  public:
    TESIcon icon;
};

class TESValueForm : public BaseFormComponent
{
  public:
    virtual unsigned long GetSaveSize(unsigned long changedFlags);
    virtual void Save(unsigned long changedFlags);
    virtual void Load(unsigned long changedFlags);
    unsigned long value;
};

class TESEnchantableForm : public BaseFormComponent
{
  public:
    virtual unsigned long Unk_04(void);
    EnchantmentItem* enchantItem;
    unsigned short enchantment;
    unsigned short unk1;
    unsigned long unk2;
};

class TESWeightForm : public BaseFormComponent
{
  public:
    float weight;
};

class TESHealthForm : public BaseFormComponent
{
  public:
    virtual unsigned long GetHealth(void);
    unsigned long health;
};

class TESModel : public BaseFormComponent
{
  public:
    virtual void* Destroy(bool noDealloc);
    virtual char* GetModelPath(void);
    virtual void SetModelPath(char* path);
    String nifPath;
    unsigned long unk0C;
    void* unk10;
    unsigned char facegenFlags;
    unsigned char pad15[3];
};

class TESModelTextureSwap : public TESModel
{
  public:
    virtual void* Destroy(bool noDealloc);
    virtual char* GetPath(void);
    virtual void SetPath(char* path);
    virtual void* Unk_07(void);
    struct Texture
    {
        unsigned long textureID;
        unsigned long index3D;
        char textureName[0x80];
    };
    tList<Texture> textureList;
};

class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    DestructibleData* data;
};

class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    TESSound* pickupSound;
    TESSound* putdownSound;
};

class BGSRepairItemList : public BaseFormComponent
{
  public:
    BGSListForm* listForm;
};

class BGSEquipType : public BaseFormComponent
{
  public:
    unsigned long equipType;
};

class BGSBipedModelList : public BaseFormComponent
{
  public:
    BGSListForm* models;
};

class TESModelRDT : public TESModel
{
  public:
    virtual unsigned long Fn_07(void);
};

class TESBipedModelForm : public BaseFormComponent
{
  public:
    unsigned long partMask;
    unsigned char bipedFlags;
    unsigned char fil009[3];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap groundModel[2];
    TESIcon icon[2];
    BGSMessageIcon messageIcon[2];
    TESModelRDT modelRDT;
    static TESBipedModelForm* GetFormAsBipedModel(const TESForm*);
};

class TESObjectARMO : public TESBoundObject
{
  public:
    TESFullName fullName;
    TESScriptableForm scriptable;
    TESEnchantableForm enchantable;
    TESValueForm value;
    TESWeightForm weight;
    TESHealthForm health;
    TESBipedModelForm bipedModel;
    BGSDestructibleObjectForm destuctible;
    BGSEquipType equipType;
    BGSRepairItemList repairItemList;
    BGSBipedModelList bipedModelList;
    BGSPickupPutdownSounds unk16C;
    unsigned short armorRating;
    unsigned short modifiesVoice;
    float damageThreshold;
    unsigned long armorFlags;
    unsigned long unk184;
};

class TESObjectARMA : public TESBoundObject
{
  public:
    TESFullName fullName;
    TESScriptableForm scriptable;
    TESEnchantableForm enchantable;
    TESValueForm value;
    TESWeightForm weight;
    TESHealthForm health;
    TESBipedModelForm bipedModelForm;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    BGSRepairItemList repairList;
    BGSBipedModelList bipedModelList;
    BGSPickupPutdownSounds pickupPutdownSounds;
    unsigned long unk178;
    unsigned long unk17C;
};

class TESObjectCLOT : public TESBoundObject
{
  public:
    TESFullName fullName;
    TESScriptableForm scriptable;
    TESEnchantableForm enchantable;
    TESValueForm value;
    TESWeightForm weight;
    TESBipedModelForm bipedModel;
    BGSDestructibleObjectForm destuctible;
    BGSEquipType equipType;
};

// C++03 compile-time layout checks. No pragma or packing override.
typedef char selector_size_check_0[(sizeof(String) == 0x8) ? 1 : -1];
typedef char selector_size_check_1[(sizeof(ListNode<ModInfo>) == 0x8) ? 1 : -1];
typedef char selector_size_check_2[(sizeof(tList<ModInfo>) == 0x8) ? 1 : -1];
typedef char selector_size_check_3[(sizeof(BaseFormComponent) == 0x4) ? 1 : -1];
typedef char selector_size_check_4[(sizeof(TESForm) == 0x18) ? 1 : -1];
typedef char selector_size_check_5[(sizeof(TESObject) == 0x18) ? 1 : -1];
typedef char selector_size_check_6[(sizeof(TESBoundObject) == 0x30) ? 1 : -1];
typedef char selector_size_check_7[(sizeof(TESFullName) == 0xc) ? 1 : -1];
typedef char selector_size_check_8[(sizeof(TESTexture) == 0xc) ? 1 : -1];
typedef char selector_size_check_9[(sizeof(TESIcon) == 0xc) ? 1 : -1];
typedef char selector_size_check_10[(sizeof(TESScriptableForm) == 0xc) ? 1 : -1];
typedef char selector_size_check_11[(sizeof(BGSMessageIcon) == 0x10) ? 1 : -1];
typedef char selector_size_check_12[(sizeof(TESValueForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_13[(sizeof(TESEnchantableForm) == 0x10) ? 1 : -1];
typedef char selector_size_check_14[(sizeof(TESWeightForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_15[(sizeof(TESHealthForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_16[(sizeof(TESModel) == 0x18) ? 1 : -1];
typedef char selector_size_check_17[(sizeof(TESModelTextureSwap) == 0x20) ? 1 : -1];
typedef char selector_size_check_18[(sizeof(BGSDestructibleObjectForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_19[(sizeof(BGSPickupPutdownSounds) == 0xc) ? 1 : -1];
typedef char selector_size_check_20[(sizeof(BGSRepairItemList) == 0x8) ? 1 : -1];
typedef char selector_size_check_21[(sizeof(BGSEquipType) == 0x8) ? 1 : -1];
typedef char selector_size_check_22[(sizeof(BGSBipedModelList) == 0x8) ? 1 : -1];
typedef char selector_size_check_23[(sizeof(TESModelRDT) == 0x18) ? 1 : -1];
typedef char selector_size_check_24[(sizeof(TESBipedModelForm) == 0xdc) ? 1 : -1];
typedef char selector_size_check_25[(sizeof(TESObjectARMO) == 0x188) ? 1 : -1];
typedef char selector_size_check_26[(sizeof(TESObjectARMA) == 0x180) ? 1 : -1];
typedef char selector_size_check_27[(sizeof(TESObjectCLOT) == 0x154) ? 1 : -1];
typedef char selector_offset_check_0[(offsetof(TESForm, typeID) == 0x4) ? 1 : -1];
typedef char selector_offset_check_1[(offsetof(TESForm, flags) == 0x8) ? 1 : -1];
typedef char selector_offset_check_2[(offsetof(TESForm, refID) == 0xc) ? 1 : -1];
typedef char selector_offset_check_3[(offsetof(TESForm, mods) == 0x10) ? 1 : -1];
typedef char selector_offset_check_4[(offsetof(TESBoundObject, head) == 0x18) ? 1 : -1];
typedef char selector_offset_check_5[(offsetof(TESBoundObject, prev) == 0x1c) ? 1 : -1];
typedef char selector_offset_check_6[(offsetof(TESBoundObject, next) == 0x20) ? 1 : -1];
typedef char selector_offset_check_7[(offsetof(TESBoundObject, bounds) == 0x24) ? 1 : -1];
typedef char selector_offset_check_8[(offsetof(TESModelTextureSwap, textureList) == 0x18) ? 1 : -1];
typedef char selector_offset_check_9[(offsetof(TESBipedModelForm, partMask) == 0x4) ? 1 : -1];
typedef char selector_offset_check_10[(offsetof(TESBipedModelForm, bipedFlags) == 0x8) ? 1 : -1];
typedef char selector_offset_check_11[(offsetof(TESBipedModelForm, bipedModel) == 0xc) ? 1 : -1];
typedef char selector_offset_check_12[(offsetof(TESBipedModelForm, groundModel) == 0x4c) ? 1 : -1];
typedef char selector_offset_check_13[(offsetof(TESBipedModelForm, icon) == 0x8c) ? 1 : -1];
typedef char selector_offset_check_14[(offsetof(TESBipedModelForm, messageIcon) == 0xa4) ? 1 : -1];
typedef char selector_offset_check_15[(offsetof(TESBipedModelForm, modelRDT) == 0xc4) ? 1 : -1];
typedef char selector_offset_check_16[(offsetof(TESObjectARMO, bipedModel) == 0x70) ? 1 : -1];
typedef char selector_offset_check_17[(offsetof(TESObjectARMO, destuctible) == 0x14c) ? 1 : -1];
typedef char selector_offset_check_18[(offsetof(TESObjectARMO, armorFlags) == 0x180) ? 1 : -1];
typedef char selector_offset_check_19[(offsetof(TESObjectARMO, unk184) == 0x184) ? 1 : -1];
typedef char selector_offset_check_20[(offsetof(TESObjectARMA, bipedModelForm) == 0x70) ? 1 : -1];
typedef char selector_offset_check_21[(offsetof(TESObjectARMA, unk178) == 0x178) ? 1 : -1];
typedef char selector_offset_check_22[(offsetof(TESObjectARMA, unk17C) == 0x17c) ? 1 : -1];
typedef char selector_offset_check_23[(offsetof(TESObjectCLOT, bipedModel) == 0x68) ? 1 : -1];
typedef char selector_offset_check_24[(offsetof(TESObjectCLOT, destuctible) == 0x144) ? 1 : -1];
typedef char selector_offset_check_25[(offsetof(TESObjectCLOT, equipType) == 0x14c) ? 1 : -1];

typedef char modelloader_selector_damage_threshold_offset[(offsetof(TESObjectARMO, damageThreshold) == 0x17C) ? 1 : -1];
typedef char modelloader_selector_texture_size[(sizeof(TESModelTextureSwap::Texture) == 0x88) ? 1 : -1];
#endif
