// include/havok/hkUiAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKUIATTRIBUTE_H
#define FNV_HAVOK_HKUIATTRIBUTE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkUiAttribute
{
  public:
    enum HideInModeler
    {
        NONE = 0,
        MAX = 1,
        MAYA = 2
    };
    hkBool m_bVisible;        // +0x0
    hkInt8 m_eHideInModeler;  // +0x1 (HideInModeler)
    char pad2[0x2];
    char* m_pName;                 // +0x4
    char* m_kGroupData;            // +0x8
    char* m_pLabel;                // +0xC
    hkBool m_bAttributeFlagOne;    // +0x10
    hkBool m_bAttributeFlagTwo;    // +0x11
    hkBool m_bAttributeFlagThree;  // +0x12
    char pad13[0x1];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkUiAttribute[(sizeof(hkUiAttribute) == 0x14) ? 1 : -1];
#endif
