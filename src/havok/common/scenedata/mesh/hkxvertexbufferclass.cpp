
// src/havok/common/scenedata/mesh/hkxvertexbufferclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexbufferclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DFD680Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DFD680MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DFD680Allocator* m_pStreamAllocator;

    DFD680Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DFD680MemoryRouter& __cdecl FUN_00c85750();

template <class T> struct DFD680Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _clearAndDeallocate(DFD680Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(FUN_00c85750().heap());
    }
};

struct DFD680Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DFD680MeshData
{
    DFD680Array<DFD680Vector4> m_kVertices;
    DFD680Array<int> m_kIndices32;
    DFD680Array<int> m_kMaterials;
    DFD680Array<unsigned short> m_kIndices16;
    DFD680Array<unsigned char> m_flags;

    void FUN_00dfd680();
};

// Clears and deallocates all five arrays of the mesh data in reverse order.
// @fnv 0x00dfd680
void DFD680MeshData::FUN_00dfd680()
{
    m_flags.ClearAndRelease();
    m_kIndices16.ClearAndRelease();
    m_kMaterials.ClearAndRelease();
    m_kIndices32.ClearAndRelease();
    m_kVertices.ClearAndRelease();
}
