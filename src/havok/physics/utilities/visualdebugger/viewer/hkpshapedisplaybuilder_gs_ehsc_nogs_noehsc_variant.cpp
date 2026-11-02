
// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddfcd0_Router* FUN_00c85750();
struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};
S_00ddfcd0_RefObj* FUN_00ddfcd0();
