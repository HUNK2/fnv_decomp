// Authored unit-local declarations for
// gamebryo2.2/corelibs/nimain/nitextureeffect.cpp.
//
// - NiFixedString (4 bytes: m_kHandle +0x0) comes from the canonical
//   generated header.
// - NiTextureEffect is declared minimally: InitializePoint3 touches only the
//   static ms_kTextureEffectNames array (4 NiFixedString handles, cf. the
//   an instance, so no instance layout is required.
// - NiGlobalStringTable::AddString, the InterlockedDecrement import and the
//   owned by other units and only declared here.
#ifndef FNV_NITEXTUREEFFECT_UNIT_H
#define FNV_NITEXTUREEFFECT_UNIT_H


#include "NiFixedString.h"

typedef long LONG;

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* pcString);
};

extern "C" __declspec(dllimport) LONG __stdcall InterlockedDecrement(LONG volatile* lpAddend);

extern NiFixedString EmptyFS;

class NiTextureEffect
{
  public:
    static void InitializePoint3();

  protected:
    static NiFixedString ms_kTextureEffectNames[4];
};

#endif
