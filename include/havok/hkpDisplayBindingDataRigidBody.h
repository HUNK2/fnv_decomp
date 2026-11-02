// include/havok/hkpDisplayBindingDataRigidBody.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPDISPLAYBINDINGDATARIGIDBODY_H
#define FNV_HAVOK_HKPDISPLAYBINDINGDATARIGIDBODY_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxMesh;
#pragma pack(push, 1)
class hkpDisplayBindingDataRigidBody : public hkReferencedObject
{
  public:
    void* m_pRigidBody;      // +0x8
    hkxMesh* m_pMesh;        // +0xC
    hkMatrix4 m_kTransform;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpDisplayBindingDataRigidBody[(sizeof(hkpDisplayBindingDataRigidBody) == 0x50) ? 1 : -1];
#endif
