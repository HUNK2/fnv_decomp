// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSMESHUPDATEMODIFIER_H
#define FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSMESHUPDATEMODIFIER_H

#include "nipsysrotationmodifier_layout_support.h"
#include "nipsysrotationmodifier_NiFixedString.h"
#include "nipsysrotationmodifier_NiObject.h"
#include "nipsysrotationmodifier_layout_support.h"
class NiAVObject;
class NiPSysMeshUpdateModifier;
class NiPSysModifier;
class NiParticleSystem;
#include "nipsysrotationmodifier_types_NiPSysModifier.h"
class NiPSysMeshUpdateModifier : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& stream);
    // base NiPSysModifier at +0x0, size 24
    NiTObjectArray<NiPointer<NiAVObject> > m_kSceneObjects;  // +0x18, 16 bytes
    // const NiRTTI* __cdecl NiPSysMeshUpdateModifier::*()
    // void __cdecl NiPSysMeshUpdateModifier::*(NiStream&)
    // void __cdecl NiPSysMeshUpdateModifier::*(NiStream&)
    // bool __cdecl NiPSysMeshUpdateModifier::*(NiStream&)
    // void __cdecl NiPSysMeshUpdateModifier::*(NiStream&)
    // bool __cdecl NiPSysMeshUpdateModifier::*(NiObject*)
    // NiObject* __cdecl NiPSysMeshUpdateModifier::*()
    // void __cdecl NiPSysMeshUpdateModifier::*(NiTPrimitiveArray<char *>*)
    // NiPSysMeshUpdateModifier
    // void __cdecl NiPSysMeshUpdateModifier::*(float, NiPSysData*)
    // void __cdecl NiPSysMeshUpdateModifier::*(NiPSysData*, unsigned short)
    // NiAVObject* __cdecl NiPSysMeshUpdateModifier::*(unsigned int)
    // void __cdecl NiPSysMeshUpdateModifier::*(unsigned int, NiAVObject*, NiPointer<NiAVObject>&)
    // unsigned int __cdecl NiPSysMeshUpdateModifier::*()
    // void __cdecl NiPSysMeshUpdateModifier::*(NiStream&)
    // void __cdecl NiPSysMeshUpdateModifier::*()
    // NiPSysMeshUpdateModifier& __cdecl NiPSysMeshUpdateModifier::*(const NiPSysMeshUpdateModifier&)
    // void __cdecl NiPSysMeshUpdateModifier::*()
};
FNV_STATIC_ASSERT(sizeof(NiPSysMeshUpdateModifier) == 40);
FNV_STATIC_ASSERT(offsetof(NiPSysMeshUpdateModifier, m_kSceneObjects) == 24);
#endif
