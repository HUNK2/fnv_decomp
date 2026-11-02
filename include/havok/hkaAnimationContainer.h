// include/havok/hkaAnimationContainer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x44.
#ifndef FNV_HAVOK_HKAANIMATIONCONTAINER_H
#define FNV_HAVOK_HKAANIMATIONCONTAINER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaAnimation;
class hkaAnimationBinding;
class hkaMeshBinding;
class hkaSkeleton;
#pragma pack(push, 1)
class hkaAnimationContainer : public hkReferencedObject
{
  public:
    hkArray<hkaSkeleton*> m_kSkeletons;                  // +0x8
    hkArray<hkaAnimation*> m_kAnimations;                // +0x14
    hkArray<hkaAnimationBinding*> m_kRigidBodyBindings;  // +0x20
    hkArray<void*> m_kAttachments;                       // +0x2C
    hkArray<hkaMeshBinding*> m_kMeshBindings;            // +0x38
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaAnimationContainer[(sizeof(hkaAnimationContainer) == 0x44) ? 1 : -1];
#endif
