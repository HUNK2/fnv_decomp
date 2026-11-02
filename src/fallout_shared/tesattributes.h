// fallout_shared/tesattributes.h: declares BaseFormComponent, TESAttributes
#ifndef FNV_TASK_TESATTRIBUTES_H
#define FNV_TASK_TESATTRIBUTES_H

#include "layout_support.h"

class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

#pragma pack(push, 4)
class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];

    TESAttributes();
    void InitializeComponent();
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 12);
FNV_STATIC_ASSERT(offsetof(TESAttributes, cAttribute) == 4);

#endif
