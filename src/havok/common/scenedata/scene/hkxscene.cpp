
// src/havok/common/scenedata/scene/hkxscene.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/scene/hkxscene.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxScene.h"

struct hkMalleableContactNormal
{
    void removeReference();
};
typedef hkMalleableContactNormal Ref;
struct Alloc
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotC();
    virtual void freeBlock(void*, int);
};
struct Router
{
    int unk00, unk04, unk08, unk0c;
    Alloc* unk10;
};
void* __cdecl FUN_00c85750();
struct FUN_00cb0c00_class
{
    char* value;
    void FUN_00cb0c00();
};
typedef FUN_00cb0c00_class String;
extern int DAT_010e99d8, DAT_0102e388;
struct Array
{
    Ref** data;
    int size;
    int capacity;
    __forceinline void clear()
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = data;
        int n = size;
        int zero = 0;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        size = zero;
        if (capacity >= 0)
            allocator->freeBlock(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
struct Root
{
    Ref* ptr;
    __forceinline ~Root()
    {
        if (ptr)
            ptr->removeReference();
        ptr = 0;
    }
};
struct Scene
{
    void* unk00;
    int unk04;
    String unk08, unk0c;
    float unk10;
    Root unk14;
    Array unk18, unk24, unk30, unk3c, unk48, unk54, unk60, unk6c;
    void ClearScene();
};
// @fnv 0x00e4a750
void Scene::ClearScene()
{
    unk00 = &DAT_010e99d8;
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk6c.data;
        int n = unk6c.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk6c.size = 0;
        if (!(unk6c.capacity & 0x80000000))
            allocator->freeBlock(unk6c.data, (unk6c.capacity & 0x3fffffff) * 4);
        unk6c.data = 0;
        unk6c.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk60.data;
        int n = unk60.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk60.size = 0;
        if (!(unk60.capacity & 0x80000000))
            allocator->freeBlock(unk60.data, (unk60.capacity & 0x3fffffff) * 4);
        unk60.data = 0;
        unk60.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk54.data;
        int n = unk54.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk54.size = 0;
        if (!(unk54.capacity & 0x80000000))
            allocator->freeBlock(unk54.data, (unk54.capacity & 0x3fffffff) * 4);
        unk54.data = 0;
        unk54.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk48.data;
        int n = unk48.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk48.size = 0;
        if (!(unk48.capacity & 0x80000000))
            allocator->freeBlock(unk48.data, (unk48.capacity & 0x3fffffff) * 4);
        unk48.data = 0;
        unk48.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk3c.data;
        int n = unk3c.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk3c.size = 0;
        if (!(unk3c.capacity & 0x80000000))
            allocator->freeBlock(unk3c.data, (unk3c.capacity & 0x3fffffff) * 4);
        unk3c.data = 0;
        unk3c.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk30.data;
        int n = unk30.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk30.size = 0;
        if (!(unk30.capacity & 0x80000000))
            allocator->freeBlock(unk30.data, (unk30.capacity & 0x3fffffff) * 4);
        unk30.data = 0;
        unk30.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk24.data;
        int n = unk24.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk24.size = 0;
        if (!(unk24.capacity & 0x80000000))
            allocator->freeBlock(unk24.data, (unk24.capacity & 0x3fffffff) * 4);
        unk24.data = 0;
        unk24.capacity = 0x80000000;
    }
    {
        Alloc* allocator = ((Router*)FUN_00c85750())->unk10;
        Ref** p = unk18.data;
        int n = unk18.size;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk18.size = 0;
        if (!(unk18.capacity & 0x80000000))
            allocator->freeBlock(unk18.data, (unk18.capacity & 0x3fffffff) * 4);
        unk18.data = 0;
        unk18.capacity = 0x80000000;
    }
    unk14.~Root();
    unk0c.FUN_00cb0c00();
    unk08.FUN_00cb0c00();
    unk00 = &DAT_0102e388;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4E4A6
{
    __m128 m_vComponents;

    hkVector4E4A6()
    {}
    hkVector4E4A6(const hkVector4E4A6& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4E4A6& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
};

struct hkMatrix3E4A6
{
    hkVector4E4A6 m_kColumn0;
    hkVector4E4A6 m_kColumn1;
    hkVector4E4A6 m_kColumn2;
};

const hkMatrix3E4A6& FUN_00cd4b50();

struct FUN_00cb0a60
{
    FUN_00cb0a60();

    const char* m_pcText;
};

template <class T> struct hkArrayE4A6
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE4A6() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectE4A6
{
  public:
    virtual ~hkBaseObjectE4A6() throw();
};

class hkReferencedObjectE4A6 : public hkBaseObjectE4A6
{
  public:
    hkReferencedObjectE4A6() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE4A6() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e4a6a0 : public hkReferencedObjectE4A6
{
  public:
    FUN_00e4a6a0() throw();
    virtual ~FUN_00e4a6a0() throw();

    FUN_00cb0a60 m_kSceneName;
    FUN_00cb0a60 m_kSceneFileName;
    float m_fNumFrames;
    void* m_pAabbRootNode;
    hkArrayE4A6<void*> m_kSelectionSets;
    hkArrayE4A6<void*> m_kCameras;
    hkArrayE4A6<void*> m_ppLights;
    hkArrayE4A6<void*> m_kMeshList;
    hkArrayE4A6<void*> m_kMaterials;
    hkArrayE4A6<void*> m_kInplaceTextures;
    hkArrayE4A6<void*> m_kExternalTextures;
    hkArrayE4A6<void*> m_kSkinBindings;
    unsigned int unk78, unk7C;
    hkMatrix3E4A6 m_kAppliedTransform;
};

// Initializes m_fNumFrames and m_pAabbRootNode, then copies the matrix returned by FUN_00cd4b50 into m_kAppliedTransform.
// @fnv 0x00e4a6a0
FUN_00e4a6a0::FUN_00e4a6a0() throw() : m_fNumFrames(0.0f), m_pAabbRootNode(0)
{
    m_kAppliedTransform = FUN_00cd4b50();
}

extern int DAT_010e929c;
extern int DAT_0102e388;

struct Heap_e4a4
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct Router_e4a4
{
    int unk00, unk04, unk08, unk0C;
    Heap_e4a4* m_pStreamAllocator;
    Heap_e4a4& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_e4a4& __cdecl FUN_00c85750() throw();
};

template <class T> struct hkArray_e4a4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void ClearAndRelease() throw()
    {
        Heap_e4a4& heap = Router_e4a4::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkReferencedObject_e4a4
{
    void FUN_00c905b0() throw();
};

struct Entry_e4a4
{
    hkReferencedObject_e4a4* m_pCollisionShape;
    hkReferencedObject_e4a4* m_iMaterialIndex;
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    ~Entry_e4a4() throw()
    {
        m_pCollisionShape->FUN_00c905b0();
        if (m_iMaterialIndex)
            m_iMaterialIndex->FUN_00c905b0();
    }
};

struct Name_e4a4
{
    int unk00;
    void FUN_00cb0c00() throw();
};

struct Mesh_e4a4
{
    int* m_vtbl;
    int unk04;
    hkArray_e4a4<Entry_e4a4> m_entries;
    hkArray_e4a4<short> m_ppIndices;
    hkArray_e4a4<int> m_iSlotIds;
    Name_e4a4 m_name;
    void FUN_00e4a460();
};

// Calls each entry destructor, invokes FUN_00cb0c00 on m_name, releases the slot ID, index, and entry arrays, then updates m_vtbl.
// @fnv 0x00e4a460
void Mesh_e4a4::FUN_00e4a460()
{
    m_vtbl = &DAT_010e929c;
    int n = m_entries.GetLogicalSize();
    for (int i = 0; i < n; i++)
        m_entries[i].~Entry_e4a4();
    m_name.FUN_00cb0c00();
    m_iSlotIds.ClearAndRelease();
    m_ppIndices.ClearAndRelease();
    m_entries.ClearAndRelease();
    m_vtbl = &DAT_0102e388;
}
