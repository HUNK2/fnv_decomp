// include/havok/hkRootLevelContainer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKROOTLEVELCONTAINER_H
#define FNV_HAVOK_HKROOTLEVELCONTAINER_H

#include "hkBase.h"
class hkRootLevelContainerNamedVariant;
#pragma pack(push, 1)
class hkRootLevelContainer
{
  public:
    hkArray<hkRootLevelContainerNamedVariant> m_kNamedVariants;  // +0x0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkRootLevelContainer[(sizeof(hkRootLevelContainer) == 0xC) ? 1 : -1];
#endif
