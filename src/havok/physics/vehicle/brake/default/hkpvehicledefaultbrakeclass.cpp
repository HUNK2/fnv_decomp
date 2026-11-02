
// src/havok/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dfc080_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00dfc080_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dfc080_Allocator* m_pStreamAllocator;
    S_00dfc080_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00dfc080_Router* FUN_00c85750();

struct S_00dfc080_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    virtual ~S_00dfc080_RefObj() throw()
    {}
    static void operator delete(void* p, size_t)
    {
        S_00dfc080_RefObj* b = static_cast<S_00dfc080_RefObj*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct S_00dfc080_Elem
{
    int unk0;
    int unk4;
    int unk8;
};

template <class T> struct S_00dfc080_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void _clearAndDeallocate(S_00dfc080_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00dfc080_Array() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

struct __declspec(novtable) S_00dfc080 : S_00dfc080_RefObj
{
    S_00dfc080_Array<S_00dfc080_Elem> m_ppData;
    virtual ~S_00dfc080() throw()
    {}
    S_00dfc080* DestroyAndFree(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object; returns this.
// @fnv 0x00dfc080
S_00dfc080* S_00dfc080::DestroyAndFree(unsigned int flags)
{
    this->S_00dfc080::~S_00dfc080();
    if (flags & 1)
        operator delete(this, sizeof(S_00dfc080));
    return this;
}
