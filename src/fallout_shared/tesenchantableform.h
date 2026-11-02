// fallout_shared/tesenchantableform.h: declares TESEnchantableForm
#ifndef FNV_TESENCHANTABLEFORM_H
#define FNV_TESENCHANTABLEFORM_H


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

#endif
