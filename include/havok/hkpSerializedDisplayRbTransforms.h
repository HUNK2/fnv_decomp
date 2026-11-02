// include/havok/hkpSerializedDisplayRbTransforms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPSERIALIZEDDISPLAYRBTRANSFORMS_H
#define FNV_HAVOK_HKPSERIALIZEDDISPLAYRBTRANSFORMS_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpSerializedDisplayRbTransformsDisplayTransformPair;
#pragma pack(push, 1)
class hkpSerializedDisplayRbTransforms : public hkReferencedObject
{
  public:
    hkArray<hkpSerializedDisplayRbTransformsDisplayTransformPair> m_kTransforms;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSerializedDisplayRbTransforms[(sizeof(hkpSerializedDisplayRbTransforms) == 0x14) ? 1 : -1];
#endif
