
// src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkFreeListNode
{
    hkFreeListNode* next;
    int a;
    int b;
    int size;
};

// @fnv 0x00dd7280
int __cdecl SumFreeListSizes(hkFreeListNode* node)
{
    int total = 0;
    while (node)
    {
        total += node->size;
        node = node->next;
    }
    return total;
}

struct PointerChainNode
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void AttachPointer(void*);
    void FUN_00dd7360();
};
// @fnv 0x00dd7360
void PointerChainNode::FUN_00dd7360()
{
    AttachPointer(m_pFreeBlocks);
    m_pFreeBlocks = 0;
}

// @fnv 0x00dd73d0
void* FUN_00dd73d0(void* p, unsigned int n)
{
    if (n <= 0x10)
        return (char*)p + 0x10;
    return (char*)p + n;
}

namespace fnv_00dd7510 {
struct PointerChainNode
{
    void FUN_00dd7200();
    void FUN_00dd74b0(int, int, int, int);
    void FUN_00dd7510(int a, int b, int c, int d);
};

// Calls FUN_00dd7200, then forwards the four int arguments to FUN_00dd74b0.
// @fnv 0x00dd7510
void PointerChainNode::FUN_00dd7510(int a, int b, int c, int d)
{
    FUN_00dd7200();
    FUN_00dd74b0(a, b, c, d);
}
}  // namespace fnv_00dd7510

struct hkFreeListAllocator
{
    virtual void unused1()
    {}
    virtual void unused2()
    {}
    virtual void freeBlock(hkFreeListNode* node)
    {
        (void)node;
    }
};

struct hkFreeListStandin
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    unsigned char m_ucUnknownByte[0x1c];
    int m_field8;
    int m_field9;
    hkFreeListAllocator* m_pThreadAllocator;

    int FreeBlocks(hkFreeListNode* node);
};

// @fnv 0x00dd71c0
int hkFreeListStandin::FreeBlocks(hkFreeListNode* node)
{
    int count = 0;

    while (node)
    {
        m_field9 -= node->size;
        m_field8 -= node->size;

        hkFreeListAllocator* allocator = m_pThreadAllocator;
        hkFreeListNode* next = node->next;

        ++count;
        allocator->freeBlock(node);
        node = next;
    }

    return count;
}

struct FUN_00dd7200_hkFreeList : PointerChainNode
{
    void FUN_00dd7200();
};

// @fnv 0x00dd7200
void FUN_00dd7200_hkFreeList::FUN_00dd7200()
{
    PointerChainNode* p = this;

    p->AttachPointer(p->m_pSecondNode);
    p->m_pSecondNode = 0;
    p->AttachPointer(p->m_pFreeBlocks);
    p->m_pFreeBlocks = 0;
    p->m_data = 0;
    p->m_field5 = 0;
    *(void**)((char*)p + 0x28) = 0;
    *(void**)((char*)p + 0x2c) = 0;
    *(void**)((char*)p + 0x20) = 0;
    *(void**)((char*)p + 0x24) = 0;
    p->m_next = 0;
}

struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    unsigned int m_field8;
    unsigned int m_field9;

    unsigned int FUN_00dd7240();
};

// @fnv 0x00dd7240
unsigned int hkFreeListStandIn::FUN_00dd7240()
{
    unsigned int count = 0;
    hkFreeListNode* node = static_cast<hkFreeListNode*>(m_data);

    while (node != 0)
    {
        ++count;
        node = node->next;
    }

    count += (m_field9 - m_field8) / reinterpret_cast<unsigned int>(m_kBlocks);

    node = static_cast<hkFreeListNode*>(m_pFreeBlocks);
    while (node != 0)
    {
        count += node->size;
        node = node->next;
    }

    return count;
}

namespace fnv_00dd73f0 {
struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    hkFreeListNode* m_pSecondNode;
    hkFreeListNode* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void* m_field8;
    void* m_field9;
    int m_field10;
    int m_field11;

    void ResetFreeList();
};

// @fnv 0x00dd73f0
void hkFreeListStandIn::ResetFreeList()
{
    *(int*)((char*)this + 0x28) = *(int*)((char*)this + 0x2c);

    hkFreeListNode* node = m_pSecondNode;
    if (node != 0)
    {
        m_data = 0;
        while (node->next != 0)
            node = node->next;

        node->next = m_pFreeBlocks;
        m_pFreeBlocks = m_pSecondNode;
        m_pSecondNode = 0;
        m_field8 = 0;
        m_field9 = 0;
        m_next = 0;
    }
}
}  // namespace fnv_00dd73f0

struct hkFreeListFUN_00dd7480 : PointerChainNode
{
    void CollectFreeNodes(hkFreeListNode** blocks, int unused);
};

// Writes every node of the two free lists into the blocks array, following each list's next pointer until null.
// @fnv 0x00dd7480
void hkFreeListFUN_00dd7480::CollectFreeNodes(hkFreeListNode** blocks, int)
{
    hkFreeListNode* node = static_cast<hkFreeListNode*>(m_pSecondNode);
    while (node != 0)
    {
        *blocks++ = node;
        node = node->next;
    }

    node = static_cast<hkFreeListNode*>(m_pFreeBlocks);
    while (node != 0)
    {
        *blocks++ = node;
        node = node->next;
    }
}

struct FreeNode
{
    FreeNode* next;
};
struct FreeBlock
{
    FreeBlock* next;
    unsigned int unk04;
    unsigned int m_pRayStart;
    unsigned int m_uiItemCount;
};
struct HavokBool
{
    unsigned char value;
    HavokBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct FreeAllocator
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual HavokBool TestBlock(FreeBlock* block);
};
struct FreeListCheck
{
    FreeNode* m_freeHead;
    unsigned int m_iFirstIndex;
    unsigned int unk08;
    FreeBlock* m_kBlocks;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_alignment;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    FreeAllocator* m_pThreadAllocator;
    bool* ValidateFreeList(bool* result);
};
// Walks the free list, checking each node's alignment and that it lies inside a block accepted by TestBlock; writes true or false to result.
// @fnv 0x00dd7140
bool* FreeListCheck::ValidateFreeList(bool* result)
{
    FreeNode* pNode = m_freeHead;
    while (pNode != 0)
    {
        if ((reinterpret_cast<unsigned int>(pNode) & (m_alignment - 1)) != 0)
            goto invalid;
        FreeBlock* block = m_kBlocks;
        if (block == 0)
            goto invalid;
        do
        {
            if (!m_pThreadAllocator->TestBlock(block))
                goto invalid;
            unsigned int base = block->m_pRayStart;
            unsigned int addr = reinterpret_cast<unsigned int>(pNode);
            if (addr >= base && addr < base + block->m_uiItemCount * m_iFirstIndex)
            {
                if ((addr - base) % m_iFirstIndex != 0)
                    goto invalid;
                break;
            }
            block = block->next;
        } while (block != 0);
        if (block == 0)
            goto invalid;
        pNode = pNode->next;
    }
    *result = true;
    return result;
invalid:
    *result = false;
    return result;
}

struct hkNodeDD72
{
    hkNodeDD72* m_next;
    int m_iElementCount;
};

class hkCounterDD72
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int count(hkNodeDD72* pNode, int iSize);
};

class hkObjDD72
{
  public:
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
    hkCounterDD72* m_iFirstInteger;

    int SumNodeCounts(hkNodeDD72* pNode);
};

// Walks the linked list from pNode and sums the counter's count for each node, returning the total.
// @fnv 0x00dd72a0
int hkObjDD72::SumNodeCounts(hkNodeDD72* pStartNode)
{
    int iSum = 0;
    for (; pStartNode; pStartNode = pStartNode->m_next)
        iSum += m_iFirstInteger->count(pStartNode, pStartNode->m_iElementCount);
    return iSum;
}

class hkBoolDD72
{
  public:
    hkBoolDD72(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBoolDD72(const hkBoolDD72& o)
    {
        m_cBooleanValue = o.m_cBooleanValue;
    }
    char m_cBooleanValue;
};

typedef void(__cdecl* hkMemoryWalkCallbackDD72)(void* start, int size, hkBoolDD72 allocated, int pool, void* param);

struct hkBlockDD72
{
    hkBlockDD72* m_next;
    int unk04;
    char* m_kRayStart;
    int m_iCapacity;
};

class hkFreeListDD72
{
  public:
    int unk00;
    int m_iFirstIndex;

    void WalkFreeBlocks(hkBlockDD72* block, hkMemoryWalkCallbackDD72 callback, int pool, void* param);
};

// Walks the free list and invokes callback on each element of every block, reporting it as not allocated.
// @fnv 0x00dd72f0
void hkFreeListDD72::WalkFreeBlocks(hkBlockDD72* block, hkMemoryWalkCallbackDD72 callback, int pool, void* param)
{
    for (; block; block = block->m_next)
    {
        char* p = block->m_kRayStart;
        char* end = p + block->m_iCapacity * m_iFirstIndex;
        for (; p < end; p += m_iFirstIndex)
            callback(p, m_iFirstIndex, hkBoolDD72(false), pool, param);
    }
}

struct hkFreeListCallsDD75
{
    static unsigned int __cdecl FUN_00dd73d0(unsigned int uiSize, unsigned int uiAlign);
};

struct hkMemoryAllocatorDD75
{
    virtual void V0();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void V2();
    virtual void V3();
    virtual int GetUsableSize(const void* pObj, int iNumBytes);
};

struct hkFreeListBlockDD75
{
    hkFreeListBlockDD75* m_pkNext;
    int m_iBlockSize;
    char* m_pcStart;
    unsigned int m_uiNumElements;
};

struct hkFreeListDD75
{
    void* m_pkFree;
    unsigned int m_uiFreeCount;
    int m_iUnk08;
    hkFreeListBlockDD75* m_pkActiveBlocks;
    hkFreeListBlockDD75* m_pkFreeBlocks;
    unsigned int m_uiIndexCapacity;
    unsigned int m_uiAlign;
    unsigned int m_uiMaxBlockSize;
    char* m_pcTop;
    char* m_pcBlockEnd;
    int m_iNumFreeElements;
    int m_iTotalNumElements;
    hkMemoryAllocatorDD75* m_pkBlockAllocator;
    void* AllocateElement();
};

// Returns one free element from the free list, reusing a free block or allocating a new block from m_pkBlockAllocator when none is available.
// @fnv 0x00dd7540
void* hkFreeListDD75::AllocateElement()
{
    hkFreeListBlockDD75* pkBlock = m_pkFreeBlocks;
    if (pkBlock)
    {
        m_pkFreeBlocks = pkBlock->m_pkNext;
        m_pcTop = pkBlock->m_pcStart;
        m_pcBlockEnd = pkBlock->m_pcStart + pkBlock->m_uiNumElements * m_uiFreeCount;
        pkBlock->m_pkNext = m_pkActiveBlocks;
        m_pkActiveBlocks = pkBlock;
        m_iNumFreeElements--;
        void* p = m_pcTop;
        m_pcTop += m_uiFreeCount;
        return p;
    }

    if (m_uiIndexCapacity <= 0)
    {
        unsigned int auiCount = 256 / m_uiFreeCount;
        if (auiCount < 1)
            auiCount = 1;
        m_uiIndexCapacity = hkFreeListCallsDD75::FUN_00dd73d0(m_uiFreeCount * auiCount, m_uiAlign);
    }
    else if (m_uiIndexCapacity < m_uiMaxBlockSize)
    {
        unsigned int auiCount = m_uiIndexCapacity / m_uiFreeCount;
        if (auiCount < 8)
            auiCount = 8;
        else
            auiCount += auiCount >> 1;
        m_uiIndexCapacity = hkFreeListCallsDD75::FUN_00dd73d0(m_uiFreeCount * auiCount, m_uiAlign);
    }

    pkBlock = (hkFreeListBlockDD75*)m_pkBlockAllocator->AllocateMemoryBlock(m_uiIndexCapacity);
    if (!pkBlock)
        return 0;
    int iAllocatedSize = m_pkBlockAllocator->GetUsableSize(pkBlock, m_uiIndexCapacity);
    pkBlock->m_iBlockSize = iAllocatedSize;
    char* pcStart = (char*)(((unsigned int)(pkBlock + 1) + m_uiAlign - 1) & ~(m_uiAlign - 1));
    pkBlock->m_pcStart = pcStart;
    pkBlock->m_uiNumElements = (unsigned int)((char*)pkBlock + iAllocatedSize - pkBlock->m_pcStart) / m_uiFreeCount;
    m_pcTop = pkBlock->m_pcStart;
    m_pcBlockEnd = pkBlock->m_pcStart + pkBlock->m_uiNumElements * m_uiFreeCount;
    pkBlock->m_pkNext = m_pkActiveBlocks;
    m_pkActiveBlocks = pkBlock;
    m_iTotalNumElements += pkBlock->m_uiNumElements;
    m_iNumFreeElements += pkBlock->m_uiNumElements - 1;
    void* p = m_pcTop;
    m_pcTop += m_uiFreeCount;
    return p;
}

struct hkStackDD7B
{
    char* m_pcCur;
};
extern "C" hkStackDD7B* __cdecl FUN_00c85750();

template <class T> inline T* hkAllocateStackDD7B(int iCount)
{
    hkStackDD7B* pkStack = FUN_00c85750();
    T* pResult = (T*)pkStack->m_pcCur;
    pkStack->m_pcCur = (char*)pResult + ((iCount * sizeof(T) + 127) & ~127);
    return pResult;
}

template <class T> inline void hkDeallocateStackDD7B(T* p)
{
    FUN_00c85750()->m_pcCur = (char*)p;
}

bool __cdecl CompareLessThan(const hkFreeListNode* pkA, const hkFreeListNode* pkB);
void __cdecl FUN_00dd7d00(hkFreeListNode** ppArray, int iLow, int iHigh,
                          bool(__cdecl* pfnLess)(const hkFreeListNode*, const hkFreeListNode*));

struct hkBlockDD7B
{
    int m_iUnk00;
    int m_iUnk04;
    char* m_pcStart;
    int m_iNumElements;
};

struct hkFreeListDD7B
{
    hkFreeListNode* m_pkFree;
    unsigned int m_uiFreeCount;
    char m_acUnk08[0x18];
    char* m_pcTop;
    char* m_pcBlockEnd;
    int FUN_00dd7b40(hkBlockDD7B* pkBlock);
};

// Removes free-list nodes that fall inside pkBlock's range, re-sorts them and relinks them into m_pkFree; returns 1 if the block is fully free, else 0.
// @fnv 0x00dd7b40
int hkFreeListDD7B::FUN_00dd7b40(hkBlockDD7B* pkBlock)
{
    hkFreeListNode** ppElems = hkAllocateStackDD7B<hkFreeListNode*>(pkBlock->m_iNumElements);

    int iNumFound = 0;
    char* pcStart = pkBlock->m_pcStart;
    char* pcEnd = pcStart + pkBlock->m_iNumElements * m_uiFreeCount;
    hkFreeListNode* pkPrev = (hkFreeListNode*)this;
    for (hkFreeListNode* pkNode = m_pkFree; pkNode; pkNode = pkNode->next)
    {
        if ((char*)pkNode >= pcStart && (char*)pkNode < pcEnd)
        {
            ppElems[iNumFound++] = pkNode;
            pkPrev->next = pkNode->next;
        }
        else
            pkPrev = pkNode;
    }

    if (m_pcTop >= pcStart && m_pcTop < pcEnd)
    {
        if (iNumFound + (m_pcBlockEnd - m_pcTop) / m_uiFreeCount == pkBlock->m_iNumElements)
        {
            m_pcTop = 0;
            m_pcBlockEnd = 0;
            hkDeallocateStackDD7B(ppElems);
            return 1;
        }
    }
    else if (iNumFound == pkBlock->m_iNumElements)
    {
        hkDeallocateStackDD7B(ppElems);
        return 1;
    }

    if (iNumFound > 0)
    {
        if (iNumFound > 1)
            FUN_00dd7d00(ppElems, 0, iNumFound - 1, CompareLessThan);
        hkFreeListNode* pkLast = ppElems[0];
        for (int i = 1; i < iNumFound; i++)
        {
            hkFreeListNode* pkNext = ppElems[i];
            pkLast->next = pkNext;
            pkLast = pkNext;
        }
        ppElems[iNumFound - 1]->next = m_pkFree;
        m_pkFree = ppElems[0];
    }
    hkDeallocateStackDD7B(ppElems);
    return 0;
}

struct hkBoolDD7C
{
    char m_cBooleanValue;
    hkBoolDD7C(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

struct hkFreeListBlockDD7C
{
    hkFreeListBlockDD7C* m_next;
};

class hkFreeListDD7C
{
  public:
    int unk00;
    int unk04;
    hkFreeListBlockDD7C* m_incrementalBlock;
    hkFreeListBlockDD7C* m_kBlocks;
    hkFreeListBlockDD7C* m_pFreeBlocks;

    int FUN_00dd7b40(hkFreeListBlockDD7C* pkBlock) throw();
    hkBoolDD7C FUN_00dd7c40(int m_iFreeBlockCount, int& iNumBlocksOut) throw();
};

// @fnv 0x00dd7c40
hkBoolDD7C hkFreeListDD7C::FUN_00dd7c40(int iMaxBlocks, int& iNumBlocksOut) throw()
{
    int i = 0;
    for (; i < iMaxBlocks; i++)
    {
        if (m_incrementalBlock)
        {
            hkFreeListBlockDD7C* pkBlock = m_incrementalBlock->m_next;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (FUN_00dd7b40(pkBlock))
            {
                m_incrementalBlock->m_next = pkBlock->m_next;
                pkBlock->m_next = m_pFreeBlocks;
                m_pFreeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
        else
        {
            hkFreeListBlockDD7C* pkBlock = m_kBlocks;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (FUN_00dd7b40(pkBlock))
            {
                m_kBlocks = pkBlock->m_next;
                pkBlock->m_next = m_pFreeBlocks;
                m_pFreeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
    }
    iNumBlocksOut = i;
    return m_incrementalBlock == 0;
}

struct B60Link
{
    int unk00;
    int unk04;
};

struct B60Large
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B60State
{
    int current;
    int link;
    int limit;
};

struct B60Owner
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA4;

    void AdvanceState(unsigned char* result, B60State* state);
};

// Advances state->current by the masked link offset; when it reaches the limit, moves to the next link or resets, and writes 1 or 0 to result.
// @fnv 0x00dd8b60
void B60Owner::AdvanceState(unsigned char* result, B60State* state)
{
    int current = state->current;

    if (current == 0)
        goto empty;

    current += (*(int*)(current + 4) & 0xFFFFFFFC);
    state->current = current;

    if (current == state->limit)
    {
        int next = ((B60Link*)state->link)->unk04;

        if (next == (int)((char*)this + 0xA4))
        {
            state->current = 0;
            goto empty;
        }

        state->link = next;
        state->current = ((B60Large*)next)->unk10;
        state->limit = ((B60Large*)next)->unk14 - 0x10;
    }

    *result = 1;
    return;

empty:
    *result = 0;
}

struct hkBlockDD73
{
    hkBlockDD73* m_next;
    unsigned int m_key;
    int unk08;
    int m_iElementCount;
};

class hkBlockAllocDD73
{
  public:
    virtual ~hkBlockAllocDD73();
    virtual void* alloc(int n);
    virtual void free(hkBlockDD73* block);
};

class hkBlockListDD73
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkBlockDD73* m_pFirstNode;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_totalSize;
    int m_usedSize;
    hkBlockAllocDD73* m_alloc;

    void FUN_00dd7380(unsigned int key);
};

// @fnv 0x00dd7380
void hkBlockListDD73::FUN_00dd7380(unsigned int key)
{
    hkBlockDD73** prev = &m_pFirstNode;
    hkBlockDD73* block = m_pFirstNode;
    while (block)
    {
        if (block->m_key <= key)
        {
            hkBlockDD73* next = block->m_next;
            *prev = next;
            m_usedSize -= block->m_iElementCount;
            m_totalSize -= block->m_iElementCount;
            m_alloc->free(block);
            block = next;
        }
        else
        {
            prev = &block->m_next;
            block = block->m_next;
        }
    }
}

struct Info_dd7430
{
    int m_iTotal;
    int m_iSpan;
    int unk08;
    int m_iStart;
    int m_iStartCopy;
    int m_iArrayCapacity;
};
struct FUN_00dd7430_cls
{
    int unk00;
    int m_iArrayCapacity;
    int unk08;
    int m_iB;
    int m_iA;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_iFirst;
    int m_iLast;
    int SumNodeCounts(int iValue);
    void FUN_00dd7430(Info_dd7430* pkInfo);
};
// Fills pkInfo with total node counts, start, span, and array capacity derived from m_iA, m_iB, m_iFirst, and m_iLast.
// @fnv 0x00dd7430
void FUN_00dd7430_cls::FUN_00dd7430(Info_dd7430* pkInfo)
{
    pkInfo->m_iTotal = SumNodeCounts(m_iA) + SumNodeCounts(m_iB);
    int iFirst = m_iFirst;
    int iLast = m_iLast;
    pkInfo->m_iStart = m_iArrayCapacity * iFirst;
    pkInfo->m_iSpan = (iLast - iFirst) * m_iArrayCapacity;
    pkInfo->m_iArrayCapacity = m_iArrayCapacity;
    pkInfo->m_iStartCopy = pkInfo->m_iStart;
}

struct hkFreeListBlockAllocator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

void __cdecl hkFreeList_quickSortRecursive(void** pArr, int d, int h, bool(__cdecl* cmpLess)(const void*, const void*));
bool __cdecl hkFreeList_comparePointers(const void* a, const void* b);

struct hkFreeListGC
{
    struct Element
    {
        Element* m_next;
    };

    struct Block
    {
        Block* m_next;
        int m_unk04;
        char* m_kRayStart;
        int m_iCapacity;
    };

    Element* m_free;
    unsigned int m_iFirstIndex;
    int m_iFreeCount;
    Block* m_kBlocks;
    Block* m_pFreeBlocks;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    char* m_fMinimumV;
    char* m_pSecondString;
    int m_unk28;
    int m_unk2C;
    hkFreeListBlockAllocator* m_blockAllocator;

    int Compact();
};

// Sorts block and element pointers, merges free blocks into m_pFreeBlocks, rebuilds m_kBlocks and m_free lists, and returns the number of freed blocks.
// @fnv 0x00dd7680
int hkFreeListGC::Compact()
{
    if (!m_kBlocks)
    {
        return 0;
    }

    int numBlocks = 0;
    for (Block* block = m_kBlocks; block; block = block->m_next)
    {
        numBlocks++;
    }

    int blocksSize = numBlocks * sizeof(Block*);
    Block** blocks = (Block**)m_blockAllocator->AllocateBufferWithSize(blocksSize);
    if (!blocks)
    {
        return -1;
    }

    if (m_kBlocks)
    {
        Block** dst = blocks;
        for (Block* block = m_kBlocks; block; block = block->m_next)
        {
            *dst++ = block;
        }
    }

    if (numBlocks > 1)
    {
        hkFreeList_quickSortRecursive((void**)blocks, 0, numBlocks - 1, hkFreeList_comparePointers);
    }

    int numElements = int(m_pSecondString - m_fMinimumV) / m_iFirstIndex;
    for (Element* pElement = m_free; pElement; pElement = pElement->m_next)
    {
        numElements++;
    }

    int elementsSize = numElements * sizeof(Element*);
    Element** elements = (Element**)m_blockAllocator->AllocateBufferWithSize(elementsSize);
    if (!elements)
    {
        m_blockAllocator->ReturnMemory(blocks, blocksSize);
        return -1;
    }

    {
        int n = 0;
        for (Element* pElement = m_free; pElement; pElement = pElement->m_next)
        {
            elements[n++] = pElement;
        }
        for (char* p = m_fMinimumV; p < m_pSecondString; p += m_iFirstIndex)
        {
            elements[n++] = (Element*)p;
        }
    }

    m_fMinimumV = m_pSecondString = 0;

    if (numElements > 1)
    {
        hkFreeList_quickSortRecursive((void**)elements, 0, numElements - 1, hkFreeList_comparePointers);
    }

    Element** cur = elements;
    Element** end = elements + numElements;
    int numFreed = 0;

    for (unsigned int i = 0; i < (unsigned int)numBlocks && cur < end; i++)
    {
        Block* block = blocks[i];
        int blockElements = block->m_iCapacity;
        unsigned int elementSize = m_iFirstIndex;
        char* p = block->m_kRayStart;
        char* blockEnd = p + blockElements * elementSize;

        while (cur < end)
        {
            if (p != (char*)*cur || p >= blockEnd)
            {
                break;
            }
            cur++;
            p += elementSize;
        }

        if (p == blockEnd)
        {
            numFreed++;
            block->m_next = m_pFreeBlocks;
            m_pFreeBlocks = block;
            blocks[i] = 0;
            for (Element** e = cur - blockElements; e < cur; e++)
            {
                *e = 0;
            }
        }
        else
        {
            while (cur < end && (char*)*cur < blockEnd)
            {
                cur++;
            }
        }
    }

    {
        Block** prev = &m_kBlocks;
        for (unsigned int i = 0; i < (unsigned int)numBlocks; i++)
        {
            Block* block = blocks[i];
            if (block)
            {
                *prev = block;
                prev = &block->m_next;
            }
        }
        *prev = 0;
    }

    {
        Element** prev = &m_free;
        for (Element** e = elements; e < end; e++)
        {
            Element* pElement = *e;
            if (pElement)
            {
                *prev = pElement;
                prev = &pElement->m_next;
            }
        }
        *prev = 0;
    }

    m_blockAllocator->ReturnMemory(elements, elementsSize);
    m_blockAllocator->ReturnMemory(blocks, blocksSize);
    m_iFreeCount = 0;
    return numFreed;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef void(__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

struct hkFreeListBlockServer
{
    virtual ~hkFreeListBlockServer();
    virtual void* unk04();
    virtual void free(void* p);
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkFreeListElement
{
    hkFreeListElement* m_next;
};

struct hkFreeListBlock
{
    hkFreeListBlock* m_next;
    unsigned int m_unk04;
    char* m_kRayStart;
    unsigned int m_iCapacity;
};

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl FUN_00dd7d00(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

inline void quickSortPointers(void** arr, int numElem)
{
    if (numElem > 1)
    {
        FUN_00dd7d00(arr, 0, numElem - 1, CompareLessThan);
    }
}

struct hkFreeListWalker
{
    hkFreeListElement* m_free;
    unsigned int m_iFirstIndex;
    unsigned int m_unk08;
    hkFreeListBlock* m_activeBlocks;
    hkFreeListBlock* m_pFreeBlocks;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    char* m_fMinimumV;
    char* m_pSecondString;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    hkFreeListBlockServer* m_blockServer;

    void WalkFreeBlocks(hkFreeListBlock* blocks, hkMemoryWalkCallback callback, int pool, void* param);
    void FUN_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
};

// Walks free blocks, then reports slots in active blocks through the callback with their allocation status.
// @fnv 0x00dd78f0
void hkFreeListWalker::FUN_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param)
{
    WalkFreeBlocks(m_pFreeBlocks, callback, pool, param);

    if (m_activeBlocks == 0 && m_free == 0)
    {
        return;
    }

    int numBlocks = 0;
    for (hkFreeListBlock* block = m_activeBlocks; block; block = block->m_next)
    {
        numBlocks++;
    }

    hkFreeListBlock** blocks =
        (hkFreeListBlock**)m_blockServer->AllocateBufferWithSize(numBlocks * sizeof(hkFreeListBlock*));
    if (!blocks)
    {
        return;
    }
    {
        int i = 0;
        for (hkFreeListBlock* block = m_activeBlocks; block; block = block->m_next)
        {
            blocks[i++] = block;
        }
    }
    quickSortPointers((void**)blocks, numBlocks);

    int numFree = (m_pSecondString - m_fMinimumV) / m_iFirstIndex;
    for (hkFreeListElement* elem = m_free; elem; elem = elem->m_next)
    {
        numFree++;
    }

    char** freeElems = (char**)m_blockServer->AllocateBufferWithSize(numFree * sizeof(char*));
    if (!freeElems)
    {
        m_blockServer->free(blocks);
        return;
    }
    {
        int i = 0;
        for (hkFreeListElement* elem = m_free; elem; elem = elem->m_next)
        {
            freeElems[i++] = (char*)elem;
        }
        for (char* p = m_fMinimumV; p < m_pSecondString; p += m_iFirstIndex)
        {
            freeElems[i++] = p;
        }
    }
    quickSortPointers((void**)freeElems, numFree);

    char** curFree = freeElems;
    char** endFree = freeElems + numFree;

    unsigned int i = 0;
    for (; i < (unsigned int)numBlocks; i++)
    {
        if (curFree >= endFree)
        {
            break;
        }
        hkFreeListBlock* block = blocks[i];
        unsigned int numElements = block->m_iCapacity;
        char* start = block->m_kRayStart;
        char* end = start + m_iFirstIndex * numElements;
        for (char* p = start; p < end; p += m_iFirstIndex)
        {
            if (p == *curFree)
            {
                callback(p, m_iFirstIndex, false, pool, param);
                curFree++;
            }
            else
            {
                callback(p, m_iFirstIndex, true, pool, param);
            }
        }
    }
    for (; i < (unsigned int)numBlocks; i++)
    {
        hkFreeListBlock* block = blocks[i];
        char* p = block->m_kRayStart;
        for (unsigned int j = 0; j < block->m_iCapacity; j++)
        {
            callback(p, m_iFirstIndex, true, pool, param);
            p += m_iFirstIndex;
        }
    }

    m_blockServer->ReturnMemory(freeElems, numFree * sizeof(char*));
    m_blockServer->ReturnMemory(blocks, numBlocks * sizeof(hkFreeListBlock*));
}

namespace fnv_00dd74b0 {
static __declspec(noinline) void* FUN_00dd73d0(void* p, unsigned int n)
{
    void** pp = &p;
    unsigned int* pn = &n;
    return (char*)*pp + *pn;
}

struct S00dd74b0_cls
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

    void FUN_00dd74b0(int a2, int a3, int a4, int a5);
};

// Initializes fields, stores a4 and a5, computes a rounded-up size from a2 and a3, and sets unk1C to a pointer offset by a3.
// @fnv 0x00dd74b0
void S00dd74b0_cls::FUN_00dd74b0(int a2, int aiAlignment, int a4, int a5)
{
    unk00 = 0;
    unk0C = 0;
    unk10 = 0;
    unk14 = a4;
    unk20 = 0;
    unk24 = 0;
    unk28 = 0;
    unk2C = 0;
    unk18 = aiAlignment;
    unk30 = a5;
    unk08 = 0;

    unsigned int size;
    if ((unsigned int)a2 < (unsigned int)aiAlignment)
        size = (unsigned int)aiAlignment;
    else
        size = ((unsigned int)a2 + (unsigned int)aiAlignment - 1u) & ~((unsigned int)aiAlignment - 1u);

    unk04 = (int)size;
    unk1C = (int)FUN_00dd73d0((void*)0xFF0u, (unsigned int)aiAlignment);
}
}  // namespace fnv_00dd74b0

__declspec(noinline) int SumFreeListSizes(hkFreeListBlockDD75* node)
{
    int sum = 0;
    for (hkFreeListBlockDD75* n = node; n != 0; n = n->m_pkNext)
        sum += n->m_uiNumElements;
    return sum;
}

struct FreeListElementCounter : hkFreeListDD75
{
    int FUN_00dd72d0();
};

// @fnv 0x00dd72d0
int FreeListElementCounter::FUN_00dd72d0()
{
    int first = SumFreeListSizes(this->m_pkFreeBlocks);
    return first + SumFreeListSizes(this->m_pkActiveBlocks);
}
