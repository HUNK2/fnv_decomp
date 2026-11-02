
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpmoppagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpmoppagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
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

extern int DAT_010ce8f4;
extern int DAT_0102e388;

struct FUN_00d2f380_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void DestroyArray();
};

// Resets the object's vtable pointers, frees m_pData through the allocator when the capacity flag is clear, then clears the data pointer and capacity.
// @fnv 0x00d2f380
void FUN_00d2f380_cls::DestroyArray()
{
    m_vptr00 = (int)&DAT_010ce8f4;
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapBits = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapBits & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (uCapBits & 0x3fffffffu) * 12);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
}
