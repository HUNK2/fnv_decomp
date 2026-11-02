// include/havok/hkRootLevelContainerNamedVariant.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKROOTLEVELCONTAINERNAMEDVARIANT_H
#define FNV_HAVOK_HKROOTLEVELCONTAINERNAMEDVARIANT_H

#include "hkBase.h"
class hkReferencedObject;
#pragma pack(push, 1)
class hkRootLevelContainerNamedVariant
{
  public:
    hkStringPtr m_name;                         // +0x0
    hkStringPtr m_pClassName;                   // +0x4
    hkReferencedObject* m_pReferencedResource;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkRootLevelContainerNamedVariant[(sizeof(hkRootLevelContainerNamedVariant) == 0xC) ? 1 : -1];
#endif
