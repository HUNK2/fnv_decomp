
// src/staging/blk_00d80000_od_o2_nood_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d80000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
struct BaseD85
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BaseD85& Assign(const BaseD85& o);
};
struct ObjD85 : BaseD85
{
    short unk90;
    char unk92;
    short unk94;
    short unk96;
    __m128 unka0;
    __m128 unkb0;
    __m128 unkc0;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    ObjD85& FUN_00d85ba0(const ObjD85& o);
};
struct __declspec(align(16)) StandinClass
{
    unsigned short unk00;
    __m128 value10;
    __m128 value20;
    __m128 value30;
    __m128 value40;
    __m128 value50;
    __m128 value60;
    __m128 value70;
    __m128 value80;
    StandinClass& FUN_00d85300(const StandinClass* source);
};

struct __declspec(align(16)) S00d9db60_ProjectedEntry
{
    unsigned short m_kMinimumCorner[3];
    unsigned short m_usFirstVectorPadding;
    unsigned short m_kMaximumCorner[3];
    unsigned short m_usSecondVectorPadding;
    __forceinline void operator=(const S00d9db60_ProjectedEntry& other)
    {
        *(__m128*)this = *(const __m128*)&other;
    }
    __forceinline void reset()
    {
        m_kMinimumCorner[0] = m_kMinimumCorner[1] = m_kMinimumCorner[2] = 0;
        m_kMaximumCorner[0] = m_kMaximumCorner[1] = m_kMaximumCorner[2] = 0xffff;
    }
};

struct S00d9db60_Allocator
{
    virtual ~S00d9db60_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

struct S00d9db60_Router
{
    void* m_stackCur;
    void* m_stackEnd;
    void* m_stackBase;
    S00d9db60_Allocator* m_pTemp;
    S00d9db60_Allocator* m_pStreamAllocator;
    __forceinline S00d9db60_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S00d9db60_Router* __cdecl FUN_00c85750();

struct S00d9db60_HeapAllocator
{
    __forceinline S00d9db60_Allocator& get(const void*)
    {
        return FUN_00c85750()->heap();
    }
};

template <typename T> struct S00d9db60_Array
{
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S00d9db60_Array(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {
        S00d9db60_Allocator& a = S00d9db60_HeapAllocator().get(this);
        T* p = n ? a._bufAlloc<T>(n) : 0;
        int cap = n ? n : DONT_DEALLOCATE_FLAG;
        setOwnedData(p, n, cap);
    }
    __forceinline void setOwnedData(T* ptr, int size, int capacity)
    {
        m_data = ptr;
        m_iElementCount = size;
        m_iCapacityState = capacity;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease()
    {
        S00d9db60_Allocator& alloc = S00d9db60_HeapAllocator().get(this);
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct S00d9db60_Node
{
    unsigned int m_word0, m_word1;
};

struct S00d9db60_KdTree
{
    S00d9db60_Array<S00d9db60_Node> m_kNodeCollection;
    int m_iNumNodes;
    int m_iNumPrimitives;
    int m_iNumProjectedEntries;
    int m_iNumReservedEmptyNodes;
    S00d9db60_Array<S00d9db60_ProjectedEntry> m_kProjectedEntries;
    __forceinline S00d9db60_Array<S00d9db60_Node>& getNodes()
    {
        return m_kNodeCollection;
    }
    __forceinline S00d9db60_Node* getRoot()
    {
        return m_kNodeCollection.begin();
    }
    __forceinline int getNumReservedEmptyNodes() const
    {
        return m_iNumReservedEmptyNodes;
    }
    __forceinline S00d9db60_ProjectedEntry* getProjectedEntries()
    {
        return m_kProjectedEntries.begin();
    }
};

struct S00d9db60_Mediator
{
    virtual ~S00d9db60_Mediator();
    virtual void reserved1();
    virtual void reserved2();
    virtual int GetNumEntries() const = 0;
};

struct S00d9db60_WorkingSet
{
    S00d9db60_ProjectedEntry* m_pProjectedEntryBegin;
    S00d9db60_ProjectedEntry* m_pProjectedEntryEnd;
};

struct S00d9db60_TreeStream
{
    S00d9db60_Node* m_pTreeNode;
};

extern const __m128 DAT_012684d0;

struct S00d9db60_Comparison
{
    __m128 m_uiMask;
    __forceinline void setXYZ()
    {
        m_uiMask = DAT_012684d0;
    }
};

struct S00d9db60_SparseWriter
{
    enum
    {
        BUFFER_SIZE = 16
    };
    __m128 m_kVectorBuffer[BUFFER_SIZE];
    int m_uiEdgeIndex;
    void FUN_00df3110();  // constructor
    void FUN_00df3160();  // flush, from the inline destructor
};

struct S00d9db60_BuildRecursiveInput
{
    S00d9db60_WorkingSet* m_pWorkingSet;
    int m_iFirstInputValue;
    int m_iSecondInputValue;
    int m_iThirdValue;
    int m_iFourthInputValue;
    S00d9db60_ProjectedEntry m_kBounds;
    S00d9db60_SparseWriter* m_pStreamWriter;
    S00d9db60_Comparison m_kComparison;
    __forceinline S00d9db60_BuildRecursiveInput() : m_iSecondInputValue(-1)
    {
        m_kComparison.setXYZ();
    }
};

void __cdecl FillAabbArray(S00d9db60_Mediator*, int, int, S00d9db60_ProjectedEntry*);
void __cdecl MixChannels(S00d9db60_WorkingSet&, S00d9db60_Node*, S00d9db60_ProjectedEntry*, int, int, int, int&);
void __cdecl FUN_00df37b0(const S00d9db60_WorkingSet&, S00d9db60_Node*, int, int, S00d9db60_BuildRecursiveInput*, int*,
                          S00d9db60_ProjectedEntry&);
int __cdecl FUN_00df56a0(const S00d9db60_BuildRecursiveInput&, S00d9db60_TreeStream*, S00d9db60_ProjectedEntry*, int*,
                         int*);
void __cdecl FUN_00d9d950(S00d9db60_KdTree*, int, int*, int*);

// @fnv 0x00d9db60
void __cdecl FUN_00d9db60(S00d9db60_Mediator& mediator, S00d9db60_KdTree* tree)
{
    S00d9db60_Node* root = tree->getRoot();

    S00d9db60_Array<S00d9db60_ProjectedEntry> entriesA(mediator.GetNumEntries());
    S00d9db60_Array<S00d9db60_ProjectedEntry> entriesB(mediator.GetNumEntries());

    S00d9db60_WorkingSet buffers;
    buffers.m_pProjectedEntryBegin = entriesA.begin();
    buffers.m_pProjectedEntryEnd = entriesB.begin();

    FillAabbArray(&mediator, 0, mediator.GetNumEntries(), entriesA.begin());

    S00d9db60_ProjectedEntry rootBounds;
    rootBounds.reset();

    if (mediator.GetNumEntries() < 8)
    {
        int numReservedEmptyNodes = tree->getNumReservedEmptyNodes();
        MixChannels(buffers, tree->m_kNodeCollection.begin(), tree->getProjectedEntries(),
                    tree->m_kNodeCollection.GetLogicalSize(), mediator.GetNumEntries(), numReservedEmptyNodes,
                    tree->m_iNumNodes);
        entriesB.ClearAndRelease();
        entriesA.ClearAndRelease();
        return;
    }

    S00d9db60_BuildRecursiveInput subTreeInputs[4];
    S00d9db60_WorkingSet subTreeBuffers[4];
    subTreeInputs[0].m_pWorkingSet = &subTreeBuffers[0];
    subTreeInputs[1].m_pWorkingSet = &subTreeBuffers[1];
    subTreeInputs[2].m_pWorkingSet = &subTreeBuffers[2];
    subTreeInputs[3].m_pWorkingSet = &subTreeBuffers[3];

    int numPrimitivesPerSubTree[4];
    FUN_00df37b0(buffers, root, tree->m_kNodeCollection.GetLogicalSize(), mediator.GetNumEntries(), subTreeInputs,
                 numPrimitivesPerSubTree, rootBounds);

    int numReservedEmptyNodes = tree->getNumReservedEmptyNodes();
    int emptyNodesPerSubTree[4];
    emptyNodesPerSubTree[0] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[1] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[2] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[3] =
        numReservedEmptyNodes - emptyNodesPerSubTree[0] - emptyNodesPerSubTree[1] - emptyNodesPerSubTree[2];

    int currentNodeIdx = 8;
    int subTreeDepths[4];
    for (int i = 0; i < 4; i++)
    {
        S00d9db60_WorkingSet ws;
        ws.m_pProjectedEntryBegin = subTreeInputs[i].m_pWorkingSet->m_pProjectedEntryBegin;
        ws.m_pProjectedEntryEnd = subTreeInputs[i].m_pWorkingSet->m_pProjectedEntryEnd;

        S00d9db60_BuildRecursiveInput input;
        input.m_pWorkingSet = &ws;
        input.m_iFirstInputValue = subTreeInputs[i].m_iFirstInputValue;
        input.m_iThirdValue = subTreeInputs[i].m_iThirdValue;
        input.m_iFourthInputValue = subTreeInputs[i].m_iFourthInputValue;
        input.m_kBounds = subTreeInputs[i].m_kBounds;
        input.m_iSecondInputValue = tree->m_kNodeCollection.GetLogicalSize();

        S00d9db60_SparseWriter writer;
        writer.FUN_00df3110();
        input.m_pStreamWriter = &writer;

        int depth = 1;
        S00d9db60_TreeStream stream;
        stream.m_pTreeNode = root + currentNodeIdx;
        numPrimitivesPerSubTree[i] += emptyNodesPerSubTree[i] + (emptyNodesPerSubTree[i] & 1);
        currentNodeIdx += numPrimitivesPerSubTree[i];

        subTreeDepths[i] = FUN_00df56a0(input, &stream, tree->getProjectedEntries(), &depth, &emptyNodesPerSubTree[i]);
        subTreeDepths[i] += 2;
        writer.FUN_00df3160();
    }

    FUN_00d9d950(tree, mediator.GetNumEntries(), subTreeDepths, numPrimitivesPerSubTree);
    entriesB.ClearAndRelease();
    entriesA.ClearAndRelease();
}
