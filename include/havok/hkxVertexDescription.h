// include/havok/hkxVertexDescription.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKXVERTEXDESCRIPTION_H
#define FNV_HAVOK_HKXVERTEXDESCRIPTION_H

#include "hkBase.h"
class hkxVertexDescriptionElementDecl;
#pragma pack(push, 1)
class hkxVertexDescription
{
  public:
    enum DataType
    {
        HKX_DT_NONE = 0,
        HKX_DT_UINT8 = 1,
        HKX_DT_INT16 = 2,
        HKX_DT_UINT32 = 3,
        HKX_DT_FLOAT = 4,
        HKX_DT_FLOAT2 = 5,
        HKX_DT_FLOAT3 = 6,
        HKX_DT_FLOAT4 = 7
    };
    enum DataUsage
    {
        HKX_DU_NONE = 0,
        HKX_DU_POSITION = 1,
        HKX_DU_COLOR = 2,
        HKX_DU_NORMAL = 4,
        HKX_DU_TANGENT = 8,
        HKX_DU_BINORMAL = 16,
        HKX_DU_TEXCOORD = 32,
        HKX_DU_BLENDWEIGHTS = 64,
        HKX_DU_BLENDINDICES = 128,
        HKX_DU_USERDATA = 256
    };
    hkArray<hkxVertexDescriptionElementDecl> m_kElementDeclarations;  // +0x0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexDescription[(sizeof(hkxVertexDescription) == 0xC) ? 1 : -1];
#endif
