// fallout_shared/tesattackdamageform.h: declares BaseFormComponent, TESAttackDamageForm
#ifndef FNV_TASK_TESATTACKDAMAGEFORM_H
#define FNV_TASK_TESATTACKDAMAGEFORM_H

#include "layout_support.h"
#pragma pack(push, 4)
// BaseFormComponent copied from canonical decomp/include/BaseFormComponent.h,
// with the out-of-line constructor and destructor declared: the game emits
// calls to them (0x00402d30, 0x00483710), so the implicit inline versions
// cannot be used. Mangling and layout are unchanged.
class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
// PC vtable 0x0101bf68 order: Init, Free, CopyFromBase, CompareWithBase,
// GetAttackDamage.
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    unsigned short m_usAttackDamage;  // +0x4
    unsigned char layoutPadding6[2];
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    void InitializeComponent();
    virtual void Free();
    virtual unsigned short GetAttackDamage();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);
FNV_STATIC_ASSERT(sizeof(TESAttackDamageForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESAttackDamageForm, m_usAttackDamage) == 4);
#endif
