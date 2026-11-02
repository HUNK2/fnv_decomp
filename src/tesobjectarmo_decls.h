// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTARMO_H
#define FNV_TESOBJECTARMO_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "tesobjectarmo_TESForm.h"
#include "TESFullName.h"
#include "TESHealthForm.h"
#include "TESIcon.h"
#include "tesobjectarmo_TESScriptableForm.h"
#include "layout_support.h"
class BGSBipedModelList;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSRepairItemList;
class BipedModelForm;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
// Only corroborated SoundDescriptor fields are exposed; the middle four bytes have
// conflicting chance-field offsets in public declarations and are not accessed.
class SoundDescriptor
{
  public:
    SoundDescriptor();
    void Endian();
    TESSound* SoundAssetTmp;
    unsigned char layoutPadding4[4];
    int eType;
};
FNV_STATIC_ASSERT(sizeof(SoundDescriptor) == 12);
class ShortPoint3;
class ArmorData;
class TESBipedModelForm;
class TESBoundObject__BOUND_DATA;
class TESEnchantableForm;
class TESModel;
class TESModelRDT;
class TESModelTextureSwap;
class TESObjectARMO;
class TESFormList;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
enum BGSEquipType__EQUIP_TYPE
{
    BGSEquipType__EQUIP_TYPE_ET_NONE = -1,
    BGSEquipType__EQUIP_TYPE_ET_BIG_GUN = 0,
    BGSEquipType__EQUIP_TYPE_ET_ENERGY_WEAPON = 1,
    BGSEquipType__EQUIP_TYPE_ET_SMALL_GUN = 2,
    BGSEquipType__EQUIP_TYPE_ET_MELEE_WEAPON = 3,
    BGSEquipType__EQUIP_TYPE_ET_UNARMED_WEAPON = 4,
    BGSEquipType__EQUIP_TYPE_ET_THROWN_WEAPON = 5,
    BGSEquipType__EQUIP_TYPE_ET_MINE = 6,
    BGSEquipType__EQUIP_TYPE_ET_BODY_WEAR = 7,
    BGSEquipType__EQUIP_TYPE_ET_HEAD_WEAR = 8,
    BGSEquipType__EQUIP_TYPE_ET_HAND_WEAR = 9,
    BGSEquipType__EQUIP_TYPE_ET_CHEMS = 10,
    BGSEquipType__EQUIP_TYPE_ET_STIMPACK = 11,
    BGSEquipType__EQUIP_TYPE_ET_FOOD = 12,
    BGSEquipType__EQUIP_TYPE_ET_ALCOHOL = 13,
    BGSEquipType__EQUIP_TYPE_ET_COUNT = 14
};
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // short& __cdecl ShortPoint3::*(int)
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
};
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
class TESEnchantableForm : public BaseFormComponent
{
  public:
    void SetFormEnchanting(EnchantmentItem*);
    void SetCastingType(MagicSystem__CastingType);
    void SetFormEnchantmentAmount(unsigned short);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    EnchantmentItem* m_pEnchantment;       // +0x4, 4 bytes
    unsigned short m_usEnchantmentAmount;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;  // +0xC, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESEnchantableForm) == 16);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_pEnchantment) == 4);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_usEnchantmentAmount) == 8);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_eCastingType) == 12);
class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, iValue) == 4);
class TESWeightForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    float fWeight;  // +0x4, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESWeightForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESWeightForm, fWeight) == 4);
class BipedModelForm
{
  public:
    void Endian();
    unsigned int m_uiBipedModelFlags;  // +0x0, 4 bytes
    unsigned char m_ucBipedModelData;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
};
FNV_STATIC_ASSERT(sizeof(BipedModelForm) == 8);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_uiBipedModelFlags) == 0);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_ucBipedModelData) == 4);
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
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    virtual void SetModelFilePath(const char*);
    static void LoadModelData(TESModel*, TESFile*);
    static void LoadTextureSwapData(TESModel*, TESFile*);
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
class TESModelTextureSwap : public TESModel
{
  public:
    static void ReadTextureSwapChunk(TESModelTextureSwap*, TESFile*);
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
};
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
class BGSMessageIcon : public BaseFormComponent
{
  public:
    void SetMessageIconTextureName(const char*);
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
class TESModelRDT : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
};
FNV_STATIC_ASSERT(sizeof(TESModelRDT) == 24);
class TESBipedModelForm : public BaseFormComponent
{
  public:
    bool GetIsHeavyArmor() const;
    bool GetIsMediumArmor() const;
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BipedModelForm m_kBipedModelForm;   // +0x4, 8 bytes
    TESModelTextureSwap bipedModel[2];  // +0xC, 64 bytes
    TESModelTextureSwap worldModel[2];  // +0x4C, 64 bytes
    TESIcon m_kIcon[2];                 // +0x8C, 24 bytes
    BGSMessageIcon messageIcon[2];      // +0xA4, 32 bytes
    TESModelRDT m_kFaceGenModel;        // +0xC4, 24 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBipedModelForm) == 220);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, m_kBipedModelForm) == 4);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, bipedModel) == 12);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, worldModel) == 76);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, m_kIcon) == 140);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, messageIcon) == 164);
FNV_STATIC_ASSERT(offsetof(TESBipedModelForm, m_kFaceGenModel) == 196);
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
};
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
class BGSEquipType : public BaseFormComponent
{
  public:
    void SetEquipType(BGSEquipType__EQUIP_TYPE);
    // base BaseFormComponent at +0x0, size 4
    BGSEquipType__EQUIP_TYPE m_eEquipType;  // +0x4, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(BGSEquipType) == 8);
FNV_STATIC_ASSERT(offsetof(BGSEquipType, m_eEquipType) == 4);
class BGSRepairItemList : public BaseFormComponent
{
  public:
    void SetRepairList(BGSListForm*);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
    // BSSimpleList<TESForm *>* __cdecl BGSRepairItemList::*(TESForm*)
};
FNV_STATIC_ASSERT(sizeof(BGSRepairItemList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSRepairItemList, pListForm) == 4);
class BGSBipedModelList : public BaseFormComponent
{
  public:
    void SetBipedModelList(BGSListForm*);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(BGSBipedModelList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSBipedModelList, pListForm) == 4);
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    void SetPickupSound(TESSound*);
    void SetPutdownSound(TESSound*);
    void InitItem(TESForm*);
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);
class ArmorData
{
  public:
    void FUN_00535aa0();
    unsigned short m_usArmorRating;  // +0x0, 2 bytes
    unsigned char layoutPadding2[2];
    float fArmorProtectionValue;  // +0x4, 4 bytes
    unsigned char cFlags;         // +0x8, 1 bytes
    unsigned char m_ucSubtype;    // +0x9, 1 bytes
    unsigned char layoutPaddingA[2];
};
FNV_STATIC_ASSERT(sizeof(ArmorData) == 12);
FNV_STATIC_ASSERT(offsetof(ArmorData, m_usArmorRating) == 0);
FNV_STATIC_ASSERT(offsetof(ArmorData, fArmorProtectionValue) == 4);
FNV_STATIC_ASSERT(offsetof(ArmorData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(ArmorData, m_ucSubtype) == 9);
class TESObjectARMO : public TESBoundObject,
                      public TESFullName,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESBipedModelForm,
                      public BGSDestructibleObjectForm,
                      public BGSEquipType,
                      public BGSRepairItemList,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
  public:
    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    unsigned char GetArmorType();
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESScriptableForm at +0x3C, size 12
    // base TESEnchantableForm at +0x48, size 16
    // base TESValueForm at +0x58, size 8
    // base TESWeightForm at +0x60, size 8
    // base TESHealthForm at +0x68, size 8
    // base TESBipedModelForm at +0x70, size 220
    // base BGSDestructibleObjectForm at +0x14C, size 8
    // base BGSEquipType at +0x154, size 8
    // base BGSRepairItemList at +0x15C, size 8
    // base BGSBipedModelList at +0x164, size 8
    // base BGSPickupPutdownSounds at +0x16C, size 12
    ArmorData data;      // +0x178, 12 bytes
    unsigned int flags;  // +0x184, 4 bytes
    union
    {                                                               // overlapping CodeView storage
        BSSimpleList<SoundDescriptor*>* m_pPickupPutdownSoundList;  // +0x188, 4 bytes
        TESObjectARMO* m_pSoundSourceArmor;                         // +0x188, 4 bytes
    };
    bool m_bUsesSoundList;  // +0x18C, 1 bytes
    unsigned char layoutPadding18D[3];
};
FNV_STATIC_ASSERT(sizeof(TESObjectARMO) == 400);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, data) == 376);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, flags) == 388);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_pPickupPutdownSoundList) == 392);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_pSoundSourceArmor) == 392);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_bUsesSoundList) == 396);
#endif
