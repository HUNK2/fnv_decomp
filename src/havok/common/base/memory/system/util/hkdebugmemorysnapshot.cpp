
// src/havok/common/base/memory/system/util/hkdebugmemorysnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/util/hkdebugmemorysnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryBlock
{
    unsigned int m_uiSize;
};
struct MemoryBlockList
{
    hkMemoryBlock* m_pBlocks;
    unsigned int m_uiBlockCount;
    unsigned int m_uiBlockCapacity;
    void Sort();
    void FUN_00dd7090(MemoryBlockList& other);
};
// @fnv 0x00dd7090
void MemoryBlockList::FUN_00dd7090(MemoryBlockList& other)
{
    Sort();
    other.Sort();
    hkMemoryBlock* a = m_pBlocks;
    hkMemoryBlock* aEnd = a + m_uiBlockCapacity;
    hkMemoryBlock* b = other.m_pBlocks;
    hkMemoryBlock* pBlockBEnd = b + other.m_uiBlockCapacity;
    while (a < aEnd && b < pBlockBEnd)
    {
        if (a->m_uiSize == b->m_uiSize)
        {
            a->m_uiSize = 0;
            ++a;
            ++b;
        }
        else if (a->m_uiSize < b->m_uiSize)
            ++a;
        else
            ++b;
    }
}

class hkMemoryAllocatorDD6E
{
  public:
    virtual ~hkMemoryAllocatorDD6E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD6E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDD6E* m_pStreamAllocator;
    hkMemoryAllocatorDD6E* m_pSolver;
    hkMemoryAllocatorDD6E& solver()
    {
        return *m_pSolver;
    }
};

namespace hkRouterDD6E {
extern "C" hkMemoryRouterDD6E& __cdecl FUN_00c85750() throw();
}

template <typename T> inline void hkDeallocateChunkDD6E(T* p, int n)
{
    hkRouterDD6E::FUN_00c85750().solver().ReleaseBlock(p, n * sizeof(T));
}

struct hkEntryDD6E
{
    int unk00[18];
};

class hkBufferDD6E
{
  public:
    int* m_ppIndices;
    hkEntryDD6E* m_entries;
    int m_pRayCursor;

    void FreeBuffers();
};

// Deallocates the two arrays when the first pointer is set, then nulls both pointers and the count.
// @fnv 0x00dd6ec0
void hkBufferDD6E::FreeBuffers()
{
    if (m_ppIndices)
    {
        hkDeallocateChunkDD6E(m_ppIndices, m_pRayCursor);
        hkDeallocateChunkDD6E(m_entries, m_pRayCursor);
    }
    m_ppIndices = 0;
    m_entries = 0;
    m_pRayCursor = 0;
}

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkMemoryAllocatorQ* m_pDebugAllocator;
    hkMemoryAllocatorQ& debug()
    {
        return *m_pDebugAllocator;
    }
};

hkMemoryRouterQ* __cdecl FUN_00c85750();

template <typename T> inline T* hkAllocateDebug(int n)
{
    return (T*)FUN_00c85750()->debug().AllocateMemoryBlock(n * sizeof(T));
}

template <typename T> inline void hkDeallocateDebug(T* p, int n)
{
    FUN_00c85750()->debug().ReleaseBlock(p, n * sizeof(T));
}

typedef unsigned int hkSnapshotAddress;

bool __cdecl LessThan(const hkSnapshotAddress* a, const hkSnapshotAddress* b);
void __cdecl FUN_00dd7d00(const hkSnapshotAddress** p, int lo, int hi,
                          bool(__cdecl* cmp)(const hkSnapshotAddress*, const hkSnapshotAddress*));

inline void hkQuickSortQ(const hkSnapshotAddress** p, int size,
                         bool(__cdecl* cmp)(const hkSnapshotAddress*, const hkSnapshotAddress*))
{
    if (size > 1)
    {
        FUN_00dd7d00(p, 0, size - 1, cmp);
    }
}

struct hkSnapshotInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
};

struct hkDebugMemorySnapshotQ
{
    hkSnapshotAddress* m_pAddressList;
    hkSnapshotInfo* m_info;
    int m_iElementCount;

    void Sort();
};

// @fnv 0x00dd6f20
void hkDebugMemorySnapshotQ::Sort()
{
    if (m_iElementCount > 1)
    {
        const hkSnapshotAddress** sorted = hkAllocateDebug<const hkSnapshotAddress*>(m_iElementCount);
        for (int i = 0; i < m_iElementCount; i++)
        {
            sorted[i] = &m_pAddressList[i];
        }
        hkQuickSortQ(sorted, m_iElementCount, LessThan);

        hkSnapshotAddress* pointers = hkAllocateDebug<hkSnapshotAddress>(m_iElementCount);
        hkSnapshotInfo* info = hkAllocateDebug<hkSnapshotInfo>(m_iElementCount);
        for (int i = 0; i < m_iElementCount; i++)
        {
            pointers[i] = *sorted[i];
            info[i] = m_info[sorted[i] - m_pAddressList];
        }

        hkDeallocateDebug(sorted, m_iElementCount);
        hkDeallocateDebug(m_pAddressList, m_iElementCount);
        hkDeallocateDebug(m_info, m_iElementCount);
        m_pAddressList = pointers;
        m_info = info;
    }
}
