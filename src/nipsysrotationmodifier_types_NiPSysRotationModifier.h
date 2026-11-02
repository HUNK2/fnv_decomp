// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSROTATIONMODIFIER_H
#define FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSROTATIONMODIFIER_H

#include "nipsysrotationmodifier_layout_support.h"
#include "nipsysrotationmodifier_NiFixedString.h"
#include "nipsysrotationmodifier_NiObject.h"
#include "nipsysrotationmodifier_NiPoint3.h"
class NiPSysModifier;
class NiPSysRotationModifier;
class NiParticleSystem;
#include "nipsysrotationmodifier_types_NiPSysModifier.h"
class NiPSysRotationModifier : public NiPSysModifier
{
  public:
  protected:
    void CopyMemberData(NiPSysRotationModifier* destination, CloningProcess& process);

  public:
    // base NiPSysModifier at +0x0, size 24
    float m_fInitialRotationSpeed;           // +0x18, 4 bytes
    float m_fInitialRotationSpeedVariation;  // +0x1C, 4 bytes
    float m_fInitialRotationAngle;           // +0x20, 4 bytes
    float m_fInitialRotationAngleVariation;  // +0x24, 4 bytes
    NiPoint3 m_kRotationAxis;                // +0x28, 12 bytes
    bool m_bUseRandomRotationAxis;           // +0x34, 1 bytes
    bool m_bRandomInitialRotationSpeedSign;  // +0x35, 1 bytes
    unsigned char layoutPadding36[2];
    // const NiRTTI* __cdecl NiPSysRotationModifier::*()
    // NiObject* __cdecl NiPSysRotationModifier::*(CloningProcess&)
    // void __cdecl NiPSysRotationModifier::*(NiPSysRotationModifier*, CloningProcess&)
    // void __cdecl NiPSysRotationModifier::*(NiStream&)
    // void __cdecl NiPSysRotationModifier::*(NiStream&)
    // bool __cdecl NiPSysRotationModifier::*(NiStream&)
    // void __cdecl NiPSysRotationModifier::*(NiStream&)
    // bool __cdecl NiPSysRotationModifier::*(NiObject*)
    // NiObject* __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(NiTPrimitiveArray<char *>*)
    // NiPSysRotationModifier
    // void __cdecl NiPSysRotationModifier::*(float, NiPSysData*)
    // void __cdecl NiPSysRotationModifier::*(NiPSysData*, unsigned short)
    // float __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(float)
    // float __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(float)
    // bool __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(bool)
    // float __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(float)
    // float __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(float)
    // bool __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(bool)
    // const NiPoint3& __cdecl NiPSysRotationModifier::*()
    // void __cdecl NiPSysRotationModifier::*(const NiPoint3&)
    // void __cdecl NiPSysRotationModifier::*(NiStream&)
    // void __cdecl NiPSysRotationModifier::*()
    // NiPSysRotationModifier& __cdecl NiPSysRotationModifier::*(const NiPSysRotationModifier&)
    // void __cdecl NiPSysRotationModifier::*()
};
FNV_STATIC_ASSERT(sizeof(NiPSysRotationModifier) == 56);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_fInitialRotationSpeed) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_fInitialRotationSpeedVariation) == 28);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_fInitialRotationAngle) == 32);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_fInitialRotationAngleVariation) == 36);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_kRotationAxis) == 40);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_bUseRandomRotationAxis) == 52);
FNV_STATIC_ASSERT(offsetof(NiPSysRotationModifier, m_bRandomInitialRotationSpeedSign) == 53);
#endif
