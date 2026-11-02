// fallout_shared/magic/spellitem_decls.h: declares SpellItem
#ifndef SPELLITEM_DECLS_H
#define SPELLITEM_DECLS_H

class SpellItem
{
  public:
    void ResetFormData();

  private:
    unsigned char formData[0x34];
    unsigned int spellType;
    int cost;
    unsigned int level;
    unsigned char flags;
};
#endif
