// include/havok/hkaRagdollInstance.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKARAGDOLLINSTANCE_H
#define FNV_HAVOK_HKARAGDOLLINSTANCE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaSkeleton;
class hkpConstraintInstance;
#pragma pack(push, 1)
class hkaRagdollInstance : public hkReferencedObject
{
  public:
    hkArray<void*> m_ppRigidBodies;                   // +0x8
    hkArray<hkpConstraintInstance*> m_ppConstraints;  // +0x14
    hkArray<hkInt32> m_kBoneMap;                      // +0x20
    hkaSkeleton* m_pSkeleton;                         // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaRagdollInstance[(sizeof(hkaRagdollInstance) == 0x30) ? 1 : -1];
#endif
