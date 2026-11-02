// fallout_shared/bgsentrypointfunction_decls.h: declares BGSEntryPointFunctionDataActivateChoice
#ifndef FNV_BGSENTRYPOINTFUNCTION_PRIVATE_DECLS_H
#define FNV_BGSENTRYPOINTFUNCTION_PRIVATE_DECLS_H
#include "TESForm.h"
class BGSEntryPointFunctionDataActivateChoice
{
  public:
    unsigned char prefix[8];
    unsigned char formStorage[0x54];
    unsigned short flags;
    void InitializeComponent();
};
#endif
