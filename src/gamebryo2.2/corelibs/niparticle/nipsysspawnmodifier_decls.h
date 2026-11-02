// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSSPAWNMODIFIER_DECLS_H
#define FNV_NIPSYSSPAWNMODIFIER_DECLS_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
class NiStream;
class NiPSysModifier;
class NiPSysSpawnModifier;
class NiParticleSystem;
class NiPSysBoundUpdateModifier;
class NiBound;
class NiRTTI;
#pragma pack(push, 4)
class NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    // base NiObject at +0x0, size 8
    NiFixedString m_kName;         // +0x8, 4 bytes
    unsigned int m_uiUpdateOrder;  // +0xC, 4 bytes
    NiParticleSystem* m_pkTarget;  // +0x10, 4 bytes
    bool m_bModifierActive;        // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // const NiRTTI* __cdecl NiPSysModifier::*()
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
    // NiPSysModifier
    // void __cdecl NiPSysModifier::*()
    // NiPSysModifier& __cdecl NiPSysModifier::*(const NiPSysModifier&)
    // void __cdecl NiPSysModifier::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);
#pragma pack(push, 4)
class NiPSysSpawnModifier : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    // base NiPSysModifier at +0x0, size 24
    unsigned short m_usSpawnGenerationCount;  // +0x18, 2 bytes
    unsigned char layoutPadding1A[2];
    float m_fSpawnPercentage;                    // +0x1C, 4 bytes
    unsigned short m_usMinimumParticlesToSpawn;  // +0x20, 2 bytes
    unsigned short m_usMaximumParticlesToSpawn;  // +0x22, 2 bytes
    float m_fSpawnedSpeedChaos;                  // +0x24, 4 bytes
    float m_fSpawnDirectionChaos;                // +0x28, 4 bytes
    float m_fYValue;                             // +0x2C, 4 bytes
    float m_fLifeSpanVariation;                  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(NiStream&)
    // void __cdecl NiPSysSpawnModifier::*(NiStream&)
    // bool __cdecl NiPSysSpawnModifier::*(NiStream&)
    // void __cdecl NiPSysSpawnModifier::*(NiStream&)
    // bool __cdecl NiPSysSpawnModifier::*(NiObject*)
    // NiObject* __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(NiTPrimitiveArray<char *>*)
    // NiPSysSpawnModifier
    // void __cdecl NiPSysSpawnModifier::*(float, NiPSysData*)
    // unsigned short __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(unsigned short)
    // float __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(float)
    // unsigned short __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(unsigned short)
    // unsigned short __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(unsigned short)
    // float __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(float)
    // float __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(float)
    // float __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(float)
    // float __cdecl NiPSysSpawnModifier::*()
    // void __cdecl NiPSysSpawnModifier::*(float)
    // void __cdecl NiPSysSpawnModifier::*()
    // NiPSysSpawnModifier& __cdecl NiPSysSpawnModifier::*(const NiPSysSpawnModifier&)
    // void __cdecl NiPSysSpawnModifier::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysSpawnModifier) == 52);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_usSpawnGenerationCount) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_fSpawnPercentage) == 28);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_usMinimumParticlesToSpawn) == 32);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_usMaximumParticlesToSpawn) == 34);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_fSpawnedSpeedChaos) == 36);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_fSpawnDirectionChaos) == 40);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_fYValue) == 44);
FNV_STATIC_ASSERT(offsetof(NiPSysSpawnModifier, m_fLifeSpanVariation) == 48);

// Binary stream read layout and inline operations, corroborated by the PC call sites.
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    FNV_FORCEINLINE unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_pfnRead) == 8);

class NiStream
{
  public:
    unsigned char m_auStreamHeader[0x24C];
    NiBinaryStream* m_pUnderlyingStream;
};
FNV_STATIC_ASSERT(offsetof(NiStream, m_pUnderlyingStream) == 0x24C);

template <class T>
FNV_FORCEINLINE void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> FNV_FORCEINLINE void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}
#pragma pack(push, 4)
class NiPSysBoundUpdateModifier : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual const NiRTTI* GetRTTI() const;

    static const NiRTTI ms_kRTTI;

    short m_usUpdateSkip;                  // +0x18, 2 bytes
    unsigned short m_usUpdateSkipCounter;  // +0x1A, 2 bytes
    NiBound* m_pkBounds;                   // +0x1C, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysBoundUpdateModifier) == 32);
FNV_STATIC_ASSERT(offsetof(NiPSysBoundUpdateModifier, m_usUpdateSkip) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysBoundUpdateModifier, m_usUpdateSkipCounter) == 26);
FNV_STATIC_ASSERT(offsetof(NiPSysBoundUpdateModifier, m_pkBounds) == 28);
#endif
