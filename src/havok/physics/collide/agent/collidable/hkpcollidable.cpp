
// src/havok/physics/collide/agent/collidable/hkpcollidable.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/collidable/hkpcollidable.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCollidable.h"

struct FUN_00d01a60
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    short m_i;
    short m_iUnknownValue;
    int m_k;
    int m_l;
    FUN_00d01a60();
};
// @fnv 0x00d01a60
FUN_00d01a60::FUN_00d01a60()
{
    m_i = 0;
    m_iUnknownValue = 0;
    m_k = 0;
    m_l = 0;
    m_kPointA = 1;
    m_usTrailingValue = 0;
}

class hkMemoryAllocatorD01A
{
  public:
    virtual ~hkMemoryAllocatorD01A() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD01A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD01A* m_pStreamAllocator;
    hkMemoryAllocatorD01A& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD01A {
extern "C" hkMemoryRouterD01A& __cdecl FUN_00c85750() throw();
}

template <typename T> inline void hkDeallocateChunkD01A(T* p, int n)
{
    hkRouterD01A::FUN_00c85750().heap().ReleaseBlock(p, n * sizeof(T));
}

struct hkEntryD01A
{
    int unk00[8];
};

class hkMapD01A
{
  public:
    int unk00[8];
    unsigned short m_iElementCount;
    unsigned short m_pRayCursor;
    hkEntryD01A* m_entries;
    int* m_bits;

    void FreeStorage();
};

// @fnv 0x00d01a80
void hkMapD01A::FreeStorage()
{
    hkDeallocateChunkD01A(m_entries, m_pRayCursor);
    hkDeallocateChunkD01A(m_bits, (m_pRayCursor + 3) & ~3);
    m_entries = 0;
    m_bits = 0;
    m_iElementCount = 0;
    m_pRayCursor = 0;
}

struct FUN_00d01ae0_shell : hkMapD01A
{
    void FUN_00d01ae0(unsigned int n);
};

// @fnv 0x00d01ae0
void FUN_00d01ae0_shell::FUN_00d01ae0(unsigned int n)
{
    m_iElementCount = (unsigned short)n;
    m_pRayCursor = (unsigned short)n;
    if (n)
    {
        unsigned int bytes = m_iElementCount;
        hkMemoryAllocatorD01A& allocator = hkRouterD01A::FUN_00c85750().heap();
        m_entries = static_cast<hkEntryD01A*>(allocator.AllocateMemoryBlock(bytes << 5));
        unsigned int count = ((unsigned int)m_pRayCursor + 3) & ~3u;
        hkMemoryAllocatorD01A& b = hkRouterD01A::FUN_00c85750().heap();
        m_bits = static_cast<int*>(b.AllocateMemoryBlock(count * 4));
    }
}
