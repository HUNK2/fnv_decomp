// include/havok/hkpDisplayBindingDataPhysicsSystem.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPDISPLAYBINDINGDATAPHYSICSSYSTEM_H
#define FNV_HAVOK_HKPDISPLAYBINDINGDATAPHYSICSSYSTEM_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpDisplayBindingDataRigidBody;
class hkpPhysicsSystem;
#pragma pack(push, 1)
class hkpDisplayBindingDataPhysicsSystem : public hkReferencedObject
{
  public:
    hkArray<hkpDisplayBindingDataRigidBody*> m_kRigidBodyBindings;  // +0x8
    hkpPhysicsSystem* m_pPhysicsSystem;                             // +0x14
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpDisplayBindingDataPhysicsSystem[(sizeof(hkpDisplayBindingDataPhysicsSystem) == 0x18) ? 1 : -1];
#endif
