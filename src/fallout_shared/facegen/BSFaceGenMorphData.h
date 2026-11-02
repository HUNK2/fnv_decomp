// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/fallout_shared/facegen/bsfacegenmorphdata.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00661d90  BSFaceGenMorphDataHead::GetRTTI           (16 bytes)
#ifndef FNV_BSFACEGENMORPHDATA_H
#define FNV_BSFACEGENMORPHDATA_H


#include "layout_support.h"

// Authored declarations for the BSFaceGenMorphData unit. The canonical
// generated headers do not yet carry the NiRTTI layout, so this header
// keeps the translation unit self-contained. Class, member and static
// BSFaceGenMorphData, exposes the static ms_kRTTI and the virtual
// GetRTTI override, and holds the four morph pointer arrays.

class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

// Local stand-ins for the canonical NiRefObject/NiObject hierarchy
// (decomp/include/NiRefObject.h, decomp/include/NiObject.h): the real
// BSFaceGenMorphData derives from NiObject, which carries the reference
// count at +0x4 behind the vtable pointer.
class NiRefObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
};

class NiObject : public NiRefObject
{
};

class BSFaceGenMorphData : public NiObject
{
};

class BSFaceGenMorph;

class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
  public:
    BSFaceGenMorphDataHead();
    virtual ~BSFaceGenMorphDataHead();

    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;

  private:
    BSFaceGenMorph** m_ppExpressionMorphs;  // +0x8
    BSFaceGenMorph** m_ppModifierMorphs;    // +0xC
    BSFaceGenMorph** m_ppPhonemeMorphs;     // +0x10
    BSFaceGenMorph** m_ppCustomMorphs;      // +0x14
};

#endif
