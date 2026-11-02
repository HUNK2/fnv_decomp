// include/havok/hkMonitorStreamColorTableColorPair.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKMONITORSTREAMCOLORTABLECOLORPAIR_H
#define FNV_HAVOK_HKMONITORSTREAMCOLORTABLECOLORPAIR_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkMonitorStreamColorTableColorPair
{
  public:
    hkStringPtr m_kColorName;  // +0x0
    hkUint32 m_kDiffuseColor;  // +0x4 (ExtendedColors)
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkMonitorStreamColorTableColorPair[(sizeof(hkMonitorStreamColorTableColorPair) == 0x8) ? 1 : -1];
#endif
