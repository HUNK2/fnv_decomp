// Source layout: BSExtraData. PC corrections are in generate_headers.py.
#ifndef FNV_BSEXTRADATA_H
#define FNV_BSEXTRADATA_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSExtraData
{
  public:
    virtual ~BSExtraData();  // the original class is polymorphic (rtti_variants.py)
  public:
    unsigned char m_ucExtraDataType;  // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;  // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSExtraData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSExtraData, m_ucExtraDataType) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSExtraData, pNext) == 0x8);
#endif
