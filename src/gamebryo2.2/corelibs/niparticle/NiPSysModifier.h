// Authored declaration for the base Nif particle system modifier.
#ifndef FNV_NIPSYSMODIFIER_H
#define FNV_NIPSYSMODIFIER_H

#include "NiObject.h"
#include "NiFixedString.h"

class NiStream;
class NiPSysData;
class NiParticleSystem;
class CloningProcess;

#pragma pack(push, 4)
class NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void Update(float fTime, NiPSysData* pkData);
    virtual void ProcessClone(CloningProcess& kCloning);

    const NiFixedString& GetName() const;
    void SetName(const NiFixedString& kName);
    unsigned int GetOrder() const;
    NiParticleSystem* GetSystemPointer();
    bool GetActive() const;
    virtual void SetActive(bool bActive);
    virtual void SetTargetSystem(NiParticleSystem* pkTarget);

  protected:
    NiFixedString m_kName;         // +0x8
    unsigned int m_uiUpdateOrder;  // +0xc
    NiParticleSystem* m_pkTarget;  // +0x10
    bool m_bModifierActive;        // +0x14
};
#pragma pack(pop)
#endif
