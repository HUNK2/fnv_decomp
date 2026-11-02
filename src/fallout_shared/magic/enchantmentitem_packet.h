// fallout_shared/magic/enchantmentitem_packet.h: declares EffectItemList, SpellItem, TESForm, MagicItemForm, EnchantmentItem
#ifndef ENCHANTMENTITEM_PACKET_H
#define ENCHANTMENTITEM_PACKET_H

class EffectItemList
{
  public:
    unsigned int* vtable;
    unsigned char data[12];
    void RemoveAllEffectItems();
};
class SpellItem
{
  public:
    unsigned char prefix[0x24];
    EffectItemList effects;
    void ClearData();
    char data_db[16];
};
enum ENUM_FORM_ID
{
    FORM_ENCHANTMENT = 19
};
class TESForm
{
  public:
    unsigned int* formVtable;
    unsigned char formData[0x14];
    void SetFormType(ENUM_FORM_ID);
};
class MagicItemForm : public TESForm
{
  public:
    unsigned int* nameVtable;
    unsigned char nameData[8];
    EffectItemList effects;
    MagicItemForm();
    ~MagicItemForm();
};
extern unsigned int DAT_01012ea4[];
extern unsigned int DAT_01012e5c[];
extern unsigned int DAT_01012e44[];
class EnchantmentItem : public MagicItemForm
{
  public:
    EnchantmentItem();
    unsigned int type;
    unsigned int charge;
    unsigned int cost;
    unsigned char flags;
    void ResetFormData();
};
#endif
