// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bshavok/bhkhingeconstraint.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x009ba510  bhkHingeConstraint::GetRTTI              (16 bytes)
#ifndef BHKHINGECONSTRAINT_H
#define BHKHINGECONSTRAINT_H


#include "layout_support.h"

// Authored declarations for the bhkHingeConstraint unit. The canonical
// generated headers do not yet carry the NiRTTI or bhkConstraint layouts,
// so this header keeps the translation unit self-contained. Class, member
// from bhkConstraint, exposes ms_kRTTI and the virtual GetRTTI override).
// Canonical additions requested from the operator:
//   - NiRTTI.h: the real NiRTTI declaration (name/base members and
//     constructor) and the bhkConstraint layout.

class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class bhkConstraint
{
  public:
    virtual ~bhkConstraint();
    virtual const NiRTTI* GetRTTI() const;
    static const NiRTTI ms_kRTTI;
};

class bhkHingeConstraint : public bhkConstraint
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

#endif
