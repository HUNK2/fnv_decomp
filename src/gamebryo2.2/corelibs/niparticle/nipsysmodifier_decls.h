// gamebryo2.2/corelibs/niparticle/nipsysmodifier_decls.h: declares NiObject, CloningProcess, NiBinaryStream, NiStream, NiPSysModifier
#ifndef FNV_NIPSYSMODIFIER_DECLS_H
#define FNV_NIPSYSMODIFIER_DECLS_H


#include "NiRefObject.h"
#include "NiFixedString.h"

extern NiFixedString EmptyFS;

class NiStream;
class CloningProcess;
class NiParticleSystem;

// Only the base operations used by this translation unit are exposed here.
class NiObject : public NiRefObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    // Base copying operation has no identified name in the PC symbol evidence.
    void CreateVertexBufferSet(NiObject* pkDest, CloningProcess& kCloning);
};

class CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;
    unsigned int m_eCloneCopyMode;
    char m_bExactType;
};

class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};

// The pointer-map lookup is folded with this canonically bound specialization.
inline bool NiPSysCloneMapGetAt(NiTPointerMap<NiObject*, NiObject*>* pkMap, NiObject* pkOriginal, NiObject*& pkClone)
{
    return reinterpret_cast<NiTStringPointerMap<ShaderBufferRecord*>*>(pkMap)->GetAt(
        reinterpret_cast<const char*>(pkOriginal), reinterpret_cast<ShaderBufferRecord*&>(pkClone));
}

class NiBinaryStream : public NiMemObject
{
  public:
    virtual ~NiBinaryStream();
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    inline unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                   unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class NiStream : public NiObject
{
  public:
    unsigned char m_streamHeader[0xD8 - 8];
    unsigned int m_uiNifVersion;
    unsigned char m_streamTables[0x24C - 0xDC];
    NiBinaryStream* m_pUnderlyingStream;

    void ReadFixedString(NiFixedString& kString);
    void ReadStringTableEntry(NiFixedString& kString);
    void ResetStreamState();
    NiObject* GetLoadedObject();
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pValue, sizeof(T), &uiSize, 1);
}

class NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    void CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning);

    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};

FNV_STATIC_ASSERT(sizeof(NiObject) == 8);
FNV_STATIC_ASSERT(sizeof(CloningProcess) == 16);
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifVersion) == 0xD8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pUnderlyingStream) == 0x24C);
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 24);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiUpdateOrder) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bModifierActive) == 20);

#endif
