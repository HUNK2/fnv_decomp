// and public JohnnyGuitar PC headers. No implementation bodies are imported.
#ifndef FNV_PROCESSLISTS_DEAD_ANIMATION_ACTORBASE_H
#define FNV_PROCESSLISTS_DEAD_ANIMATION_ACTORBASE_H


#include "processlists_TESBoundAnimObject.h"
#include "processlists_ActorValueOwner.h"
#include "processlists_BaseFormComponent.h"
#include "processlists_TESFullName.h"
#include "processlists_TESHealthForm.h"
#include "processlists_TESModel.h"
#include "processlists_TESScriptableForm.h"
#include "processlists_types_BGSDestructibleObjectForm.h"

class TESActorBase;
class TESLevItem;
class BGSVoiceType;
class FactionReaction;
class InventoryItemEntry;
class MagicItemForm;
class SpellItem;
class TESLevSpell;
class TESPackage;
class CollisionComponent;
class BGSBodyPartData;
class TESCombatStyle;

// Public JohnnyGuitar BSEnums.hpp's enum, expressed in C++03.
struct _ImpactMaterialType
{
    enum Type
    {
        NONE = 0xFFFFFFFFu,
        STONE = 0,
        DIRT = 1,
        GRASS = 2,
        GLASS = 3,
        METAL = 4,
        WOOD = 5,
        ORGANIC = 6,
        CLOTH = 7,
        WATER = 8,
        HOLLOW_METAL = 9,
        ORGANIC_BUG = 10,
        ORGANIC_GLOW = 11,
        COUNT = 12
    };
};
typedef _ImpactMaterialType::Type IMPACT_MATERIAL_TYPE;
FNV_STATIC_ASSERT(sizeof(IMPACT_MATERIAL_TYPE) == 4);

class ActorBaseAttributes
{
  public:
    int m_uiActorFlags;
    unsigned short m_usField04;
    unsigned short m_usField06;
    unsigned short sLevel;
    unsigned short m_usField0A;
    unsigned short m_usField0C;
    unsigned short m_usField0E;
    float m_fField10;
    unsigned short m_usField14;
    unsigned short m_usField16;
};
FNV_STATIC_ASSERT(sizeof(ActorBaseAttributes) == 0x18);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_uiActorFlags) == 0x00);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField04) == 0x04);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField06) == 0x06);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, sLevel) == 0x08);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0A) == 0x0A);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0C) == 0x0C);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0E) == 0x0E);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_fField10) == 0x10);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField14) == 0x14);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField16) == 0x16);

class TESActorBaseData : public BaseFormComponent
{
  public:
    TESActorBaseData();
    ~TESActorBaseData();

    // The inherited BaseFormComponent owns slots 0 through 3.
    virtual void CopyFromTemplateForm(TESActorBase* form);               // +0x10
    virtual bool GetNoVATSmelee() const;                                 // +0x14
    virtual bool GetNoVATSranged() const;                                // +0x18
    virtual bool GetAllowPickpocket() const;                             // +0x1C
    virtual bool GetIsGhost() const;                                     // +0x20
    virtual bool GetIsInvulnerable() const;                              // +0x24
    virtual bool GetNoKnockdowns() const;                                // +0x28
    virtual bool GetCanBeAllRaces() const;                               // +0x2C
    virtual bool GetNoHeadTracking() const;                              // +0x30
    virtual bool GetNoPersuasion() const;                                // +0x34
    virtual bool GetNoLeftArm() const;                                   // +0x38
    virtual bool GetNoRightArm() const;                                  // +0x3C
    virtual bool GetNoHead() const;                                      // +0x40
    virtual bool GetNoShadow() const;                                    // +0x44
    virtual bool GetNoBloodSpray() const;                                // +0x48
    virtual void SetNoBloodSpray(bool value);                            // +0x4C
    virtual bool GetNoBloodDecal() const;                                // +0x50
    virtual void SetNoBloodDecal(bool value);                            // +0x54
    virtual IMPACT_MATERIAL_TYPE GetBloodImpactMaterial() const;         // +0x58
    virtual void SetBloodImpactMaterial(IMPACT_MATERIAL_TYPE material);  // +0x5C
    virtual unsigned short GetFatigue() const;                           // +0x60
    virtual float GetHealthRegeneration() const;                         // +0x64
    virtual BGSVoiceType* GetVoiceType() const;                          // +0x68

    ActorBaseAttributes actorData;
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    BSSimpleList<FactionReaction*> m_pVoiceType;
};
FNV_STATIC_ASSERT(sizeof(TESActorBaseData) == 0x34);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, actorData) == 0x04);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pBaseTemplateForm) == 0x1C);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_kFactionList) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_ppTemplateForms) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pDeathItem) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pVoiceType) == 0x2C);

class TESContainer : public BaseFormComponent
{
  public:
    TESContainer();
    ~TESContainer();
    BSSimpleList<InventoryItemEntry*> objectList;
};
FNV_STATIC_ASSERT(sizeof(TESContainer) == 0x0C);
FNV_STATIC_ASSERT(offsetof(TESContainer, objectList) == 0x04);

class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    BGSTouchSpellForm();
    ~BGSTouchSpellForm();
    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
};
FNV_STATIC_ASSERT(sizeof(BGSTouchSpellForm) == 0x0C);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_pMagicItem) == 0x04);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_usTouchSpellType) == 0x08);

class TESSpellList : public BaseFormComponent
{
  public:
    TESSpellList();
    ~TESSpellList();
    virtual unsigned int GetSaveSizeTES(unsigned int flags);
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags);
    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
};
FNV_STATIC_ASSERT(sizeof(TESSpellList) == 0x14);
FNV_STATIC_ASSERT(offsetof(TESSpellList, spellList) == 0x04);
FNV_STATIC_ASSERT(offsetof(TESSpellList, leveledSpellList) == 0x0C);

class PackedRecordData
{
  public:
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
FNV_STATIC_ASSERT(sizeof(PackedRecordData) == 0x14);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField00) == 0x00);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField01) == 0x01);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField02) == 0x02);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField03) == 0x03);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField04) == 0x04);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField08) == 0x08);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0C) == 0x0C);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0D) == 0x0D);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0E) == 0x0E);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_bField0F) == 0x0F);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField10) == 0x10);

class PackageList
{
  public:
    BSSimpleList<TESPackage*> m_kPackages;
};
FNV_STATIC_ASSERT(sizeof(PackageList) == 0x08);
FNV_STATIC_ASSERT(offsetof(PackageList, m_kPackages) == 0x00);

class TESAIForm : public BaseFormComponent
{
  public:
    TESAIForm();
    ~TESAIForm();
    virtual unsigned int GetSaveSizeTES(unsigned int flags);
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags);
    PackedRecordData m_kAIData;
    PackageList m_kPackageList;
};
FNV_STATIC_ASSERT(sizeof(TESAIForm) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kAIData) == 0x04);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kPackageList) == 0x18);

class TESAttributes : public BaseFormComponent
{
  public:
    TESAttributes();
    ~TESAttributes();
    unsigned char cAttribute[7];
};
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 0x0C);
FNV_STATIC_ASSERT(offsetof(TESAttributes, cAttribute) == 0x04);

class TESAnimation : public BaseFormComponent
{
  public:
    TESAnimation();
    ~TESAnimation();
    BSSimpleList<const char*> m_kKFFileList;
};
FNV_STATIC_ASSERT(sizeof(TESAnimation) == 0x0C);
FNV_STATIC_ASSERT(offsetof(TESAnimation, m_kKFFileList) == 0x04);

class TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    TESActorBase();
    virtual ~TESActorBase();
    virtual BGSBodyPartData* GetBodyPartData() const;
    virtual void SetBodyPartData(BGSBodyPartData* data);
    virtual TESCombatStyle* GetCombatStyle() const;
    virtual void SetCombatStyle(TESCombatStyle* style);
    virtual void SetActorValueF(ActorValue::Index index, float value);
    virtual void SetActorValueI(ActorValue::Index index, int value);
    virtual void ModActorValueF(ActorValue::Index index, float value);
    virtual void ModActorValueI(ActorValue::Index index, int value);

    int GetHealth() const;
};
FNV_STATIC_ASSERT(sizeof(TESActorBase) == 0x10C);
// The first member in each inherited data component verifies its base offset.
FNV_STATIC_ASSERT(offsetof(TESActorBase, actorData) == 0x34);
FNV_STATIC_ASSERT(offsetof(TESActorBase, objectList) == 0x68);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_pMagicItem) == 0x74);
FNV_STATIC_ASSERT(offsetof(TESActorBase, spellList) == 0x80);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_kAIData) == 0x94);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_uiHealthValue) == 0xB4);
FNV_STATIC_ASSERT(offsetof(TESActorBase, cAttribute) == 0xBC);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_kKFFileList) == 0xC8);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_kName) == 0xD4);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_kModelFilePath) == 0xE0);
FNV_STATIC_ASSERT(offsetof(TESActorBase, m_pFormScript) == 0xF8);
FNV_STATIC_ASSERT(offsetof(TESActorBase, pData) == 0x108);

#endif
