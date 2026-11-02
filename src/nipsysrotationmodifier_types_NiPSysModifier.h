// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSMODIFIER_H
#define FNV_NIPSYSROTATIONMODIFIER_FNV_NIPSYSMODIFIER_H

#include "nipsysrotationmodifier_layout_support.h"
#include "nipsysrotationmodifier_NiFixedString.h"
#include "nipsysrotationmodifier_NiObject.h"
class NiPSysModifier;
class NiPSysData;
class CloningProcess;
class NiParticleSystem;
class NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void Update(float time, NiPSysData* data);
    virtual void Initialize(NiPSysData* data, unsigned short newParticle);
    virtual void HandleReset();
    virtual void SetActive(bool active);
    virtual void SetTargetSystem(NiParticleSystem* target);
    virtual bool IsDeferred() const;
    void CopyMemberData(NiPSysModifier* destination, CloningProcess& process);

  public:
    // base NiObject at +0x0, size 8
    NiFixedString m_kName;         // +0x8, 4 bytes
    unsigned int m_uiUpdateOrder;  // +0xC, 4 bytes
    NiParticleSystem* m_pkTarget;  // +0x10, 4 bytes
    bool m_bModifierActive;        // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // const NiRTTI* __cdecl NiPSysModifier::*()
    // void __cdecl NiPSysModifier::*(NiPSysModifier*, CloningProcess&)
    // void __cdecl NiPSysModifier::*(NiStream&)
    // void __cdecl NiPSysModifier::*(NiStream&)
    // bool __cdecl NiPSysModifier::*(NiStream&)
    // void __cdecl NiPSysModifier::*(NiStream&)
    // bool __cdecl NiPSysModifier::*(NiObject*)
    // void __cdecl NiPSysModifier::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysModifier::*(float, NiPSysData*)
    // const NiFixedString& __cdecl NiPSysModifier::*()
    // void __cdecl NiPSysModifier::*(const NiFixedString&)
    // unsigned int __cdecl NiPSysModifier::*()
    // NiParticleSystem* __cdecl NiPSysModifier::*()
    // bool __cdecl NiPSysModifier::*()
    // void __cdecl NiPSysModifier::*(CloningProcess&)
    // NiPSysModifier
    // void __cdecl NiPSysModifier::*()
    // NiPSysModifier& __cdecl NiPSysModifier::*(const NiPSysModifier&)
    // void __cdecl NiPSysModifier::*()
};
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);
#endif
