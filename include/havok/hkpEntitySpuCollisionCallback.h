// include/havok/hkpEntitySpuCollisionCallback.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPENTITYSPUCOLLISIONCALLBACK_H
#define FNV_HAVOK_HKPENTITYSPUCOLLISIONCALLBACK_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpEntitySpuCollisionCallback
{
  public:
    void* m_pCallbackData;       // +0x0
    hkUint16 m_pRayCursor;         // +0x4
    hkUint8 m_uiCallbackType;    // +0x6
    hkUint8 m_bCallbackEnabled;  // +0x7
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpEntitySpuCollisionCallback[(sizeof(hkpEntitySpuCollisionCallback) == 0x8) ? 1 : -1];
#endif
