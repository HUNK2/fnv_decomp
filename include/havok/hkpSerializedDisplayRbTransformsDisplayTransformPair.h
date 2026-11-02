// include/havok/hkpSerializedDisplayRbTransformsDisplayTransformPair.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPSERIALIZEDDISPLAYRBTRANSFORMSDISPLAYTRANSFORMPAIR_H
#define FNV_HAVOK_HKPSERIALIZEDDISPLAYRBTRANSFORMSDISPLAYTRANSFORMPAIR_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpSerializedDisplayRbTransformsDisplayTransformPair
{
  public:
    void* m_pRigidBody;  // +0x0
    char pad4[0xC];
    hkTransform m_kTransform;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSerializedDisplayRbTransformsDisplayTransformPair
    [(sizeof(hkpSerializedDisplayRbTransformsDisplayTransformPair) == 0x50) ? 1 : -1];
#endif
