// include/havok/hkpPhysicsSystem.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x44.
#ifndef FNV_HAVOK_HKPPHYSICSSYSTEM_H
#define FNV_HAVOK_HKPPHYSICSSYSTEM_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpAction;
class hkpConstraintInstance;
class hkpPhantom;
#pragma pack(push, 1)
class hkpPhysicsSystem : public hkReferencedObject
{
  public:
    hkArray<void*> m_ppRigidBodies;                   // +0x8
    hkArray<hkpConstraintInstance*> m_ppConstraints;  // +0x14
    hkArray<hkpAction*> m_ppActions;                  // +0x20
    hkArray<hkpPhantom*> m_kPhantoms;                 // +0x2C
    hkStringPtr m_name;                               // +0x38
    hkUlong m_ulUserData;                             // +0x3C
    hkBool m_bSlotEnabled;                            // +0x40
    char pad41[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPhysicsSystem[(sizeof(hkpPhysicsSystem) == 0x44) ? 1 : -1];
#endif
