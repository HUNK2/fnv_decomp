// include/havok/hkResourceBase.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKRESOURCEBASE_H
#define FNV_HAVOK_HKRESOURCEBASE_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkResourceBase : public hkReferencedObject
{
  public:
    enum Type
    {
        TYPE_RESOURCE = 0,
        TYPE_CONTAINER = 1
    };
};
#pragma pack(pop)
typedef char fnv_hk_size_hkResourceBase[(sizeof(hkResourceBase) == 0x8) ? 1 : -1];
#endif
