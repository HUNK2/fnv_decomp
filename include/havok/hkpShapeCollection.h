// include/havok/hkpShapeCollection.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPSHAPECOLLECTION_H
#define FNV_HAVOK_HKPSHAPECOLLECTION_H

#include "hkBase.h"
#include "hkpShape.h"
#pragma pack(push, 1)
class hkpShapeCollection : public hkpShape
{
  public:
    enum CollectionType
    {
        COLLECTION_LIST = 0,
        COLLECTION_EXTENDED_MESH = 1,
        COLLECTION_TRISAMPLED_HEIGHTFIELD = 2,
        COLLECTION_USER = 3,
        COLLECTION_SIMPLE_MESH = 4,
        COLLECTION_MESH_SHAPE = 5,
        COLLECTION_COMPRESSED_MESH = 6,
        COLLECTION_MAX = 7
    };
    char pad10[0x4];
    hkBool m_bDisableWelding;   // +0x14
    hkUint8 m_eCollectionType;  // +0x15 (CollectionType)
    char pad16[0x2];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpShapeCollection[(sizeof(hkpShapeCollection) == 0x18) ? 1 : -1];
#endif
