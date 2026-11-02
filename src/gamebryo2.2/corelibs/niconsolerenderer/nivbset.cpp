
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiVBBlock
{
    void* m_pBuffer;
    char _04[8];
    unsigned int m_uiSize;
    char _10[12];
    unsigned long m_uiValue1C;
    unsigned int m_uiValue20;
    unsigned int m_uiValue24;
    unsigned int m_uiValue28;
    void FreeVBBlock(unsigned int);
};

void __stdcall InsertSortedNode(NiVBBlock*);

struct NiVBSetBlockArray
{
    unsigned int _00;
    NiVBBlock** m_pData;
    void FUN_00a93c50(unsigned int);
};

struct NiVBSet
{
    unsigned int m_uiPosition;
    char _04[8];
    unsigned int m_uiIndexCapacity;
    char _10[12];
    NiVBSetBlockArray m_kBlockArray;
    void RemoveNode(NiVBBlock*);
    void FUN_00e94330(NiVBBlock*);
    void FUN_00e94490(unsigned int uiArrayIndex, unsigned int uiChipIndex);
};

// @fnv 0x00e94490
void NiVBSet::FUN_00e94490(unsigned int uiArrayIndex, unsigned int uiChipIndex)
{
    unsigned int uiPreFreeSpace;
    NiVBBlock* pkVBBlock;
    pkVBBlock = m_kBlockArray.m_pData[uiArrayIndex];
    if (!pkVBBlock)
        return;
    uiPreFreeSpace = pkVBBlock->m_uiValue24;
    pkVBBlock->FreeVBBlock(uiChipIndex);
    if (uiPreFreeSpace == pkVBBlock->m_uiValue24)
        return;
    RemoveNode(pkVBBlock);
    if (pkVBBlock->m_uiValue28 == pkVBBlock->m_uiSize)
    {
        m_kBlockArray.FUN_00a93c50(uiArrayIndex);
        FUN_00e94330(pkVBBlock);
    }
    else
    {
        InsertSortedNode(pkVBBlock);
    }
}

// InsertSortedNode: insert a block into a key-sorted doubly linked list owned by this set.
// Head pointer lives at +0x2c; each node has key at +0x24, next at +0x3c, prev at +0x40.

struct FUN_00e94220_node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int m_key;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    FUN_00e94220_node* m_next;
    FUN_00e94220_node* m_pSecondNode;
};

struct FUN_00e94220_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_00e94220_node* m_pFirstNode;

    void InsertSortedNode(FUN_00e94220_node* node);
};

// Inserts node into the doubly linked list ordered by m_key, updating head, next and back pointers.
// @fnv 0x00e94220
void FUN_00e94220_cls::InsertSortedNode(FUN_00e94220_node* node)
{
    if (m_pFirstNode != 0)
    {
        FUN_00e94220_node* prev = 0;
        FUN_00e94220_node* cur = m_pFirstNode;
        unsigned int key = node->m_key;
        do
        {
            if (cur->m_key > key)
            {
                goto found;
            }
            prev = cur;
            cur = cur->m_next;
        } while (cur != 0);
        prev->m_next = node;
        node->m_pSecondNode = prev;
        node->m_next = 0;
        return;
    found:
        if (prev != 0)
        {
            prev->m_next = node;
        }
        cur->m_pSecondNode = node;
        node->m_next = cur;
        node->m_pSecondNode = prev;
        if (cur != m_pFirstNode)
        {
            return;
        }
        m_pFirstNode = node;
    }
    else
    {
        m_pFirstNode = node;
        node->m_next = 0;
        m_pFirstNode->m_pSecondNode = 0;
    }
}

extern unsigned int DAT_011c0cdc;
extern int DAT_010f0f8c;
void* __cdecl FUN_00aa13e0(unsigned int);
struct LinkedVBBlock
{
    NiVBBlock block;
    void* type;
    unsigned int index;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short used;
    LinkedVBBlock* previous;
    LinkedVBBlock* next;
    void FUN_00e942d0();
    __forceinline LinkedVBBlock* Initialize()
    {
        a = 0;
        used = 1;
        b = 0;
        c = 0;
        index = 0;
        type = &DAT_010f0f8c;
        FUN_00e942d0();
        return this;
    }
};
extern LinkedVBBlock* DAT_0126fa30;
// Allocates DAT_011c0cdc LinkedVBBlock objects, initializes each, and links them into a doubly linked list headed by DAT_0126fa30.
// @fnv 0x00e944f0
void __cdecl AllocateVBBlocks()
{
    for (unsigned int i = 0; i < DAT_011c0cdc; ++i)
    {
        LinkedVBBlock* pRawBlock = static_cast<LinkedVBBlock*>(FUN_00aa13e0(sizeof(LinkedVBBlock)));
        LinkedVBBlock* p = pRawBlock ? pRawBlock->Initialize() : 0;
        LinkedVBBlock* previous = p->previous;
        LinkedVBBlock* next = p->next;
        if (previous)
            previous->next = next;
        if (next)
            next->previous = previous;
        if (DAT_0126fa30)
            DAT_0126fa30->next = p;
        p->previous = DAT_0126fa30;
        p->next = 0;
        DAT_0126fa30 = p;
    }
}

struct VBBlock
{
    char _00[0x24];
    unsigned int m_uiValue24;
    void* FUN_00e98660(unsigned int uiSize);
};

struct VBSet
{
    char _00[0x30];
    unsigned int m_uiThreshold;
    VBBlock* RemoveFirstNodeAtLeast(unsigned int uiSize);
    VBBlock* FUN_00e94580(unsigned int uiSize);
    void InsertSortedNode(VBBlock* pkBlock);
    void* FUN_00e94650(unsigned int uiSize, bool bForceNew);
};

// @fnv 0x00e94650
void* VBSet::FUN_00e94650(unsigned int uiSize, bool bForceNew)
{
    void* pvChip = 0;
    VBBlock* pkBlock = 0;
    if (!bForceNew)
        pkBlock = RemoveFirstNodeAtLeast(uiSize);
    if (!pkBlock)
        pkBlock = FUN_00e94580(uiSize);
    if (pkBlock)
    {
        pvChip = pkBlock->FUN_00e98660(uiSize);
        if (pkBlock->m_uiValue24 > m_uiThreshold)
            InsertSortedNode(pkBlock);
    }
    return pvChip;
}

struct VBLayout;
struct VBArray
{
    unsigned int m_uiCount;
    VBLayout** m_pData;
    void FUN_00ba3aa0(unsigned int, VBLayout**);
};
struct VBLayout
{
    void* m_pBuffer;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiSize;
    unsigned int unk10;
    unsigned int m_uiValueBeforeCount;
    VBLayout* m_pkNext;
    VBLayout* m_pkPrev;
    unsigned int m_uiValue20;
    unsigned int m_uiValue24;
    unsigned int m_uiValue28;
    VBArray m_kBlockArray;
};
extern VBLayout* g_pkFreeList;
// @fnv 0x00e98500
unsigned int __fastcall FreeVBBlock(NiVBBlock* object, void*, unsigned int index)
{
    VBLayout* pLayout = reinterpret_cast<VBLayout*>(object);
    unsigned int result = 0;
    VBLayout* block = pLayout->m_kBlockArray.m_pData[index];
    if (block)
    {
        result = block->m_uiValueBeforeCount;
        if (pLayout->m_uiValue20 - result == block->m_uiSize)
        {
            pLayout->m_uiValue20 = 0;
            if (index > 0)
            {
                VBLayout** ppCursor = pLayout->m_kBlockArray.m_pData;
                unsigned int remain = index;
                do
                {
                    VBLayout* current = *ppCursor;
                    if (current)
                    {
                        unsigned int end = current->m_uiValueBeforeCount + current->m_uiSize;
                        if (end > pLayout->m_uiValue20)
                            pLayout->m_uiValue20 = end;
                    }
                    ++ppCursor;
                } while (--remain);
            }
        }
        pLayout->m_uiValue24 = pLayout->m_uiSize - pLayout->m_uiValue20;
        pLayout->m_uiValue28 += result;
        VBLayout* removed = 0;
        pLayout->m_kBlockArray.FUN_00ba3aa0(index, &removed);
        block->m_pkPrev = 0;
        block->m_pkNext = g_pkFreeList;
        if (g_pkFreeList)
            g_pkFreeList->m_pkPrev = block;
        g_pkFreeList = block;
    }
    return result;
}

struct HashNode
{
    HashNode* next;
    unsigned int key;
    unsigned int value;
};
struct HashTableBase
{
    virtual void Reserved0() = 0;
    virtual unsigned int BucketIndex(unsigned int key) = 0;
    virtual bool EqualKey(unsigned int key, unsigned int existingKey) = 0;
    virtual void Initialize(HashNode* entry, unsigned int key, unsigned int value) = 0;
    virtual void Reserved4() = 0;
    virtual HashNode* AllocateNode() = 0;

    unsigned int tableSize;
    HashNode** buckets;
    unsigned int elementCount;
    void InsertOrUpdate(unsigned int key, unsigned int value);
};
// Looks up key in the bucket chain, updates the value if found, otherwise allocates, initializes and prepends a new node and increments elementCount.
// @fnv 0x00b57ea0
void HashTableBase::InsertOrUpdate(unsigned int key, unsigned int value)
{
    unsigned int bucketIndex = BucketIndex(key);
    HashNode* node = buckets[bucketIndex];
    while (node)
    {
        if (EqualKey(key, node->key))
        {
            node->value = value;
            return;
        }
        node = node->next;
    }
    HashNode* newNode = AllocateNode();
    Initialize(newNode, key, value);
    newNode->next = buckets[bucketIndex];
    buckets[bucketIndex] = newNode;
    ++elementCount;
}

struct VBBlk
{
    void* m_pSet;
    unsigned int m_uiPosition;
    unsigned int m_uiVB;
    unsigned int m_uiSize;
    unsigned int m_u10;
    unsigned int m_u14;
    unsigned int m_u18;
    unsigned int m_u1C;
    unsigned int m_u20;
    unsigned int m_u24;
    unsigned int m_u28;
    unsigned int m_u2C;
    unsigned int m_u30;
    unsigned int m_u34;
    unsigned int m_u38;
    VBBlk* m_pNext;
    VBBlk* m_pListObject;
};

struct VBArr
{
    unsigned int FUN_00a64330(VBBlk** ppBlock);
};

struct VBDev;
typedef int(__stdcall* VBDev_fn)(VBDev* pSelf, unsigned int uiSize, unsigned int uiA, unsigned int uiB,
                                 unsigned int uiC, unsigned int* puiOut, unsigned int uiZero);
struct VBDev
{
    VBDev_fn* m_pVtbl;
};

struct VBSetX
{
    unsigned int m_u00;
    unsigned int m_u04;
    unsigned int m_u08;
    unsigned int m_u0C;
    VBDev* m_pDev;
    unsigned int m_u14;
    unsigned int m_u18;
    VBArr m_kArr;
    VBBlk* FUN_00e94580(unsigned int uiSize);
};

__forceinline VBBlk* PopBlock()
{
    if (!DAT_0126fa30)
        AllocateVBBlocks();
    VBBlk* block = (VBBlk*)DAT_0126fa30;
    DAT_0126fa30 = (LinkedVBBlock*)((VBBlk*)DAT_0126fa30)->m_pNext;
    if (DAT_0126fa30)
        ((VBBlk*)DAT_0126fa30)->m_pListObject = 0;
    block->m_pNext = 0;
    block->m_pListObject = 0;
    return block;
}

// Allocates a VBBlk of at least uiSize bytes via the device, fills its fields, and inserts it into the VBArr.
// @fnv 0x00e94580
VBBlk* VBSetX::FUN_00e94580(unsigned int uiSize)
{
    unsigned int uiAllocSize = uiSize;
    if ((m_u08 & 0x10000000) == 0)
    {
        if (uiAllocSize <= m_u0C)
            uiAllocSize = m_u0C;
    }
    uiSize = 0;
    if (m_pDev->m_pVtbl[26](m_pDev, uiAllocSize, m_u14, m_u04, m_u18, &uiSize, 0) < 0)
        return 0;

    VBBlk* p = PopBlock();
    p->m_pSet = this;
    p->m_uiVB = uiSize;
    p->m_uiSize = uiAllocSize;
    p->m_u24 = uiAllocSize;
    p->m_u28 = uiAllocSize;
    p->m_u10 = m_u04;
    p->m_u14 = m_u08;
    p->m_u1C = m_u18;
    VBBlk* pBlock = p;
    VBBlk* __restrict usageBlock = p;
    usageBlock->m_u18 = m_u14;
    p->m_uiPosition = m_kArr.FUN_00a64330(&pBlock);
    return p;
}

extern "C" void __cdecl FUN_00aa10f0(void*);
struct VBReleaseInterface
{
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

template <class T> class NiTMallocInterface
{
};
template <class T, class Alloc> class NiTArray
{
  public:
    T* data;
    unsigned short capacity, size, used, grow;
    virtual ~NiTArray()
    {
        FUN_00aa10f0(data);
    }
    T RemoveAt(unsigned int index)
    {
        if (index >= size)
            return T(0);
        T item = data[index];
        data[index] = T(0);
        if (item)
            --used;
        if (index == (unsigned short)(size - 1))
            --size;
        return item;
    }
};
typedef NiTArray<NiVBBlock*, NiTMallocInterface<NiVBBlock*> > CleanupBlockArray;

struct VBSetCleanup
{
    unsigned int index;
    unsigned int format;
    unsigned int flags;
    unsigned int blockSize;
    VBReleaseInterface* buffer;
    unsigned int usage;
    unsigned int pool;
    CleanupBlockArray blocks;
    void FUN_00e943c0();
};

// Releases each block's VB interface, links non-null blocks into a list, releases the buffer, and destroys the array.
// @fnv 0x00e943c0
void VBSetCleanup::FUN_00e943c0()
{
    for (unsigned int i = 0; i < blocks.size; ++i)
    {
        LinkedVBBlock* block = reinterpret_cast<LinkedVBBlock*>(blocks.RemoveAt(i));
        if (block)
        {
            VBBlk* view = reinterpret_cast<VBBlk*>(block);
            if (view->m_uiVB)
            {
                reinterpret_cast<VBReleaseInterface*>(view->m_uiVB)->Release();
                view->m_uiVB = 0;
            }
            block->FUN_00e942d0();
            LinkedVBBlock* previous = block->previous;
            LinkedVBBlock* next = block->next;
            if (previous)
                previous->next = next;
            if (next)
                next->previous = previous;
            LinkedVBBlock* head = DAT_0126fa30;
            if (head)
            {
                head->next = block;
                head = DAT_0126fa30;
            }
            block->previous = head;
            block->next = 0;
            DAT_0126fa30 = block;
        }
    }
    if (buffer)
        buffer->Release();
    buffer = 0;
    blocks.CleanupBlockArray::~CleanupBlockArray();
}
