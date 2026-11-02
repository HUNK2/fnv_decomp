// fallout_shared/bgsmessageicon_decls.h: declares BGSMessageIcon, TESModel, TESModelTextureSwap
#ifndef BGSMESSAGEICON_DECLS_H
#define BGSMESSAGEICON_DECLS_H

#include "BaseFormComponent.h"
#include "TESIcon.h"
class BGSMessageIcon : public BaseFormComponent
{
  public:
    TESIcon Icon;
    void ClearComponent();
};
class DistantTreeTextureInfo;
class TESModel : public BaseFormComponent
{
  public:
    unsigned char modelData[20];
    TESModel();
    ~TESModel();
};
class TESModelTextureSwap : public TESModel
{
  public:
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;
    TESModelTextureSwap();
    void InitializeComponent();
};
#endif
