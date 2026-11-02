// include/havok/hkMemoryMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKMEMORYMESHSHAPE_H
#define FNV_HAVOK_HKMEMORYMESHSHAPE_H

#include "hkBase.h"
#include "hkMeshShape.h"
class hkMeshSectionCinfo;
#pragma pack(push, 1)
class hkMemoryMeshShape : public hkMeshShape
{
  public:
    hkArray<hkMeshSectionCinfo> m_sections;  // +0x8
    hkArray<hkUint16> m_kIndices16;          // +0x14
    hkArray<hkUint32> m_kIndices32;          // +0x20
    hkStringPtr m_name;                      // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMemoryMeshShape[(sizeof(hkMemoryMeshShape) == 0x30) ? 1 : -1];
#endif
