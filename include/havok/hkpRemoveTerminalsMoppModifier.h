// include/havok/hkpRemoveTerminalsMoppModifier.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPREMOVETERMINALSMOPPMODIFIER_H
#define FNV_HAVOK_HKPREMOVETERMINALSMOPPMODIFIER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpRemoveTerminalsMoppModifier : public hkReferencedObject
{
  public:
    char pad8[0x4];
    hkArray<hkUint32> m_kRemovedTerminalIds;  // +0xC
    void* m_pTerminalIdsToRemove;             // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRemoveTerminalsMoppModifier[(sizeof(hkpRemoveTerminalsMoppModifier) == 0x1C) ? 1 : -1];
#endif
