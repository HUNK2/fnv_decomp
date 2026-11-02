// include/havok/hkxEdgeSelectionChannel.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKXEDGESELECTIONCHANNEL_H
#define FNV_HAVOK_HKXEDGESELECTIONCHANNEL_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxEdgeSelectionChannel : public hkReferencedObject
{
  public:
    hkArray<hkInt32> m_kSelectedEdgeIndices;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxEdgeSelectionChannel[(sizeof(hkxEdgeSelectionChannel) == 0x14) ? 1 : -1];
#endif
