// include/havok/hkMonitorStreamColorTable.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKMONITORSTREAMCOLORTABLE_H
#define FNV_HAVOK_HKMONITORSTREAMCOLORTABLE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkMonitorStreamColorTableColorPair;
#pragma pack(push, 1)
class hkMonitorStreamColorTable : public hkReferencedObject
{
  public:
    hkArray<hkMonitorStreamColorTableColorPair> m_kColorPairs;  // +0x8
    hkUint32 m_uiColorValue;                                    // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMonitorStreamColorTable[(sizeof(hkMonitorStreamColorTable) == 0x18) ? 1 : -1];
#endif
