// include/havok/hkpDisplayBindingData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPDISPLAYBINDINGDATA_H
#define FNV_HAVOK_HKPDISPLAYBINDINGDATA_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpDisplayBindingDataPhysicsSystem;
class hkpDisplayBindingDataRigidBody;
#pragma pack(push, 1)
class hkpDisplayBindingData : public hkReferencedObject
{
  public:
    hkArray<hkpDisplayBindingDataRigidBody*> m_kRigidBodyBindings;          // +0x8
    hkArray<hkpDisplayBindingDataPhysicsSystem*> m_kPhysicsSystemBindings;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpDisplayBindingData[(sizeof(hkpDisplayBindingData) == 0x20) ? 1 : -1];
#endif
