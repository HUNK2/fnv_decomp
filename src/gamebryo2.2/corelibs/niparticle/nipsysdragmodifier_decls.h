#ifndef FNV_NIPSYSDRAGMODIFIER_DECLS_H
#define FNV_NIPSYSDRAGMODIFIER_DECLS_H


#include "NiObject.h"
#include "NiFixedString.h"
#include "NiPoint3.h"

class NiAVObject;
class NiPSysData;
class NiParticleSystem;
class CloningProcess;

// These method declarations preserve the canonical particle header ABI.
class NiStream : public NiObject
{
  public:
    void ResetStreamState();
    unsigned int ReadUnsignedInteger();
    unsigned int GetLinkIDFromObject(const NiObject* pkObject);
    NiObject* DeserializeObject();
    NiObject* GetLoadedObject(unsigned int uiLinkID);
};

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
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};

// The three-float LoadBinary implementations are folded together in the PC
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream& kStream);
};

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    FNV_FORCEINLINE unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                            unsigned int uiComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

// The particle shared NiStream declaration exposes only methods. This view
// supplies its input stream member without changing that shared header.
struct NiPSysDragModifierStreamLayout
{
    void** m_ppVirtualMethodTable;
    unsigned char layoutUnmodeled04[0x248];
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T>
FNV_FORCEINLINE void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pkValue, unsigned int uiNumEls = 1)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pkValue, sizeof(T) * uiNumEls, &uiComponentSize, 1);
}

template <class T> FNV_FORCEINLINE void ReadBinaryValue(NiStream& kStream, T& kValue)
{
    NiBinaryStreamLoad(*reinterpret_cast<NiPSysDragModifierStreamLayout*>(&kStream)->m_pUnderlyingStream, &kValue, 1);
}

class NiPSysDragModifier : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    NiAVObject* m_pParent;
    NiPoint3 m_kDragDirection;
    float m_fDragStrength;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;
};

FNV_STATIC_ASSERT(sizeof(NiColor) == 12);
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 0x18);
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_pfnRead) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysDragModifierStreamLayout, m_pUnderlyingStream) == 0x24C);
FNV_STATIC_ASSERT(sizeof(NiPSysDragModifier) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiPSysDragModifier, m_kDragDirection) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiPSysDragModifier, m_fDragStrength) == 0x28);
FNV_STATIC_ASSERT(offsetof(NiPSysDragModifier, m_fFirstLightParameter) == 0x2C);
FNV_STATIC_ASSERT(offsetof(NiPSysDragModifier, m_fSecondLightParameter) == 0x30);

#endif
