
// src/havok/common/scenedata/attributes/hkxsparselyanimatedenumclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxsparselyanimatedenumclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dfdb90_Allocator
{
    virtual ~S_00dfdb90_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00dfdb90_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00dfdb90_Allocator* m_pStreamAllocator;
    S_00dfdb90_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dfdb90_Router* FUN_00c85750();
template <class T> struct S_00dfdb90_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void _clearAndDeallocate(S_00dfdb90_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00dfdb90_Array() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00dfdb90_Base
{
    virtual ~S_00dfdb90_Base() throw()
    {}
    int unk04;
};
struct __declspec(novtable) FUN_00dfdb90 : S_00dfdb90_Base
{
    S_00dfdb90_Array<int> m_kPointA;
    S_00dfdb90_Array<int> m_kPointB;
    virtual ~FUN_00dfdb90() throw();
};
// Destructor for the container: implicitly destroys the two int arrays, which deallocate their buffers through the heap allocator.
// @fnv 0x00dfdb90
FUN_00dfdb90::~FUN_00dfdb90() throw()
{}

namespace fnv_00dfdc10 {
struct Heap
{
    virtual void a();
    virtual void b();
    virtual void free(void*, unsigned short);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Heap* unk10;
};
struct Helper
{
    void FUN_00dfdb90();
};
struct Owner
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Owner* DestroyOwner(unsigned int flags);
};
extern Holder* FUN_00c85750();
// Calls FUN_00dfdb90 on this, and if flags has bit 0 set, frees this through the holder's heap using unk04; returns this.
// @fnv 0x00dfdc10
Owner* Owner::DestroyOwner(unsigned int flags)
{
    ((Helper*)this)->FUN_00dfdb90();
    if (flags & 1)
    {
        Holder* holder = FUN_00c85750();
        holder->unk10->free(this, unk04);
    }
    return this;
}
}  // namespace fnv_00dfdc10

namespace fnv_00dfdc40 {
struct S_00dfdc40_Allocator
{
    virtual ~S_00dfdc40_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00dfdc40_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00dfdc40_Allocator* m_pStreamAllocator;
    S_00dfdc40_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dfdc40_Router* FUN_00c85750();
template <class T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
template <class T> struct S_00dfdc40_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void _clearAndDeallocate(S_00dfdc40_Allocator& alloc)
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00dfdc40_Array() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00dfdc40_Str
{
    int unk00;
    ~S_00dfdc40_Str() throw();
};
struct S_00dfdc40_Elem
{
    int unk00;
    S_00dfdc40_Str unk04;
};
struct S_00dfdc40_Base
{
    virtual ~S_00dfdc40_Base() throw()
    {}
    int unk04;
};
struct __declspec(novtable) FUN_00dfdc40 : S_00dfdc40_Base
{
    S_00dfdc40_Array<S_00dfdc40_Elem> m_ppData;
    virtual ~FUN_00dfdc40() throw();
};
// Destructor of FUN_00dfdc40; the member array's destructor runs implicitly after this empty body.
// @fnv 0x00dfdc40
FUN_00dfdc40::~FUN_00dfdc40() throw()
{}
}  // namespace fnv_00dfdc40

namespace fnv_00dfdcb0 {
struct Ref
{
    void removeReference();
};
struct Heap
{
    virtual void a();
    virtual void b();
    virtual void free(void*, unsigned short);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Heap* unk10;
};
struct Helper
{
    void FUN_00dfdb90();
};
struct Owner
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Ref* unk20;
    Owner* Destroy(unsigned int flags);
};
extern Holder* FUN_00c85750();
// Releases the reference at unk20, calls FUN_00dfdb90, and if flags bit 0 is set frees this through the holder's heap using unk04.
// @fnv 0x00dfdcb0
Owner* Owner::Destroy(unsigned int flags)
{
    if (unk20)
        unk20->removeReference();
    unk20 = 0;
    ((Helper*)this)->FUN_00dfdb90();
    if (flags & 1)
    {
        Holder* holder = FUN_00c85750();
        holder->unk10->free(this, unk04);
    }
    return this;
}
}  // namespace fnv_00dfdcb0

namespace fnv_00dfdcf0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00dfdcf0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00dfdc40();

    FUN_00dfdcf0_cls* FUN_00dfdcf0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00dfdc40, and if acFlags has bit 0 set, frees this via the AudioAllocator from FUN_00c85750, then returns this.
// @fnv 0x00dfdcf0
FUN_00dfdcf0_cls* FUN_00dfdcf0_cls::FUN_00dfdcf0(unsigned char acFlags)
{
    FUN_00dfdc40();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00dfdcf0
