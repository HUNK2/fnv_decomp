// fallout_shared/bgstouchspellform.h: declares BGSTouchSpellForm
#ifndef FNV_BGSTOUCHSPELLFORM_H
#define FNV_BGSTOUCHSPELLFORM_H


#include "BaseFormComponent.h"

class TESForm;
class MagicItemForm;

#pragma pack(push, 4)
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    void InitializeComponent();
    void InitItem(TESForm* owner);

    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    unsigned char paddingA[2];
};
#pragma pack(pop)

#endif
