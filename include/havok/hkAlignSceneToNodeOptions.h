// include/havok/hkAlignSceneToNodeOptions.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKALIGNSCENETONODEOPTIONS_H
#define FNV_HAVOK_HKALIGNSCENETONODEOPTIONS_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkAlignSceneToNodeOptions : public hkReferencedObject
{
  public:
    hkBool m_bOption1;  // +0x8
    hkBool m_bOption2;  // +0x9
    hkBool m_bOption3;  // +0xA
    hkBool m_bOption4;  // +0xB
    hkBool m_bOption5;  // +0xC
    hkBool m_bOption6;  // +0xD
    hkBool m_bOption7;  // +0xE
    char padF[0x1];
    hkInt32 m_iOptionValue;   // +0x10
    hkStringPtr m_kNodeName;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkAlignSceneToNodeOptions[(sizeof(hkAlignSceneToNodeOptions) == 0x18) ? 1 : -1];
#endif
