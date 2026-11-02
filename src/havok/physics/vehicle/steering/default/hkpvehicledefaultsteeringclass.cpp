
// src/havok/physics/vehicle/steering/default/hkpvehicledefaultsteeringclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/steering/default/hkpvehicledefaultsteeringclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dfee20_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};

struct S_00dfee20_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dfee20_Allocator* unk10;
    static S_00dfee20_Router& FUN_00c85750();
    S_00dfee20_Allocator& heap()
    {
        return *unk10;
    }
};

struct S_00dfee20_Array
{
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(S_00dfee20_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned char));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00dfee20_Array() throw()
    {
        _clearAndDeallocate(S_00dfee20_Router::FUN_00c85750().heap());
    }
};

struct S_00dfee20_Base
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00dfee20_Base();
    virtual ~S_00dfee20_Base() throw()
    {}
    static void operator delete(void* p)
    {
        S_00dfee20_Base* b = static_cast<S_00dfee20_Base*>(p);
        S_00dfee20_Router::FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct __declspec(novtable) S_00dfee20 : S_00dfee20_Base
{
    int unk8;
    int unkC;
    S_00dfee20_Array unk10;

    virtual ~S_00dfee20() throw()
    {}
    S_00dfee20* DestroyAndMaybeFree(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object via operator delete; returns this.
// @fnv 0x00dfee20
S_00dfee20* S_00dfee20::DestroyAndMaybeFree(unsigned int flags)
{
    this->S_00dfee20::~S_00dfee20();
    if (flags & 1)
        operator delete(this);
    return this;
}
