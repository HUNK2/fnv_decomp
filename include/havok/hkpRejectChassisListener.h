// include/havok/hkpRejectChassisListener.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPREJECTCHASSISLISTENER_H
#define FNV_HAVOK_HKPREJECTCHASSISLISTENER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpRejectChassisListener : public hkReferencedObject
{
  public:
    char pad8[0x4];
    void* m_pChassisCollidable;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRejectChassisListener[(sizeof(hkpRejectChassisListener) == 0x10) ? 1 : -1];
#endif
