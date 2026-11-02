// include/havok/hkMemoryResourceContainer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKMEMORYRESOURCECONTAINER_H
#define FNV_HAVOK_HKMEMORYRESOURCECONTAINER_H

#include "hkBase.h"
#include "hkResourceContainer.h"
class hkMemoryResourceHandle;
#pragma pack(push, 1)
class hkMemoryResourceContainer : public hkResourceContainer
{
  public:
    hkStringPtr m_name;                              // +0x8
    hkMemoryResourceContainer* m_parent;             // +0xC
    hkArray<hkMemoryResourceHandle*> m_kHandles;     // +0x10
    hkArray<hkMemoryResourceContainer*> m_children;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMemoryResourceContainer[(sizeof(hkMemoryResourceContainer) == 0x28) ? 1 : -1];
#endif
