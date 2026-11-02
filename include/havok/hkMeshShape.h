// include/havok/hkMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKMESHSHAPE_H
#define FNV_HAVOK_HKMESHSHAPE_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkMeshShape : public hkReferencedObject
{
  public:
    enum AccessFlags
    {
        ACCESS_INDICES = 1,
        ACCESS_VERTEX_BUFFER = 2
    };
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMeshShape[(sizeof(hkMeshShape) == 0x8) ? 1 : -1];
#endif
