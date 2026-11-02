// include/havok/hkpMoppCode.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPMOPPCODE_H
#define FNV_HAVOK_HKPMOPPCODE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkpMoppCodeCodeInfo.h"
#pragma pack(push, 1)
class hkpMoppCode : public hkReferencedObject
{
  public:
    enum BuildType
    {
        BUILT_WITH_CHUNK_SUBDIVISION = 0,
        BUILT_WITHOUT_CHUNK_SUBDIVISION = 1,
        BUILD_NOT_SET = 2
    };
    char pad8[0x8];
    hkpMoppCodeCodeInfo m_info;  // +0x10
    hkArray<hkUint8> m_data;     // +0x20
    hkInt8 m_eBuildType;         // +0x2C (BuildType)
    char pad2D[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMoppCode[(sizeof(hkpMoppCode) == 0x30) ? 1 : -1];
#endif
