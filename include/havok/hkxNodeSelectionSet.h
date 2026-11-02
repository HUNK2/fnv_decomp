// include/havok/hkxNodeSelectionSet.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKXNODESELECTIONSET_H
#define FNV_HAVOK_HKXNODESELECTIONSET_H

#include "hkBase.h"
class hkxNode;
#pragma pack(push, 1)
class hkxNodeSelectionSet
{
  public:
    char pad0[0x14];
    hkArray<hkxNode*> m_kSelection;  // +0x14
    hkStringPtr m_name;              // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxNodeSelectionSet[(sizeof(hkxNodeSelectionSet) == 0x24) ? 1 : -1];
#endif
