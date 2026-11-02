// include/havok/hkaDeltaCompressedAnimationQuantizationFormat.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKADELTACOMPRESSEDANIMATIONQUANTIZATIONFORMAT_H
#define FNV_HAVOK_HKADELTACOMPRESSEDANIMATIONQUANTIZATIONFORMAT_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaDeltaCompressedAnimationQuantizationFormat
{
  public:
    hkUint8 m_ucFirstQuantizationParameter;   // +0x0
    hkUint8 m_ucSecondQuantizationParameter;  // +0x1
    char pad2[0x2];
    hkUint32 m_uiDynamicDofCount;      // +0x4
    hkUint32 m_uiOffsetIndexOffset;    // +0x8
    hkUint32 m_uiScaleIndexOffset;     // +0xC
    hkUint32 m_uiBitWidthIndexOffset;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaDeltaCompressedAnimationQuantizationFormat
    [(sizeof(hkaDeltaCompressedAnimationQuantizationFormat) == 0x14) ? 1 : -1];
#endif
