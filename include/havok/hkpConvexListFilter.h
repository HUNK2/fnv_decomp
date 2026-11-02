// include/havok/hkpConvexListFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPCONVEXLISTFILTER_H
#define FNV_HAVOK_HKPCONVEXLISTFILTER_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpConvexListFilter : public hkReferencedObject
{
  public:
    enum ConvexListCollisionType
    {
        TREAT_CONVEX_LIST_AS_NORMAL = 0,
        TREAT_CONVEX_LIST_AS_LIST = 1,
        TREAT_CONVEX_LIST_AS_CONVEX = 2
    };
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexListFilter[(sizeof(hkpConvexListFilter) == 0x8) ? 1 : -1];
#endif
