// Authored research header for fallout_shared/magic/magicitem.cpp.
//   TESForm 0x18, TESBoundObject 0x30, TESFullName 0xC,
//   EffectItemList 0x10 (vftable + BSSimpleList<EffectItem*> base at +4,
//   hostile count at +0xC), MagicItem 0x1C (TESFullName + EffectItemList).
// MagicItemForm carries MagicItem as second base at +0x18;
// MagicItemObject carries it as second base at +0x30.
#ifndef FNV_MAGICITEM_LOCAL_H
#define FNV_MAGICITEM_LOCAL_H

#include "layout_support.h"

struct MagicSystem
{
    enum Range
    {
        SELF = 0,
        TOUCH = 1,
        TARGET = 2,
        RANGE_COUNT = 3
    };
};

class TESForm
{
  public:
    virtual ~TESForm();
    unsigned char formPad[20];
    static TESForm* GetFormByID(unsigned int auiFormID);
};
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);

class TESBoundObject : public TESForm
{
  public:
    virtual ~TESBoundObject();
    unsigned char boundPad[24];
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);

class TESFullName
{
  public:
    virtual ~TESFullName();
    unsigned char namePad[8];
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);

// in EffectSetting. The unused tail of TESModel is retained at its real size.
class TESModel
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(TESModel* component);
    virtual bool CompareWithBase(TESModel* component);
    BSStringT<char> m_kModelFilePath;
    unsigned char modelTail[12];
    unsigned int GetModelLength() const;
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 0x18);

class EffectSetting : public TESForm, public TESModel
{
  public:
    bool IsAssociatedFormUsed();
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    bool IsModelLoaded();
    bool HasNoAssociatedActorValue();
};

class EffectItem
{
  public:
    void InitItem(TESForm* apForm);
    bool IsHostile();
    float GetCost(Actor* pActor);
    bool IsDetrimental();
    MagicSystem::Range GetRange();
    EffectSetting* GetEffectSetting();
};

class EffectItemList : public BSSimpleList<EffectItem*>
{
  public:
    virtual ~EffectItemList();
    int m_iEffectCount;
};
FNV_STATIC_ASSERT(sizeof(EffectItemList) == 0x10);

class MagicItem : public TESFullName, public EffectItemList
{
  public:
    virtual ~MagicItem();
    static MagicItem* GetMagicItemByID(unsigned int auiID);
    EffectSetting* GetEffectSettingForRange(MagicSystem::Range aeRange);
    bool IsLoaded();
    bool IsLoading();

  protected:
    void LoadEffectsFromForm(TESForm* apForm);
};
FNV_STATIC_ASSERT(sizeof(MagicItem) == 0x1C);

class MagicItemForm : public TESForm, public MagicItem
{
  public:
    virtual ~MagicItemForm();
};

class MagicItemObject : public TESBoundObject, public MagicItem
{
  public:
    virtual ~MagicItemObject();
};

#endif
