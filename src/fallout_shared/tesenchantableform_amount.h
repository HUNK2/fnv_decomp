// fallout_shared/tesenchantableform_amount.h: declares TESEnchantableForm, EnchantmentItem, BGSCameraPath
#ifndef FNV_TESENCHANTABLEFORM_AMOUNT_H
#define FNV_TESENCHANTABLEFORM_AMOUNT_H


#include "BaseFormComponent.h"

class EnchantmentItem;

enum MagicSystemCastingType
{
    MAGIC_SYSTEM_CAST_ONCE = 0,
    MAGIC_SYSTEM_WHEN_USED = 1,
    MAGIC_SYSTEM_WHEN_STRIKES = 2,
    MAGIC_SYSTEM_CONSTANT_EFFECT = 3,
    MAGIC_SYSTEM_CASTING_COUNT = 4
};

#pragma pack(push, 4)
class TESEnchantableForm : public BaseFormComponent
{
  public:
    static EnchantmentItem* FindFormEnchantment(class TESForm* form);
    TESEnchantableForm();
    void InitializeComponent();
    void SetFormEnchantmentAmount(unsigned short amount);
    void InitItem(class TESForm* owner);

    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned char paddingA[2];
    MagicSystemCastingType m_eCastingType;
};
#pragma pack(pop)

#include "tesenchantableform_decls.h"

// @fnv 0x004be330
EnchantmentItem* TESEnchantableForm::FindFormEnchantment(TESForm* form)
{
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(form);
    return enchantable ? (EnchantmentItem*)((BSSimpleList<BGSPerkEntry*>*)enchantable)->GetNext() : 0;
}

class EnchantmentItem : public TESForm
{
  public:
    bool FUN_004094f0(TESForm* owner);
    char _pdbpad_18[28];
    char data[16];
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);
#endif
