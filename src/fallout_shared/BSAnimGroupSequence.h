// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout shared/bsanimgroupsequence.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x0049bb10  BSAnimGroupSequence::GetRTTI              (16 bytes)
#ifndef FNV_BSANIMGROUPSEQUENCE_H
#define FNV_BSANIMGROUPSEQUENCE_H


#include "layout_support.h"

// Authored declarations for the BSAnimGroupSequence unit. The canonical
// generated headers do not yet carry the NiRTTI layout, so this header keeps
// the translation unit self-contained. Class, member and static names mirror
// exposes the static ms_kRTTI and the virtual GetRTTI override, and holds the
// TESAnimGroup m_spAnimGroup pointer at +0x74.

class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiControllerSequence
{
};

class TESAnimGroup;

class BSAnimGroupSequence : public NiControllerSequence
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;

  private:
    unsigned int m_spAnimGroup;  // +0x74
};

#endif
