// gamebryo2.2/corelibs/niparticle/nipsyscollider_decls.h: declares NiObject, NiBinaryStream, NiPSysCollider, CloningProcess
#ifndef FNV_NIPSYSCOLLIDER_DECLS_H
#define FNV_NIPSYSCOLLIDER_DECLS_H

#include "NiRefObject.h"
class NiStream;
class CloningProcess;
#define FNV_NIOBJECT_H
#pragma pack(push, 4)
class NiObject : public NiRefObject
{
  public:
    virtual void GetType();
    virtual void GetNiNode();
    virtual void GetFadeNode();
    virtual void GetMultiBoundNode();
    virtual void GetNiGeometry();
    virtual void GetTriBasedGeom();
    virtual void GetTriStrips();
    virtual void GetTriShape();
    virtual void GetSegmentedTriShape();
    virtual void GetResizableTriShape();
    virtual void GetNiParticles();
    virtual void GetNiLines();
    virtual void GetCollisionObject();
    virtual void GetBlendCollisionObject();
    virtual void GetRigidBody();
    virtual void GetLimitedHingeConstraint();
    virtual void Clone();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual void RegisterStreamables();
    virtual void SaveBinary();
    virtual void Compare();
    virtual void GetViewerStrings();
    virtual void AddViewerStrings();
    virtual void ProcessClone(CloningProcess&);
};
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    inline unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, buffer, bytes, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};
#pragma pack(pop)
#include "nipsyscollider_stream.h"
#include "NiPoint3.h"
class NiPSysSpawnModifier;
class NiPSysColliderManager;
#pragma pack(push, 4)
class NiPSysCollider : public NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    virtual void ProcessClone(CloningProcess&);
    virtual void LinkObject(NiStream&);
    float m_fBounceFactor;
    bool m_bSpawnOnCollision;
    bool m_bDieOnCollision;
    NiPSysSpawnModifier* m_pSpawnModifier;
    NiPoint3 m_kCollisionPosition;
    float m_fSpawnRate;
    NiPSysColliderManager* m_pColliderManager;
    NiPointer<NiPSysCollider> m_spNextController;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiObject) == 8);
FNV_STATIC_ASSERT(sizeof(NiPSysCollider) == 44);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_spNextController) == 40);
class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};
#pragma pack(push, 4)
class CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    inline bool GetClone(NiObject* original, NiObject*& clone)
    {
        // The PC linker folds this pointer-map lookup with the canonical
        // string-pointer-map lookup; preserve its bound external symbol.
        return reinterpret_cast<NiTStringPointerMap<ShaderBufferRecord*>*>(m_pCloneMap)
            ->GetAt(reinterpret_cast<const char*>(original), reinterpret_cast<ShaderBufferRecord*&>(clone));
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CloningProcess) == 16);
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &size, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*stream.m_pUnderlyingStream, &value, 1);
}
#endif
