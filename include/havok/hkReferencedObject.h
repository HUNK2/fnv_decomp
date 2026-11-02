// include/havok/hkReferencedObject.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKREFERENCEDOBJECT_H
#define FNV_HAVOK_HKREFERENCEDOBJECT_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkReferencedObject : public hkBaseObject
{
  public:
    hkUint16 m_usMemSizeAndFlags;  // +0x4
    hkInt16 m_sReferenceCount;     // +0x6
};
#pragma pack(pop)
typedef char fnv_hk_size_hkReferencedObject[(sizeof(hkReferencedObject) == 0x8) ? 1 : -1];
#endif
