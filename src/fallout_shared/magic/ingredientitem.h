#ifndef FNV_INGREDIENTITEM_H
#define FNV_INGREDIENTITEM_H


#include "layout_support.h"

class TESForm;

#pragma pack(push, 4)

class MagicItemObject
{
  public:
    virtual ~MagicItemObject();
    virtual void ResetFormData();
    virtual void ClearData();
    virtual void InitItem();

    bool IsFormInitialized() const;

    char pad04[0x48];
};

class TESModelTextureSwap
{
  public:
    virtual ~TESModelTextureSwap();
    void InitItem(TESForm* pForm);

    char pad04[0x28];
};

class TESScriptableForm
{
  public:
    virtual ~TESScriptableForm();
    void InitItem(TESForm* pForm);

    char pad04[0x18];
};

class BGSDestructibleObjectForm
{
  public:
    virtual ~BGSDestructibleObjectForm();
    void InitItem(TESForm* pForm);

    char pad04[0x4];
};

struct EffectIndexRecord
{
    int m_iEffectIndex;           // 0x9C
    unsigned char m_ucEntryType;  // 0xA0
    unsigned char pad[3];
};

class IngredientItem : public MagicItemObject,
                       public TESModelTextureSwap,
                       public TESScriptableForm,
                       public BGSDestructibleObjectForm
{
  public:
    virtual ~IngredientItem();
    virtual void ResetFormData();
    virtual void ClearData();
    virtual void InitItem();

    EffectIndexRecord data;  // 0x9C

    void InitializeComponent();
};

#pragma pack(pop)

#include "ingredientitem_tesclass.h"

// @fnv 0x005f6e60
bool TESClass::IsGuard()
{
    return bool(data.m_ucClassFlags & 2);
}

#endif
