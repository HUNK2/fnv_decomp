// gamebryo2.2/corelibs/nimain/nidynamiceffect_decls.h: declares NiBinaryStream, NiAVObject
#ifndef FNV_NIDYNAMICEFFECT_DECLS_H
#define FNV_NIDYNAMICEFFECT_DECLS_H

#include "NiObjectNET.h"
#include "NiPoint3.h"

#include "nidynamiceffect_stream.h"
class NiCollisionObject;
class FourComponentFloatVector;
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* data, unsigned int size)
    {
        unsigned int componentSizes[1] = {size};
        return BinaryRead(data, size, componentSizes, 1);
    }
    unsigned int BinaryRead(void* data, unsigned int size, unsigned int* componentSizes, unsigned int components)
    {
        unsigned int read = m_pfnRead(this, data, size, componentSizes, components);
        m_uiStreamFlags += read;
        return read;
    }
};
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value, sizeof(T));
}
class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];
    void Lock(const char* name);
    FNV_FORCEINLINE void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
};
template <class T> class PoolMemoryAllocator : public PoolAllocatorBase<T>
{
  public:
    static void CreateFreeMem();
};
inline NiTListItem<NiNode*>* NiDynamicEffectNewListItem()
{
    typedef PoolAllocatorBase<unsigned int> Pool;
    Pool::ms_kPoolState.Lock(0);
    Pool::LinkedListEntry* item = Pool::ms_pFreeList;
    if (!item)
    {
        PoolMemoryAllocator<unsigned int>::CreateFreeMem();
        item = Pool::ms_pFreeList;
    }
    Pool::ms_pFreeList = item->m_pkNext;
    item->m_element = 0;
    item->m_pkNext = 0;
    item->m_pUserData = 0;
    Pool::ms_kPoolState.Unlock();
    return reinterpret_cast<NiTListItem<NiNode*>*>(item);
}
struct NiDynamicEffectTransform
{
    float m_kOrientation[9];
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiAVObject();
    virtual ~NiAVObject();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiDynamicEffectTransform m_kLocalTransform;
    NiDynamicEffectTransform m_kWorldSpaceTransform;
};
extern volatile long DAT_011a9b58;
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
  public:
    NiTPointerList()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
};
class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    bool m_bEffectEnabled;
    unsigned char m_ucEffectCategory;
    int m_iIndex;
    unsigned int m_uiEffectPushCount;
    unsigned int m_uiRevID;
    NiTPointerList<NiNode*> m_kEffectTargetNodes;
    NiTPointerList<NiNode*> m_kAffectedNodes;
};
FNV_STATIC_ASSERT(sizeof(NiAVObject) == 0x9c);
FNV_STATIC_ASSERT(offsetof(NiDynamicEffect, m_bEffectEnabled) == 0x9c);
FNV_STATIC_ASSERT(offsetof(NiDynamicEffect, m_kAffectedNodes) == 0xb8);
#endif
